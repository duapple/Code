#include "bme280_i2c.h"

static dig_reg_t dig_reg;

static unsigned short dig_T1;
static short dig_T2;
static short dig_T3;
static unsigned short dig_P1;
static short dig_P2;
static short dig_P3;
static short dig_P4;
static short dig_P5;
static short dig_P6;
static short dig_P7;
static short dig_P8;
static short dig_P9;
static unsigned char dig_H1;
static signed short dig_H2;
static unsigned char dig_H3;
static signed short dig_H4;
static signed short dig_H5;
static signed char dig_H6;

void i2c_init(void)
{
    i2c_sda_out();
    i2c_scl_out();

    i2c_sda_set(1);
    i2c_scl_set(1);
    
    i2c_delay_us(10000);
}

void i2c_start(void)
{
    i2c_sda_out();
    i2c_sda_set(1);
    i2c_scl_set(1);

    i2c_delay_us(1);
    i2c_sda_set(0);

    i2c_delay_us(1);
    i2c_scl_set(0);
    i2c_delay_us(1);
}

void i2c_stop(void)
{
    i2c_sda_out();
    i2c_scl_set(0);
    i2c_sda_set(0);

    i2c_scl_set(1);
    i2c_delay_us(1);
    i2c_sda_set(1);
    i2c_delay_us(1);
}

void i2c_ack(void)
{
    i2c_sda_out();
    i2c_scl_set(0);
    i2c_sda_set(1);

    i2c_delay_us(1);
    i2c_sda_set(0);
    i2c_scl_set(1);
    i2c_delay_us(1);
    i2c_scl_set(0);
    i2c_sda_set(1);
}

void i2c_nack()
{
    i2c_sda_out();
    i2c_scl_set(0);

    i2c_sda_set(1);
    i2c_delay_us(1);
    i2c_scl_set(1);
    i2c_delay_us(1);
    i2c_scl_set(0);
    i2c_scl_set(0);
}

bool i2c_wait_ack()
{
    i2c_scl_set(0);
    i2c_sda_set(1);
    i2c_delay_us(1);
    i2c_sda_in();
    i2c_scl_set(1);

    int timeout = 0;
    while (i2c_sda_read())
    {
        timeout++;
        if (timeout >= 250)
        {
            i2c_stop();
            return false;
        }
    }
    i2c_scl_set(0);
    i2c_delay_us(1);
    i2c_sda_out();
    i2c_sda_set(1);

    return true;
}

void i2c_write(uint8_t byte)
{
    i2c_sda_out();
    i2c_scl_set(0);
    int i = 7;
    for ( ; i >= 0; i--)
    {
        i2c_sda_set( (byte>>i) & 0x01);
        i2c_delay_us(1);
        i2c_scl_set(1);
        i2c_delay_us(1);
        i2c_delay_us(1);
        i2c_scl_set(0);
        i2c_delay_us(1);
    }
}

void i2c_read(uint8_t *byte)
{
    i2c_sda_in();
    int i = 8;
    uint8_t b = 0;
    for (; i > 0 ; i--)
    {
        b = b<<1;
        i2c_scl_set(0);
        i2c_delay_us(1);
        i2c_scl_set(1);
        i2c_delay_us(1);
        if (i2c_sda_read())
        {
            b++;
        }
        i2c_delay_us(1);
    }

    *byte = b;
}

int i2c_read_bytes(uint8_t slave_addr, uint8_t reg_addr, uint32_t len, uint8_t *byte)
{
    i2c_start();
    i2c_write(slave_addr);
    if (!i2c_wait_ack()) return 1;
    i2c_write(reg_addr);
    if (!i2c_wait_ack()) return 2;

    i2c_start();
    i2c_write(slave_addr+1);
    if (!i2c_wait_ack()) return 3;

    for (int i = 0; i < len - 1; i++)
    {
        i2c_read(byte + i);
        i2c_ack();
    }
    i2c_read(byte + len -1);
    i2c_nack();
    i2c_stop();

    return 0;
}

int i2c_write_bytes(uint8_t slave_addr, uint8_t reg_addr, uint32_t len, uint8_t *byte)
{
    i2c_start();
    i2c_write(slave_addr);
    if (!i2c_wait_ack()) return 1;
    for (int i = 0; i < len; i++)
    {
        i2c_write(reg_addr + i);
        if (!i2c_wait_ack()) return 2;
        i2c_write(*(byte+i));
        if (!i2c_wait_ack()) return 3;
    }

    i2c_stop();

    return 0;
}

typedef long BME280_S32_t;
typedef unsigned long BME280_U32_t;
typedef long long BME280_S64_t;
/* Returns temperature in DegC, resolution is 0.01 DegC. Output value of “5123” equals 51.23
 * DegC.
 * t_fine carries fine temperature as global value
 */
