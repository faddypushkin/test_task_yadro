/**
 * @brief Драйвер микросхемы с RGDW светодиодами
 */

#include <stdbool.h>

#include "i2c_hw.h"

#define DO_NOTHING		0b100
#define RESET_REGISTERS_ONLY	0b101
#define RESET_COMPLETE_CHIP	0b111

#define DEVICE_ENTERS_SHUTDOWN	0b00
#define DEVICE_ALWAYS_ON	0b11

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

/**
 * @brief Первоначальная инициализация микросхемы
 */
bool RGDW_device_init(const i2chw_dev_t *p_dev);
