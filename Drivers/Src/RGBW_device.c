#include "RGBW_device.h"

#include <stdint.h>

bool RGDW_device_init(const i2chw_dev_t *p_dev)
{
	uint8_t reset_data[] = {0, 0};

	reset_data[0] = REGISTER_0;		//Будем записывать в регистр 0
	reset_data[1] |= RESET_COMPLETE_CHIP;	//Сброс микросхемы
	reset_data[1] |= DEVICE_ALWAYS_ON << 3;	//По заданию микросхема всегда включена

	I2CHW_WriteSync(p_dev, reset_data, sizeof(reset_data));

	HAL_Delay(200);
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
