/* Copyright (c) 2014 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */
#ifndef BOARDS_H
#define BOARDS_H

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "nrf_gpio.h"

#include BOARD_HEADER_FILE

#ifndef BUTTON_DFU
#define BUTTON_DFU      BUTTON_1
#endif
#ifndef BUTTON_FRESET
#define BUTTON_FRESET   BUTTON_2
#endif

// The primary LED is usually Red but not in all cases.
#define LED_PRIMARY 0
// The secondary LED, when available, is usually blue.
#define LED_SECONDARY 1

// Its more common for LEDs to be sinking to the MCU pin. Setting is only for individual LEDs, not
// RGB LEDs.
#ifndef LED_STATE_ON
#define LED_STATE_ON   0
#endif

// Internal status colors are masked by this brightness setting.
#ifndef BOARD_RGB_BRIGHTNESS
#define BOARD_RGB_BRIGHTNESS 0x101010
#endif

// Helper function
#define memclr(buffer, size)                memset(buffer, 0, size)
#define varclr(_var)                        memclr(_var, sizeof(*(_var)))
#define arrclr(_arr)                        memclr(_arr, sizeof(_arr))
#define arrcount(_arr)                      ( sizeof(_arr) / sizeof(_arr[0]) )

void board_init(void);
void board_teardown(void);

//--------------------------------------------------------------------+
// LED
//--------------------------------------------------------------------+

#define bit(b) (1UL << (b))

enum {
  STATE_BOOTLOADER_STARTED = 0,
  STATE_USB_MOUNTED,
  STATE_USB_UNMOUNTED,
  STATE_FACTORY_RESET_STARTED,
  STATE_FACTORY_RESET_FINISHED,
  STATE_WRITING_STARTED,
  STATE_WRITING_FINISHED,
  STATE_BLE_CONNECTED,
  STATE_BLE_DISCONNECTED
};

void led_pwm_init(uint32_t led_index, uint32_t led_pin);
void led_pwm_teardown(void);
void led_pwm_disable(uint32_t led_index);
void led_pwm_enable(uint32_t led_index);
void led_state(uint32_t state);
void led_tick(void);
void printd(char *str);
void uart_init(void);

//--------------------------------------------------------------------+
// BUTTONS
//--------------------------------------------------------------------+
// Make sure we have at least two buttons (DFU + FRESET since DFU+FRST=OTA)
#if BUTTONS_NUMBER < 2
#error "At least two buttons required in the BSP (see 'BUTTONS_NUMBER')"
#endif

static inline void button_init(uint32_t pin)
{
  nrf_gpio_cfg_sense_input(pin, BUTTON_PULL, NRF_GPIO_PIN_SENSE_LOW);
}

static inline bool button_pressed(uint32_t pin)
{
  return (nrf_gpio_pin_read(pin) == 0) ? true : false;
}

bool is_ota(void);

//--------------------------------------------------------------------+
// DEBUG
//--------------------------------------------------------------------+
//#define CFG_DEBUG

#ifdef CFG_DEBUG

#include <stdio.h>

#define PRINT_LOCATION()      printf("%s: %d:\n", __PRETTY_FUNCTION__, __LINE__)
#define PRINT_MESS(x)         printf("%s: %d: %s \n"   , __FUNCTION__, __LINE__, (char*)(x))
#define PRTNT_HEAP()          if (CFG_DEBUG == 3) printf("\n%s: %d: Heap free: %d\n", __FUNCTION__, __LINE__, util_heap_get_free_size())
#define PRINT_STR(x)          printf("%s: %d: " #x " = %s\n"   , __FUNCTION__, __LINE__, (char*)(x) )
#define PRINT_INT(x)          printf("%s: %d: " #x " = %ld\n"  , __FUNCTION__, __LINE__, (uint32_t) (x) )
#define PRINT_HEX(x)          printf("%s: %d: " #x " = 0x%X\n"  , __FUNCTION__, __LINE__, (uint32_t) (x) )

#define PRINT_BUFFER(buf, n) \
  do {\
    uint8_t const* p8 = (uint8_t const*) (buf);\
    printf(#buf ": ");\
    for(uint32_t i=0; i<(n); i++) printf("%x ", p8[i]);\
    printf("\n");\
  }while(0)

#define ADALOG(tag, ...) \
  do { \
    if ( tag ) printf("[%s] ", tag);\
    printf(__VA_ARGS__);\
    printf("\n");\
  }while(0)

#else

#define PRINT_LOCATION()
#define PRINT_MESS(x)
#define PRTNT_HEAP()
#define PRINT_STR(x)
#define PRINT_INT(x)
#define PRINT_HEX(x)
#define PRINT_BUFFER(buf, n)

#define ADALOG(...)

#endif


#endif