BME280_S32_t t_fine;
BME280_S32_t BME280_compensate_T_int32(BME280_S32_t adc_T)
{
    BME280_S32_t var1, var2, T;
    var1 = ((((adc_T >> 3) - ((BME280_S32_t)dig_T1 << 1))) * ((BME280_S32_t)dig_T2)) >> 11;
    var2 = (((((adc_T >> 4) - ((BME280_S32_t)dig_T1)) * ((adc_T >> 4) - ((BME280_S32_t)dig_T1))) >> 12) *
            ((BME280_S32_t)dig_T3)) >>
           14;
    t_fine = var1 + var2;
    T = (t_fine * 5 + 128) >> 8;
    return T;
}

/* Returns pressure in Pa as unsigned 32 bit integer in Q24.8 format (24 integer bits and 8
 *  fractional bits).
 *  Output value of “24674867” represents 24674867/256 = 96386.2 Pa = 963.862 hPa
 */
BME280_U32_t BME280_compensate_P_int64(BME280_S32_t adc_P)
{
    BME280_S64_t var1, var2, p;
    var1 = ((BME280_S64_t)t_fine) - 128000;
    var2 = var1 * var1 * (BME280_S64_t)dig_P6;
    var2 = var2 + ((var1 * (BME280_S64_t)dig_P5) << 17);
    var2 = var2 + (((BME280_S64_t)dig_P4) << 35);
    var1 = ((var1 * var1 * (BME280_S64_t)dig_P3) >> 8) + ((var1 * (BME280_S64_t)dig_P2) << 12);
    var1 = (((((BME280_S64_t)1) << 47) + var1)) * ((BME280_S64_t)dig_P1) >> 33;
    if (var1 == 0)
    {
        return 0; // avoid exception caused by division by zero
    }
    p = 1048576 - adc_P;
    p = (((p << 31) - var2) * 3125) / var1;
    var1 = (((BME280_S64_t)dig_P9) * (p >> 13) * (p >> 13)) >> 25;
    var2 = (((BME280_S64_t)dig_P8) * p) >> 19;
    p = ((p + var1 + var2) >> 8) + (((BME280_S64_t)dig_P7) << 4);
    return (BME280_U32_t)p;
}

/* Returns humidity in %RH as unsigned 32 bit integer in Q22.10 format (22 integer and 10
 * fractional bits).
 * Output value of “47445” represents 47445/1024 = 46.333 %RH
 */
BME280_U32_t bme280_compensate_H_int32(BME280_S32_t adc_H)
{
    BME280_S32_t v_x1_u32r;
    v_x1_u32r = (t_fine - ((BME280_S32_t)76800));
    v_x1_u32r = (((((adc_H << 14) - (((BME280_S32_t)dig_H4) << 20) - (((BME280_S32_t)dig_H5) *
                    v_x1_u32r)) +
                   ((BME280_S32_t)16384)) >>
                  15) *
                 (((((((v_x1_u32r *
                        ((BME280_S32_t)dig_H6)) >>
                       10) *
                      (((v_x1_u32r * ((BME280_S32_t)dig_H3)) >> 11) +
                       ((BME280_S32_t)32768))) >>
                     10) +
                    ((BME280_S32_t)2097152)) *
                   ((BME280_S32_t)dig_H2) +
                   8192) >>
                  14));
    v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) *
                               ((BME280_S32_t)dig_H1)) >>
                              4));
    v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
    v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);
    return (BME280_U32_t)(v_x1_u32r >> 12);
}

int bme280_reset()
{
    uint8_t byte[1] = {0xb6};
    int ret = i2c_write_bytes(BME280_ADDR, BME280_REG_RESET, 1, byte);
    if (ret) return ret;
    
    i2c_delay_us(10000);
    return 0;
}

int bme280_read_device_id(uint8_t *id)
{
    uint8_t byte[1] = {0};
    int ret = i2c_read_bytes(BME280_ADDR, BME280_REG_ID, 1, byte);
    if (ret) return ret;
    *id = byte[0];
    return 0;
}

