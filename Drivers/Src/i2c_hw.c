#include "i2c_hw.h"

#include "stm32f4xx_hal.h"

static I2C_HandleTypeDef hi2c[4];
static i2chw_dir_mode_t device_mode[4];

i2chw_error_t I2CHW_Init(const i2chw_bus_t bus_num)
{

}

i2chw_error_t I2CHW_Configure(const i2chw_bus_t bus_num,
			      const i2chw_cfg_t *p_config)
{
	if (bus_num == I2CHW_BUS_I2C0) {
		//hi2c0.Instance = I2C0;	//Не поддерживается на моём МК

		switch (p_config->bus_freq) {
		case 0:
			hi2c[0].Init.ClockSpeed = 10000;
			break;
		case 1:
			hi2c[0].Init.ClockSpeed = 100000;
			break;
		case 2:
			hi2c[0].Init.ClockSpeed = 400000;
			break;
		case 3:
			hi2c[0].Init.ClockSpeed = 1000000;
			break;
		default:
			return I2CHW_ERR_INVALID_PARAMS;
		}

		hi2c[0].Init.DutyCycle = I2C_DUTYCYCLE_2;
		hi2c[0].Init.OwnAddress1 = 0;
		hi2c[0].Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
		hi2c[0].Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
		hi2c[0].Init.OwnAddress2 = 0;
		hi2c[0].Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
		hi2c[0].Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

		device_mode[0] = p_config->dir_mode;
	} else if (bus_num == I2CHW_BUS_I2C1) {
		hi2c[1].Instance = I2C1;

		switch (p_config->bus_freq) {
		case 0:
			hi2c[1].Init.ClockSpeed = 10000;
			break;
		case 1:
			hi2c[1].Init.ClockSpeed = 100000;
			break;
		case 2:
			hi2c[1].Init.ClockSpeed = 400000;
			break;
		case 3:
			hi2c[1].Init.ClockSpeed = 1000000;
			break;
		default:
			return I2CHW_ERR_INVALID_PARAMS;
		}

		hi2c[1].Init.DutyCycle = I2C_DUTYCYCLE_2;
		hi2c[1].Init.OwnAddress1 = 0;
		hi2c[1].Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
		hi2c[1].Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
		hi2c[1].Init.OwnAddress2 = 0;
		hi2c[1].Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
		hi2c[1].Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

		device_mode[1] = p_config->dir_mode;
	} else if (bus_num == I2CHW_BUS_I2C2) {
		hi2c[2].Instance = I2C2;

		switch (p_config->bus_freq) {
		case 0:
			hi2c[2].Init.ClockSpeed = 10000;
			break;
		case 1:
			hi2c[2].Init.ClockSpeed = 100000;
			break;
		case 2:
			hi2c[2].Init.ClockSpeed = 400000;
			break;
		case 3:
			hi2c[2].Init.ClockSpeed = 1000000;
			break;
		default:
			return I2CHW_ERR_INVALID_PARAMS;
		}

		hi2c[2].Init.DutyCycle = I2C_DUTYCYCLE_2;
		hi2c[2].Init.OwnAddress1 = 0;
		hi2c[2].Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
		hi2c[2].Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
		hi2c[2].Init.OwnAddress2 = 0;
		hi2c[2].Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
		hi2c[2].Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

		device_mode[2] = p_config->dir_mode;
	} else if (bus_num == I2CHW_BUS_I2C3) {
		hi2c[3].Instance = I2C3;

		switch (p_config->bus_freq) {
		case 0:
			hi2c[3].Init.ClockSpeed = 10000;
			break;
		case 1:
			hi2c[3].Init.ClockSpeed = 100000;
			break;
		case 2:
			hi2c[3].Init.ClockSpeed = 400000;
			break;
		case 3:
			hi2c[3].Init.ClockSpeed = 1000000;
			break;
		default:
			return I2CHW_ERR_INVALID_PARAMS;
		}

		hi2c[3].Init.DutyCycle = I2C_DUTYCYCLE_2;
		hi2c[3].Init.OwnAddress1 = 0;
		hi2c[3].Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
		hi2c[3].Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
		hi2c[3].Init.OwnAddress2 = 0;
		hi2c[3].Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
		hi2c[3].Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

		device_mode[3] = p_config->dir_mode;
	} else
		return I2CHW_ERR_INVALID_PARAMS;

	return I2CHW_SUCCESS;
}

i2chw_error_t I2CHW_WriteSync(const i2chw_dev_t* p_dev,
			      const uint8_t* p_tx_data,
			      const uint16_t tx_data_len)
{

}

i2chw_error_t I2CHW_WriteReadSync(const i2chw_dev_t* p_dev,
				  const uint8_t* p_tx_data,
				  const uint16_t tx_data_len,
				  uint8_t* p_rx_data,
				  const uint16_t rx_data_len)
{

}

i2chw_error_t I2CHW_ReadSync(const i2chw_dev_t* p_dev,
			     uint8_t* p_rx_data,
			     const uint16_t rx_data_len)
{

}
