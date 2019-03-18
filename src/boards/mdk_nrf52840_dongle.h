/**************************************************************************/
/*!
    @file     mdk_nrf52840_dongle.h
    @author   gpshead (krypto.org)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2019, Adafruit Industries (adafruit.com)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/

#ifndef _MDK_NRF52840_DONGLE_H_
#define _MDK_NRF52840_DONGLE_H_

#define _PINNUM(port, pin)    ((port)*32 + (pin))

/*------------------------------------------------------------------*/
/* LED
 *------------------------------------------------------------------*/
#define LEDS_NUMBER           2  // TODO(gpshead): support 0.
#define LED_PRIMARY_PIN       _PINNUM(0, 23)  // Red
#define LED_SECONDARY_PIN     _PINNUM(0, 24)  // Blue
#define LED_STATE_ON          0

//#define LED_RGB_RED_PIN       _PINNUM(0, 23)
//#define LED_RGB_GREEN_PIN     _PINNUM(0, 22)
//#define LED_RGB_BLUE_PIN      _PINNUM(0, 24)
#define BOARD_RGB_BRIGHTNESS  0x404040
/*------------------------------------------------------------------*/
/* BUTTON
 *------------------------------------------------------------------*/
// TODO(gpshead): simplify, have code support 0.  double reset only.
#define BUTTONS_NUMBER        2  // none connected at all
#define BUTTON_1              _PINNUM(0, 18)  // unusable: RESET
#define BUTTON_2              _PINNUM(0, 19)  // no connection
#define BUTTON_PULL           NRF_GPIO_PIN_PULLUP

// Used as model string in OTA mode
#define DIS_MANUFACTURER      "MakerDiary"
#define DIS_MODEL             "nRF52840 Micro Dev Kit USB Dongle"

#define PRODUCT_NAME          "MDK nRF52840 USB Dongle"
#define VOLUME_LABEL          "MDK840DONGL"

#define BOARD_ID "MakerDiary-nRF52840-USB-Dongle"

#define INDEX_URL "https://wiki.makerdiary.com/nrf52840-mdk-usb-dongle/"

#endif /* _MDK_NRF52840_DONGLE_H_ */
