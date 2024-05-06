#define DT_DRV_COMPAT st_mfx

#include "mfx.h"
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/drivers/mfx.h>

LOG_MODULE_REGISTER(mfx_v3, CONFIG_MFX_LOG_LEVEL);

struct mfx_config {
	struct i2c_dt_spec i2c;
};

static int mfx_init(const struct device *dev)
{
	const struct mfx_config *config = dev->config;
	if (!i2c_is_ready_dt(&config->i2c)) {
		LOG_ERR("Failed to get I2C device");
		return -ENODEV;
	}
	int ret;
	ret = i2c_reg_write_byte_dt(&config->i2c, MFXSTM32L496G_DISCO_REG_ADR_SYS_CTRL,
				    1); // abilitate all gpios
	if (ret < 0) {
		LOG_ERR("Could not abilitate GPIOS (%d)", ret);
		return ret;
	}

	ret = i2c_reg_write_byte_dt(&config->i2c, MFXSTM32L496G_DISCO_REG_ADR_GPIO_DIR1,
				    0x10); // define LED as output GPIO

	if (ret < 0) {
		LOG_ERR("Could not turn on led (%d)", ret);
		return ret;
	}

	ret = i2c_reg_write_byte_dt(&config->i2c, MFXSTM32L496G_DISCO_REG_ADR_GPO_SET1, 0x10);
	if (ret < 0) {
		LOG_ERR("Could not turn off led (%d)", ret); // turn off led at start by default
		return ret;
	}

	return 0;
}

static int mfx_led_turn_on(const struct device *dev)
{
	const struct mfx_config *config = dev->config;
	int ret;
	ret = i2c_reg_write_byte_dt(&config->i2c, MFXSTM32L496G_DISCO_REG_ADR_GPO_CLR1, 0x10);

	if (ret < 0) {
		LOG_ERR("Could not turn on led (%d)", ret);
		return ret;
	}

	return 0;
}

static int mfx_led_turn_off(const struct device *dev)
{
	const struct mfx_config *config = dev->config;
	int ret;
	ret = i2c_reg_write_byte_dt(&config->i2c, MFXSTM32L496G_DISCO_REG_ADR_GPO_SET1, 0x10);

	if (ret < 0) {
		LOG_ERR("Could not turn off led (%d)", ret);
		return ret;
	}

	return 0;
}

static int mfx_card_is_detected(const struct device *dev)
{
	int ret;
	const struct mfx_config *config = dev->config;

	ret = i2c_reg_write_byte_dt(&config->i2c, MFXSTM32L496G_DISCO_REG_ADR_GPIO_TYPE2,
				    0x01); // set GPIO 8 pull resistor
	if (ret < 0) {
		LOG_ERR("Could not configure GPIO 8 PULL RESISTOR (%d)", ret);
		return ret;
	}

	ret = i2c_reg_write_byte_dt(&config->i2c, MFXSTM32L496G_DISCO_REG_ADR_GPIO_PUPD2,
				    0x01); // set GPIO 8 pull up
	if (ret < 0) {
		LOG_ERR("Could not configure GPIO 8 PULL UP (%d)", ret);
		return ret;
	}

	uint8_t buf;
	ret = i2c_reg_read_byte_dt(&config->i2c, MFXSTM32L496G_DISCO_REG_ADR_GPIO_STATE2,
				   &buf); // read 0 if the SD is present, 1 otherwise
	if (ret < 0) {
		LOG_ERR("Could not detect SD CARD (%d)", ret);
		return ret;
	}

	uint8_t flag_sd_card = buf & 0x1;
	return flag_sd_card;
}

static const struct mfx_api mfx_driver_api = {
	.card_is_detected = mfx_card_is_detected,
	.turn_on_led = mfx_led_turn_on,
	.turn_off_led = mfx_led_turn_off,
};

#define MFX_DEVICE(i)                                                                              \
	static struct mfx_config mfx_config##i = {                                                 \
		.i2c = I2C_DT_SPEC_INST_GET(i),                                                    \
	};                                                                                         \
                                                                                                   \
	DEVICE_DT_INST_DEFINE(i, mfx_init, NULL, NULL, &mfx_config##i, POST_KERNEL,                \
			      CONFIG_MFX_INIT_PRIORITY, &mfx_driver_api);

DT_INST_FOREACH_STATUS_OKAY(MFX_DEVICE)
