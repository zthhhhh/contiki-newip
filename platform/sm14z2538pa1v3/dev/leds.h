/*
 * Copyright (c) 2005, Swedish Institute of Computer Science
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
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */
/**
 * \addtogroup dev
 * @{
 */

/**
 * \defgroup leds LEDs API
 *
 * The LEDs API defines a set of functions for accessing LEDs for
 * Contiki plaforms with LEDs.
 *
 * A platform with LED support must implement this API.
 * @{
 */

#ifndef LEDS_H_
#define LEDS_H_

/* Allow platform to override LED numbering */
#include "contiki-conf.h"

void leds_init(void);

/**
 * Blink all LEDs.
 */
void leds_blink(void);

#ifndef LEDS_GREEN
#define LEDS_GREEN  0x10                   //??????LED
#endif /* LEDS_GREEN */
#ifndef LEDS_YELLOW
#define LEDS_YELLOW  0x02                  //??????LED
#endif /* LEDS_YELLOW */
#ifndef LEDS_RED
#define LEDS_RED  0x01                     //??????LED
#endif /* LEDS_RED */
#ifndef LEDS_BLUE
#define LEDS_BLUE  32          //??????LED
#endif /* LEDS_BLUE */

#ifndef LEDS_ALL  LEDS_CONF_ALL        //???????????????LED
//#define LEDS_ALL            //???????????????led
#define LEDS_ALL    51                   //LED ALL ???51
#endif

/**
 * Returns the current status of all leds
 */
unsigned char leds_get(void);           //led??????
void leds_set(unsigned char leds);      //led??????
void leds_on(unsigned char leds);       //led???
void leds_off(unsigned char leds);      //led???
void leds_toggle(unsigned char leds);   //led????????????

/**
 * Leds implementation
 */
void leds_arch_init(void);              //led?????????
unsigned char leds_arch_get(void);      //led??????
void leds_arch_set(unsigned char leds); //led??????

#endif /* LEDS_H_ */

/** @} */
/** @} */
