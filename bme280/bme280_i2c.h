#ifndef __BME280_I2C_H__
#define __BME280_I2C_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "boards.h"
#include "bsp.h"
#include "nrf_delay.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

/* 平台接口定义 */
#define SDA_PIN                  NRF_GPIO_PIN_MAP(1,13)
#define SCL_PIN                  NRF_GPIO_PIN_MAP(1, 15)

#define i2c_sda_set(i)           nrf_gpio_pin_write(SDA_PIN, i)
#define i2c_scl_set(i)           nrf_gpio_pin_write(SCL_PIN, i)
#define i2c_sda_read()           nrf_gpio_pin_read(SDA_PIN)
#define i2c_sda_out()            nrf_gpio_cfg_output(SDA_PIN)
#define i2c_sda_in()             nrf_gpio_cfg_input(SDA_PIN, GPIO_PIN_CNF_PULL_Pullup)
#define i2c_scl_out()            nrf_gpio_cfg_output(SCL_PIN)
#define i2c_debug_print(...)     NRF_LOG_INFO(__VA_ARGS__)
#define i2c_delay_us(t)          nrf_delay_us(t)
/* end */ 

/* 寄存器地址 */
#define BME280_ADDR              0XEC
#define BME280_REG_ID            0XD0
#define BME280_REG_CTRL_MEAS     0XF4
#define BME280_REG_RESET         0XE0
#define BME280_REG_CTRL_HUM      0XF2
#define BME280_REG_CONFIG        0XF5
#define BME280_REG_TEMP          0XFA
#define BME280_REG_HUMI          0XFD
#define BME280_REG_PRESS         0XF7
#define BME280_REG_DIG_T1        0x88
/* end */

typedef struct dig {
    uint16_t dig_T1;
    int16_t dig_T2;
    int16_t dig_T3;
    uint16_t dig_P1;
    int16_t dig_P2;
    int16_t dig_P3;
    int16_t dig_P4;
    int16_t dig_P5;
    int16_t dig_P6;
    int16_t dig_P7;
    int16_t dig_P8;
    int16_t dig_P9;
    uint8_t dig_H1;
    int16_t dig_H2;
    uint8_t dig_H3;
    int16_t dig_H4;
    int16_t dig_H5;
    int8_t dig_H6;
}dig_reg_t;

void i2c_init(void);
int bme280_reset(void);
int bme280_init_config(void);
int bme280_read_temperature(int32_t *temperature);
int bme280_read_humidity(uint32_t *humidity);
int bme280_read_pressure(int32_t *pressure);

#endif // __BME280_I2C_H__
