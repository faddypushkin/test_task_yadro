#include "RGBW_device.h"

#include <stdint.h>

#include "stm32f4xx_hal.h"

bool RGDW_device_init(const i2chw_dev_t *p_dev)
{
	uint8_t data[] = {0, 0};
	i2chw_error_t ret;

	data[0] = REGISTER_0;			//Будем записывать в регистр 0
	data[1] |= RESET_COMPLETE_CHIP;		//Сброс микросхемы
	data[1] |= DEVICE_ALWAYS_ON << 3;	//По заданию микросхема всегда включена

	ret = I2CHW_WriteSync(p_dev, data, sizeof(data));
	if (ret != I2CHW_SUCCESS)
		return false;

	HAL_Delay(200);

	return true;
}

void RGBW_poweron_led(const i2chw_dev_t *p_dev, const RGBW_led led)
{
	uint8_t reg = REGISTER_4;
	uint8_t rx_data = 0;
	uint8_t tx_data[] = {0, 0};

	I2CHW_WriteReadSync(p_dev, &reg, sizeof(reg), &rx_data, sizeof(rx_data));

	rx_data |= LED_ALWAYS_ON << (led * 2);

	tx_data[0] = reg;
	tx_data[1] = rx_data;

	I2CHW_WriteSync(p_dev, tx_data, sizeof(tx_data));
}

void RGBW_poweroff_led(const i2chw_dev_t *p_dev, const RGBW_led led)
{
	uint8_t reg = REGISTER_4;
	uint8_t rx_data = 0;
	uint8_t tx_data[] = {0, 0};

	I2CHW_WriteReadSync(p_dev, &reg, sizeof(reg), &rx_data, sizeof(rx_data));

	rx_data &= ~(~LED_ALWAYS_OFF << (led * 2));

	tx_data[0] = reg;
	tx_data[1] = rx_data;

	I2CHW_WriteSync(p_dev, tx_data, sizeof(tx_data));
}

void RGBW_poweron_all_leds(const i2chw_dev_t *p_dev)
{
	uint8_t data[] = {0, 0};

	data[0] = REGISTER_4;
	data[1] |= ALL_LEDS_ALWAYS_ON;

	I2CHW_WriteSync(p_dev, data, sizeof(data));
}

void RGBW_poweroff_all_leds(const i2chw_dev_t *p_dev)
{
	uint8_t data[2];

	data[0] = REGISTER_4;
	data[1] &= ALL_LEDS_ALWAYS_OFF;

	I2CHW_WriteSync(p_dev, data, sizeof(data));
}

void RGBW_change_brightness_led(const i2chw_dev_t *p_dev, const RGBW_led led,
				const uint8_t brightness)
{
	uint8_t data[2];

	switch (led) {
	case LED_RED_D1:
		data[0] = REGISTER_6;
		break;
	case LED_GREEN_D2:
		data[0] = REGISTER_7;
		break;
	case LED_BLUE_D3:
		data[0] = REGISTER_8;
		break;
	case LED_WHITE_D4:
		data[0] = REGISTER_9;
		break;
	}

	data[1] = brightness;

	I2CHW_WriteSync(p_dev, data, sizeof(data));
}

void RGBW_set_color(const i2chw_dev_t *p_dev, const uint8_t red_brightness,
	const uint8_t green_brightness, const uint8_t blue_brightness)
{
	RGBW_change_brightness_led(p_dev, LED_RED_D1, red_brightness);
	RGBW_change_brightness_led(p_dev, LED_GREEN_D2, green_brightness);
	RGBW_change_brightness_led(p_dev, LED_BLUE_D3, red_brightness);
}
