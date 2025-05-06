/**
 * @brief Драйвер микросхемы с RGBW светодиодами
 */

#include <stdbool.h>

#include "i2c_hw.h"

#define DO_NOTHING		0b100
#define RESET_REGISTERS_ONLY	0b101
#define RESET_COMPLETE_CHIP	0b111

#define DEVICE_ENTERS_SHUTDOWN	0b00
#define DEVICE_ALWAYS_ON	0b11

#define LED_ALWAYS_OFF		0b00
#define LED_ALWAYS_ON		0b01

enum {
	REGISTER_0,
	REGISTER_1,
	REGISTER_2,
	REGISTER_3,
	REGISTER_4,
	REGISTER_5,
	REGISTER_6,
	REGISTER_7,
	REGISTER_8,
	REGISTER_9,
};

typedef enum {
	LED_RED_D1,
	LED_GREEN_D2,
	LED_BLUE_D3,
	LED_WHITE_D4,
} RGBW_led;

/**
 * @brief Первоначальная инициализация микросхемы
 */
bool RGBW_device_init(const i2chw_dev_t *p_dev);

/**
 * @brief Включение каждоко канала по отдельности
 */
void RGBW_poweron_led(const i2chw_dev_t *p_dev, const RGBW_led led);

/**
 * @brief Выключение каждоко канала по отдельности
 */
void RGBW_poweroff_led(const i2chw_dev_t *p_dev, const RGBW_led led);
