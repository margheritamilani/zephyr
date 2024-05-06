#include <zephyr/types.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>

typedef int (*mfx_card_is_detected_t)(const struct device *dev);
typedef int (*mfx_turn_on_led_t)(const struct device *dev);
typedef int (*mfx_turn_off_led_t)(const struct device *dev);

struct mfx_api {
  mfx_card_is_detected_t card_is_detected;
  mfx_turn_on_led_t turn_on_led;
  mfx_turn_off_led_t turn_off_led;
};

static inline int mfx_card_detect(const struct device *dev) {
  const struct mfx_api *api = (const struct mfx_api *)dev->api;
  return api->card_is_detected(dev);
}

static inline int mfx_turn_on_led(const struct device *dev) {
  const struct mfx_api *api = (const struct mfx_api *)dev->api;
  return api->turn_on_led(dev);
}

static inline int mfx_turn_off_led(const struct device *dev) {
  const struct mfx_api *api = (const struct mfx_api *)dev->api;
  return api->turn_off_led(dev);
}