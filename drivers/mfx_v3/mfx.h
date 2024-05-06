/**
 * @brief Register address: chip IDs (R)
 */
#define MFXSTM32L496G_DISCO_I2C_ADDR 0x42U

/**
 * @brief Register address: System Control Register (R/W)
 */
#define MFXSTM32L496G_DISCO_REG_ADR_SYS_CTRL 0x40U

/**
 * @brief Reg addr: GPIO DIRECTION (R/W): GPIO pins direction: (0) input, (1) output.
 */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_DIR1   0x60U /* gpio [0:7] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_DIR2   0x61U /* gpio [8:15] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_DIR3   0x62U /* agpio [0:7] */
/**
  * @brief Reg addr: GPIO TYPE (R/W): If GPIO in output: (0) output push pull, (1) output open
  drain. If GPIO in input: (0) input without pull resistor, (1) input with pull resistor.
  */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_TYPE1  0x64U /* gpio [0:7] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_TYPE2  0x65U /* gpio [8:15] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_TYPE3  0x66U /* agpio [0:7] */
/**
 * @brief Reg addr: GPIO PULL_UP_PULL_DOWN (R/W)
 */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_PUPD1  0x68U /* gpio [0:7] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_PUPD2  0x69U /* gpio [8:15] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_PUPD3  0x6AU /* agpio [0:7] */
/**
  * @brief Reg addr: GPIO SET (W): When GPIO is in output mode, write (1) puts
	   the corresponding GPO in High level.
 */
#define MFXSTM32L496G_DISCO_REG_ADR_GPO_SET1    0x6CU /* gpio [0:7] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPO_SET2    0x6DU /* gpio [8:15] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPO_SET3    0x6EU /* agpio [0:7] */
/**
  * @brief Reg addr: GPIO CLEAR (W): When GPIO is in output mode, write (1) puts
	   the corresponding GPO in Low level.
 */
#define MFXSTM32L496G_DISCO_REG_ADR_GPO_CLR1    0x70U /* gpio [0:7] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPO_CLR2    0x71U /* gpio [8:15] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPO_CLR3    0x72U /* agpio [0:7] */
/**
 * @brief Reg addr: GPIO STATE (R): Give state of the GPIO pin.
 */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_STATE1 0x10U /* gpio [0:7] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_STATE2         0x11U /* gpio [8:15] */
#define MFXSTM32L496G_DISCO_REG_ADR_GPIO_STATE3 0x12U /* agpio [0:7] */

/* GPIOs can INDIVIDUALLY generate interruption to the Main MCU thanks to the MFXSTM32L152_IRQ_OUT
 * signal */
/* the general MFXSTM32L152_IRQ_GPIO_SRC_EN shall be enabled too          */
/* GPIO IRQ_GPI_SRC1/2/3 (R/W): registers enable or not the feature to generate irq */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_SRC1 0x48U /* gpio [0:7] */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_SRC2 0x49U /* gpio [8:15] */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_SRC3 0x4AU /* agpio [0:7] */

/**
 * @brief GPIO IRQ_GPI_EVT1/2/3 (R/W): Irq generated on level (0) or edge (1).
 */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_EVT1 0x4CU /* gpio [0:7] */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_EVT2 0x4DU /* gpio [8:15] */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_EVT3 0x4EU /* agpio [0:7] */

/**
  * @brief GPIO IRQ_GPI_TYPE1/2/3 (R/W): Irq generated on (0) : Low level or Falling edge.
	  (1) : High level or Rising edge.
  */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_TYPE1 0x50U /* gpio [0:7] */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_TYPE2 0x51U /* gpio [8:15] */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_TYPE3 0x52U /* agpio [0:7] */

/**
 * @brief GPIO IRQ_GPI_PENDING1/2/3 (R): irq occurs
 */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_PENDING1 0x0CU /* gpio [0:7] */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_PENDING2 0x0DU /* gpio [8:15] */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_PENDING3 0x0EU /* agpio [0:7] */

/**
 * @brief GPIO IRQ_GPI_ACK1/2/3 (W): Write (1) to acknowledge IRQ event
 */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_ACK1  0x54U /* gpio [0:7] */
#define MFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_ACK2  0x55U /* gpio [8:15] */
#define MMFXSTM32L496G_DISCO_REG_ADR_IRQ_GPI_ACK3 0x56U /* agpio [0:7] */