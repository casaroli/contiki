/*
 * Copyright (c) 2015, Texas Instruments Incorporated - http://www.ti.com/
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
/*---------------------------------------------------------------------------*/
/** \addtogroup launchpad-peripherals
 * @{
 *
 * \defgroup launchpad-cc26xx-specific CC2650 LaunchPad Peripherals
 *
 * Defines related to the CC2650 LaunchPad
 *
 * This file provides connectivity information on LEDs, Buttons, UART and
 * other peripherals
 *
 * This file is not meant to be modified by the user.
 * @{
 *
 * \file
 * Header file with definitions related to the I/O connections on the TI
 * CC2650 LaunchPad
 *
 * \note   Do not include this file directly. It gets included by contiki-conf
 *         after all relevant directives have been set.
 */
/*---------------------------------------------------------------------------*/
#ifndef BOARD_H_
#define BOARD_H_
/*---------------------------------------------------------------------------*/
#include "ioc.h"
/*---------------------------------------------------------------------------*/
/**
 * \name LED configurations
 *
 * Those values are not meant to be modified by the user
 * @{
 */
/* Some files include leds.h before us, so we need to get rid of defaults in
 * leds.h before we provide correct definitions */
#undef LEDS_RED
#undef LEDS_CONF_ALL

#define LEDS_RED       1
#define LEDS_GREEN     LEDS_RED
#define LEDS_ORANGE    LEDS_RED

#define LEDS_CONF_ALL  1

/* Notify various examples that we have LEDs */
#define PLATFORM_HAS_LEDS        1
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name LED IOID mappings
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_LED_1          IOID_2
#define BOARD_LED_1               (1 << BOARD_IOID_LED_1)
#define BOARD_LED_ALL             (BOARD_LED_1)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name UART IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_UART_RX        IOID_1
#define BOARD_IOID_UART_TX        IOID_0
#define BOARD_IOID_UART_RTS       IOID_UNUSED
#define BOARD_IOID_UART_CTS       IOID_UNUSED
#define BOARD_UART_RX             (1 << BOARD_IOID_UART_RX)
#define BOARD_UART_TX             (1 << BOARD_IOID_UART_TX)
//#define BOARD_UART_RTS            (1 << BOARD_IOID_UART_RTS)
//#define BOARD_UART_CTS            (1 << BOARD_IOID_UART_CTS)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Button IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
//#define BOARD_IOID_KEY_LEFT       IOID_13
#define BOARD_IOID_KEY_RIGHT      IOID_5
//#define BOARD_KEY_LEFT            (1 << BOARD_IOID_KEY_LEFT)
#define BOARD_KEY_RIGHT           (1 << BOARD_IOID_KEY_RIGHT)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief SPI IOID mappings
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_SPI_MOSI       IOID_12
#define BOARD_IOID_SPI_MISO       IOID_14
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name External flash IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_FLASH_CS       IOID_13
#define BOARD_FLASH_CS            (1 << BOARD_IOID_FLASH_CS)
#define BOARD_IOID_SPI_CLK_FLASH  IOID_11
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief ROM bootloader configuration
 *
 * Change SET_CCFG_BL_CONFIG_BL_PIN_NUMBER to BOARD_IOID_KEY_xyz to select
 * which button triggers the bootloader on reset.
 *
 * The remaining values are not meant to be modified by the user
 * @{
 */
#if ROM_BOOTLOADER_ENABLE
#define SET_CCFG_BL_CONFIG_BOOTLOADER_ENABLE            0xC5
#define SET_CCFG_BL_CONFIG_BL_LEVEL                     0x00
#define SET_CCFG_BL_CONFIG_BL_PIN_NUMBER                BOARD_IOID_KEY_RIGHT
#define SET_CCFG_BL_CONFIG_BL_ENABLE                    0xC5
#else
#define SET_CCFG_BL_CONFIG_BOOTLOADER_ENABLE            0x00
#define SET_CCFG_BL_CONFIG_BL_LEVEL                     0x01
#define SET_CCFG_BL_CONFIG_BL_PIN_NUMBER                0xFF
#define SET_CCFG_BL_CONFIG_BL_ENABLE                    0xFF
#endif
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief Remaining pins
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_DIO0           IOID_0
#define BOARD_IOID_DIO1           IOID_1
#define BOARD_IOID_DIO2           IOID_2
#define BOARD_IOID_DIO3           IOID_3
#define BOARD_IOID_DIO4           IOID_4
#define BOARD_IOID_DIO5           IOID_5
#define BOARD_IOID_DIO6           IOID_6
#define BOARD_IOID_DIO7           IOID_7
#define BOARD_IOID_DIO8           IOID_8
#define BOARD_IOID_DIO9           IOID_9
#define BOARD_IOID_DI10           IOID_10
#define BOARD_IOID_DI11           IOID_11
#define BOARD_IOID_DI12           IOID_12
#define BOARD_IOID_DI13           IOID_13
#define BOARD_IOID_DI14           IOID_14

#define BOARD_UNUSED_PINS { \
    BOARD_IOID_DIO3, BOARD_IOID_DIO4, BOARD_IOID_DIO5, BOARD_IOID_DIO6, \
    BOARD_IOID_DIO7, BOARD_IOID_DIO8, BOARD_IOID_DIO9, BOARD_IOID_DI10, \
    IOID_UNUSED \
  }
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Device string used on startup
 * @{
 */
#define BOARD_STRING "momote001/CC2650"

/** @} */
/*---------------------------------------------------------------------------*/
#endif /* BOARD_H_ */
/*---------------------------------------------------------------------------*/
/**
 * @}
 * @}
 */
