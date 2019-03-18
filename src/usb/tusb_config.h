/**************************************************************************/
/*!
    @file     tusb_config.h
    @author   hathach (tinyusb.org)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2013, hathach (tinyusb.org)
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
    INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    This file is part of the tinyusb stack.
*/
/**************************************************************************/

#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

#ifdef __cplusplus
 extern "C" {
#endif

//--------------------------------------------------------------------+
// COMMON CONFIGURATION
//--------------------------------------------------------------------+
#define CFG_TUSB_MCU                OPT_MCU_NRF5X
#define CFG_TUSB_RHPORT0_MODE       OPT_MODE_DEVICE

#ifndef CFG_TUSB_DEBUG
#define CFG_TUSB_DEBUG              0
#endif

/*------------- RTOS -------------*/
#define CFG_TUSB_OS                 OPT_OS_NONE
//#define CFG_TUD_TASK_PRIO         0
//#define CFG_TUD_TASK_QUEUE_SZ     16
//#define CFG_TUD_TASK_STACK_SZ     150


//--------------------------------------------------------------------+
// DEVICE CONFIGURATION
// Note: TUD Stand for Tiny Usb Device
//--------------------------------------------------------------------+

/*------------- Core -------------*/
#define CFG_TUD_DESC_AUTO           0
#define CFG_TUD_ENDOINT0_SIZE       64

//------------- Class enabled -------------//
#define CFG_TUD_CDC                 1
#define CFG_TUD_MSC                 1
#define CFG_TUD_HID_KEYBOARD        0
#define CFG_TUD_HID_MOUSE           0
#define CFG_TUD_HID_GENERIC         0 // not supported yet
#define CFG_TUD_CUSTOM_CLASS        0


/*------------------------------------------------------------------*/
/* CLASS DRIVER
 *------------------------------------------------------------------*/

// FIFO size of CDC TX and RX
#define CFG_TUD_CDC_RX_BUFSIZE      1024
#define CFG_TUD_CDC_TX_BUFSIZE      1024

/* TX is sent automatically on every Start of Frame event ~ 1ms.
 * If not enabled, application must call tud_cdc_flush() periodically
 * Note: Enabled this could overflow device task, if it does, define
 * CFG_TUD_TASK_QUEUE_SZ with large value
 */
#define CFG_TUD_CDC_FLUSH_ON_SOF    0

// Number of supported Logical Unit Number
#define CFG_TUD_MSC_MAXLUN          1

// Buffer size for each read/write transfer, the more the better
#define CFG_TUD_MSC_BUFSIZE         (4*1024)

// Vendor name included in Inquiry response, max 8 bytes
#define CFG_TUD_MSC_VENDOR          "Adafruit"

// Product name included in Inquiry response, max 16 bytes
#define CFG_TUD_MSC_PRODUCT         "Feather nRF52840"

// Product revision string included in Inquiry response, max 4 bytes
#define CFG_TUD_MSC_PRODUCT_REV     "1.0"


//--------------------------------------------------------------------+
// USB RAM PLACEMENT
//--------------------------------------------------------------------+
#define CFG_TUSB_ATTR_USBRAM
#define CFG_TUSB_MEM_ALIGN          ATTR_ALIGNED(4)


#define BREAKPOINT_IGNORE_COUNT(n) \
  do {\
    static uint8_t ignore_count = 0;\
    ignore_count++;\
    if ( ignore_count > n ) verify_breakpoint();\
  }while(0)

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_CONFIG_H_ */
