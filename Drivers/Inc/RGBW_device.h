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

#define ALL_LEDS_ALWAYS_OFF	0b00000000
#define ALL_LEDS_ALWAYS_ON	0b01010101

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
 *
 * @param p_dev - указатель на конфигурацию I2C микросхемы с RGBW светодиодами
 * @return true - инициализация прошла успешно
 * false - ошибка при передаче данных
 */
bool RGBW_device_init(const i2chw_dev_t *p_dev);

/**
 * @brief Включение каждого канала по отдельности
 *
 * @param p_dev - указатель на конфигурацию I2C микросхемы с RGBW светодиодами
 * @param led - светодиод, с которым будем производить действие
 * @return true - включение прошло успешно
 * false - ошибка при передаче данных
 */
bool RGBW_poweron_led(const i2chw_dev_t *p_dev, const RGBW_led led);

/**
 * @brief Выключение каждого канала по отдельности
 *
 * @param p_dev - указатель на конфигурацию I2C микросхемы с RGBW светодиодами
 * @param led - светодиод, с которым будем производить действие
 * @return true - выключение прошло успешно
 * false - ошибка при передаче данных
 */
bool RGBW_poweroff_led(const i2chw_dev_t *p_dev, const RGBW_led led);

/**
 * @brief Включение всех каналов одновременно
 *
 * @param p_dev - указатель на конфигурацию I2C микросхемы с RGBW светодиодами
 * @return true - включение прошло успешно
 * false - ошибка при передаче данных
 */
bool RGBW_poweron_all_leds(const i2chw_dev_t *p_dev);

/**
 * @brief Выключение всех каналов одновременно
 *
 * @param p_dev - указатель на конфигурацию I2C микросхемы с RGBW светодиодами
 * @return true - выключение прошло успешно
 * false - ошибка при передаче данных
 */
bool RGBW_poweroff_all_leds(const i2chw_dev_t *p_dev);

/**
 * @brief Изменение яркости каждого канала по отдельности
 *
 * @param p_dev - указатель на конфигурацию I2C микросхемы с RGBW светодиодами
 * @param led - светодиод, с которым будем производить действие
 * @param brightness - параметр яркости светодиода (0 до 255)
 * @return true - изменение яркости прошло успешно
 * false - ошибка при передаче данных
 */
bool RGBW_change_brightness_led(const i2chw_dev_t *p_dev, const RGBW_led led,
				const uint8_t brightness);

/**
 * @brief Установка цвета изменением яркости светодиодов R, G, B
 *
 * @param p_dev - указатель на конфигурацию I2C микросхемы с RGBW светодиодами
 * @param red_brightness - параметр яркости красного светодиода (0 до 255)
 * @param green_brightness - параметр яркости зелёного светодиода (0 до 255)
 * @param blue_brightness - параметр яркости синего светодиода (0 до 255)
 * @return true - установка цвета прошло успешно
 * false - ошибка при передаче данных
 */
bool RGBW_set_color(const i2chw_dev_t *p_dev, const uint8_t red_brightness,
		const uint8_t green_brightness, const uint8_t blue_brightness);
