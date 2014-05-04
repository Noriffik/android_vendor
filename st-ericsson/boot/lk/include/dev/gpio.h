/*
 * Copyright (c) 2008, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the 
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef __DEV_GPIO_H
#define __DEV_GPIO_H

#ifndef GPIO_INPUT
#define GPIO_INPUT	0x0000
#endif
#ifndef GPIO_OUTPUT
#define GPIO_OUTPUT	0x0001
#endif

#define GPIO_LEVEL	0x0000
#define GPIO_EDGE	0x0010

#define GPIO_RISING	0x0020
#define GPIO_FALLING	0x0040

#define GPIO_HIGH	0x0020
#define GPIO_LOW	0x0040

#define GPIO_PULLNONE	0x0000
#define GPIO_PULLUP	0x0100
#define GPIO_PULLDOWN	0x0200

int gpio_config(unsigned nr, unsigned flags);
void gpio_set(unsigned nr, unsigned on);
int gpio_get(unsigned nr);

/**
 * gpio_get_mode() - get the input/output mode on a gpio
 * @nr: pin number
 */
int gpio_get_mode(unsigned nr);


/**
 * gpio_get_pull() - get the  pull up/down mode on a gpio
 * @nr: pin number
 */
int gpio_get_pull(unsigned nr);


/**
 * gpio_get_alt() - get the alternate mode gpio/alta/altb/altc on a gpio
 * @nr: pin number
 */
int gpio_get_alt(unsigned nr);


/**
 * gpio_make_input() - configure the input mode on a gpio
 * @nr: pin number
 */
void gpio_make_input(unsigned nr);


/**
 * gpio_set_pull() - enable/disable pull up/down on a gpio
 * @nr: pin number
 * @pull: one of GPIO_PULL_DOWN, GPIO_PULL_UP,
 *  and PIO_PULL_NONE
 *
 * Enables/disables pull up/down on a specified pin.  This only takes effect if
 * the pin is configured as an input (either explicitly or by the alternate
 * function).
 *
 * NOTE: If enabling the pull up/down, the caller must ensure that the GPIO is
 * configured as an input.  Otherwise, due to the way the controller registers
 * work, this function will change the value output on the pin.
 */
void gpio_set_pull(unsigned nr,unsigned  pull);

#endif