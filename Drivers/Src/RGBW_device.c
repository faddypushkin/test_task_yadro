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