int bme280_init_config()
{
    uint8_t id = 0;
    int ret = 0;

    ret = bme280_reset();
    if (ret)
    {
        i2c_debug_print("bme280 reset error: %d\n", ret);
        return ret;
    }
    ret = bme280_read_device_id(&id);
    if (ret) 
    {
        i2c_debug_print("bme280 read device id error: %d\n", ret);
        return ret;
    } else {
        i2c_debug_print("device id: 0x%02X", id);
    }
    
    uint8_t *byte = (uint8_t *)&dig_reg;
    ret = i2c_read_bytes(BME280_ADDR, BME280_REG_DIG_T1, sizeof(dig_reg), byte);
    if (ret) return ret;
    
    dig_T1 = dig_reg.dig_T1;
    dig_T2 = dig_reg.dig_T2;
    dig_T3 = dig_reg.dig_T3;
    dig_P1 = dig_reg.dig_P1;
    dig_P2 = dig_reg.dig_P2;
    dig_P3 = dig_reg.dig_P3;
    dig_P4 = dig_reg.dig_P4;
    dig_P5 = dig_reg.dig_P5;
    dig_P6 = dig_reg.dig_P6;
    dig_P7 = dig_reg.dig_P7;
    dig_P8 = dig_reg.dig_P8;
    dig_P9 = dig_reg.dig_P9;
    
    uint8_t byte_2[2] = {0};
    
    ret = i2c_read_bytes(BME280_ADDR, 0xa1, 1, &dig_H1);
    if (ret) return ret;
    
    ret = i2c_read_bytes(BME280_ADDR, 0xe1, 2, byte_2);
    if (ret) return ret;
    dig_H2 = (byte_2[1] << 8) | byte_2[0];
    
    ret = i2c_read_bytes(BME280_ADDR, 0xe3, 1, &dig_H3);
    if (ret) return ret;
    
    ret = i2c_read_bytes(BME280_ADDR, 0xe4, 2, byte_2);
    if (ret) return ret;
    dig_H4= (byte_2[0] << 4) | (byte_2[1] & 0x0f);
    
    ret = i2c_read_bytes(BME280_ADDR, 0xe5, 2, byte_2);
    if (ret) return ret;
    dig_H5= (byte_2[1] << 4) | ( (byte_2[0] >> 4) & 0x0f);

    ret = i2c_read_bytes(BME280_ADDR, 0xe7, 1, (uint8_t *)&dig_H6);
    if (ret) return ret;
    
    #if 0
    i2c_debug_print("dig_T1: %d", dig_T1);
    i2c_debug_print("dig_T2: %d", dig_T2);
    i2c_debug_print("dig_T3: %d", dig_T3);
    i2c_debug_print("dig_P1: %d", dig_P1);
    i2c_debug_print("dig_P2: %d", dig_P2);
    i2c_debug_print("dig_P3: %d", dig_P3);
    i2c_debug_print("dig_P4: %d", dig_P4);
    i2c_debug_print("dig_P5: %d", dig_P5);
    i2c_debug_print("dig_P6: %d", dig_P6);
    i2c_debug_print("dig_P7: %d", dig_P7);
    i2c_debug_print("dig_P8: %d", dig_P8);
    i2c_debug_print("dig_P9: %d", dig_P9);
    #if 1
    i2c_debug_print("dig_H1: %d", dig_H1);
    i2c_debug_print("dig_H2: %d", dig_H2);
    i2c_debug_print("dig_H3: %d", dig_H3);
    i2c_debug_print("dig_H4: %d", dig_H4);
    i2c_debug_print("dig_H5: %d", dig_H5);
    i2c_debug_print("dig_H6: %d", dig_H6);
    #endif
    #endif
    NRF_LOG_FLUSH();

    uint8_t temp = 0x01;
    
    ret = i2c_write_bytes(BME280_ADDR, BME280_REG_CTRL_HUM, 1, &temp);
    if (ret) return ret;

    temp = 0XFF;
    ret = i2c_write_bytes(BME280_ADDR, BME280_REG_CTRL_MEAS, 1, &temp);
    if (ret) return ret;

    temp = 0XF0;
    ret = i2c_write_bytes(BME280_ADDR, BME280_REG_CONFIG, 1, &temp);
    if (ret) return ret;

    i2c_delay_us(100000);
    return 0;
}

int bme280_read_temperature(int32_t *temperature)
{
    unsigned long  msb, lsb, xlsb;
    uint8_t byte[3] = {0};
    long temp = 0;

    int ret = i2c_read_bytes(BME280_ADDR, BME280_REG_TEMP, 3, byte);
    if (ret) return ret;

    msb = byte[0];
    lsb = byte[1];
    xlsb = byte[2];

    temp = (xlsb >> 4) | (lsb << 4) | (msb << 12);
    *temperature = BME280_compensate_T_int32(temp);
    return 0;
}

int bme280_read_humidity(uint32_t *humidity)
{
    unsigned long  msb, lsb;
    uint8_t byte[2] = {0};
    long humi = 0;

    int ret = i2c_read_bytes(BME280_ADDR, BME280_REG_HUMI, 2, byte);
    if (ret) return ret;

    msb = byte[0];
    lsb = byte[1];

    humi = (msb << 8) | lsb;
    *humidity = bme280_compensate_H_int32(humi) * 100 / 1024;
    return 0;
}

int bme280_read_pressure(int32_t *pressure)
{
    unsigned long  msb, lsb, xlsb;
    uint8_t byte[3] = {0};
    long press = 0;

    int ret = i2c_read_bytes(BME280_ADDR, BME280_REG_PRESS, 2, byte);
    if (ret) return ret;

    msb = byte[0];
    lsb = byte[1];
    xlsb = byte[2];

    press = (xlsb >> 4) | (lsb << 4) | (msb << 12);
    *pressure = BME280_compensate_P_int64(press) / 256;

    return 0;
}

