/*
 * Copyright (c) 2013, ADVANSEE - http://www.advansee.com/
 * Benoît Thébaudeau <benoit.thebaudeau@advansee.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * \addtogroup cc2538dk-als-sensor
 * @{
 *
 * \file
 *  Driver for the SmartRF06EB ALS
 */
#include "contiki.h"            //contiki系统接口
#include "sys/clock.h"          //系统时钟
#include "dev/ioc.h"            //ioc驱动
#include "dev/gpio.h"           //gpio驱动
#include "dev/adc.h"            //adc驱动
#include "dev/als-sensor.h"     //als传感器

#include <stdint.h>             //标准数据类型定义库
//定义ADC硬件IO口
#define ADC_ALS_PWR_PORT_BASE    GPIO_PORT_TO_BASE(ADC_ALS_PWR_PORT)
#define ADC_ALS_PWR_PIN_MASK     GPIO_PIN_MASK(ADC_ALS_PWR_PIN)
#define ADC_ALS_OUT_PIN_MASK     GPIO_PIN_MASK(ADC_ALS_OUT_PIN)
/*---------------------------------------------------------------------------*/
//变量初始化
static int
value(int type)
{
  uint8_t channel = SOC_ADC_ADCCON_CH_AIN0 + ADC_ALS_OUT_PIN;
  int16_t res;
  //引脚设置
  GPIO_SET_PIN(ADC_ALS_PWR_PORT_BASE, ADC_ALS_PWR_PIN_MASK);
  //延时2ms
  clock_delay_usec(2000);
  //读取通道的数值
  res = adc_get(channel, SOC_ADC_ADCCON_REF_INT, SOC_ADC_ADCCON_DIV_512);
  //GPIO复位
  GPIO_CLR_PIN(ADC_ALS_PWR_PORT_BASE, ADC_ALS_PWR_PIN_MASK);
  //返回ADC的值
  return res;
}
/*---------------------------------------------------------------------------*/
//GPIO配置
static int
configure(int type, int value)
{
  switch(type) {
  case SENSORS_HW_INIT:
    GPIO_SOFTWARE_CONTROL(ADC_ALS_PWR_PORT_BASE, ADC_ALS_PWR_PIN_MASK);
    GPIO_SET_OUTPUT(ADC_ALS_PWR_PORT_BASE, ADC_ALS_PWR_PIN_MASK);
    GPIO_CLR_PIN(ADC_ALS_PWR_PORT_BASE, ADC_ALS_PWR_PIN_MASK);
    ioc_set_over(ADC_ALS_PWR_PORT, ADC_ALS_PWR_PIN, IOC_OVERRIDE_DIS);

    GPIO_SOFTWARE_CONTROL(GPIO_A_BASE, ADC_ALS_OUT_PIN_MASK);
    GPIO_SET_INPUT(GPIO_A_BASE, ADC_ALS_OUT_PIN_MASK);
    ioc_set_over(GPIO_A_NUM, ADC_ALS_OUT_PIN, IOC_OVERRIDE_ANA);

    break;
  }
  return 0;
}
/*---------------------------------------------------------------------------*/
//状态
static int
status(int type)
{
  return 1;
}
/*---------------------------------------------------------------------------*/
SENSORS_SENSOR(als_sensor, ALS_SENSOR, value, configure, status);

/** @} */
