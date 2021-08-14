/*
 * Copyright (c) 2012, Texas Instruments Incorporated - http://www.ti.com/
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
 * \addtogroup cc2538-smartrf
 * @{
 *
 * \defgroup cc2538dk-leds SmartRF06EB LED driver
 *
 * LED driver implementation for the TI SmartRF06EB + cc2538EM
 * @{
 *
 * \file
 * LED driver implementation for the TI SmartRF06EB + cc2538EM
 */
#include "contiki.h"        //contiki系统库
#include "reg.h"            //寄存器定义库
#include "dev/leds.h"       //LED驱动库
#include "dev/gpio.h"       //GPIO驱动库

/*#define LEDS_GPIO_PIN_MASK   LEDS_ALL*/
#define LEDS_GPIO_PIN_MASK   LEDS_ALL//0x33
/*---------------------------------------------------------------------------*/
//led初始化
void
leds_arch_init(void)
{
	/*
	 * IO口对应的位置送1灯灭，送0灯亮
	 * 例如：开发板SM14Z2538PA1V3开发板的pC0对应的是板子上的D4红色LED，要让D4亮，
	 * D1-D3灯都不亮，给对应的0到7的8个GPIO口送对应的值1111 1110就可以了，
	 * (这里提到的从右到左IO口对应的二进制数的顺序，不是板子上登的顺序，不要混淆)
	 * 高四位1111从右到左表示：D2，D1都不亮
	 * PC4-->D2绿色LED,PC5-->D1蓝色LED,PC6-->未连接LED，PC7-->未连接LED;
	 * 低四位1110从右到左表示:D4红灯亮，D3黄色灯不亮()
	 * PC0-->D4红色LED,PC1-->D3黄色LED,PC2-->未连接LED，PC3-->未连接LED;
	 *
	 * */
  GPIO_SET_OUTPUT(GPIO_C_BASE, LEDS_GPIO_PIN_MASK);
  /*GPIO_WRITE_PIN(GPIO_C_BASE, LEDS_GPIO_PIN_MASK, 0xfe);//D4红灯亮
  GPIO_WRITE_PIN(GPIO_C_BASE, LEDS_GPIO_PIN_MASK, 0xfd);//黄灯D3灯亮
  GPIO_WRITE_PIN(GPIO_C_BASE, LEDS_GPIO_PIN_MASK, 0xef);//D2绿灯亮
  GPIO_WRITE_PIN(GPIO_C_BASE, LEDS_GPIO_PIN_MASK, 0xdf);//D1红灯亮*/
  GPIO_WRITE_PIN(GPIO_C_BASE, LEDS_GPIO_PIN_MASK, 0x00);//全亮
  GPIO_WRITE_PIN(GPIO_C_BASE, LEDS_GPIO_PIN_MASK, 0x33);//全灭
}
/*---------------------------------------------------------------------------*/
//获得LED状态
unsigned char
leds_arch_get(void)
{
  return GPIO_READ_PIN(GPIO_C_BASE, LEDS_GPIO_PIN_MASK);
}
/*---------------------------------------------------------------------------*/
//设置LED状态
void
leds_arch_set(unsigned char leds)
{
  GPIO_WRITE_PIN(GPIO_C_BASE, LEDS_GPIO_PIN_MASK, leds);
/*  GPIO_WRITE_PIN(GPIO_C_BASE, LEDS_GPIO_PIN_MASK, 0x00);
  GPIO_WRITE_PIN(GPIO_C_BASE, LEDS_GPIO_PIN_MASK, 0x0F);
  GPIO_WRITE_PIN(GPIO_C_BASE, LEDS_GPIO_PIN_MASK, 0xF0);*/
}
/*---------------------------------------------------------------------------*/

/**
 * @}
 * @}
 */
