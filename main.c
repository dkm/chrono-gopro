/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Hello World application
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 * @author      Ludwig Ortmann <ludwig.ortmann@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>
#include <stdint.h>
#include "periph/gpio.h"
#include "xtimer.h"
#include "cc110x.h"

cc110x_t radio;

void my_cb(void* e){
    printf ("Ping\n");
}

int main(void)
{
  /* unsigned long us_per_tick = 1; */
  cc110x_setup(&radio, 0);
  gpio_t test = GPIO_PIN(2,4);
  gpio_init(test, GPIO_DIR_OUT, GPIO_PULLUP); //, my_cb, NULL);
  gpio_clear(test);
  /* puts("Hello World!"); */
    //  xtimer_usleep(1000000);

  /* timer_init(0, us_per_tick, my_cb); */
  /* timer_set(0, 0, 1000000); */
  /* printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD); */
  /* printf("This board features a(n) %s MCU.\n", RIOT_MCU); */
  int i = 0;
  
  while(1){
    if (i)
      gpio_clear(test);
    else
      gpio_set(test);

    xtimer_usleep(1000000);
    /* i = (i+1) % 100; */
    int r = gpio_read(test);
    printf("v%d%d\n", r,i);
    i = (i + 1) % 2 ;
    /* int g = gpio_read(test); */
    /* printf("toto%d %2d\n", g, i); */
  }
    return 0;
}
