
<!-- saved from url=(0105)https://raw.github.com/arduino/Arduino/master/hardware/arduino/bootloaders/caterina-LilyPadUSB/Caterina.h -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8"></head><body><pre style="word-wrap: break-word; white-space: pre-wrap;">/*
             LUFA Library
     Copyright (C) Dean Camera, 2011.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2011  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for BootloaderCDC.c.
 */

#ifndef _CDC_H_
#define _CDC_H_

	/* Includes: */
		#include &lt;avr/io.h&gt;
		#include &lt;avr/wdt.h&gt;
		#include &lt;avr/boot.h&gt;
		#include &lt;avr/eeprom.h&gt;
		#include &lt;avr/power.h&gt;
		#include &lt;avr/interrupt.h&gt;
		#include &lt;stdbool.h&gt;

		#include "Descriptors.h"

		#include &lt;LUFA/Drivers/USB/USB.h&gt;
	/* Macros: */
		/** Version major of the CDC bootloader. */
		#define BOOTLOADER_VERSION_MAJOR     0x01

		/** Version minor of the CDC bootloader. */
		#define BOOTLOADER_VERSION_MINOR     0x00

		/** Hardware version major of the CDC bootloader. */
		#define BOOTLOADER_HWVERSION_MAJOR   0x01

		/** Hardware version minor of the CDC bootloader. */
		#define BOOTLOADER_HWVERSION_MINOR   0x00

		/** Eight character bootloader firmware identifier reported to the host when requested */
		#define SOFTWARE_IDENTIFIER          "CATERINA"
		
		#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))
		#define LED_SETUP()		DDRC |= (1&lt;&lt;7); DDRB |= (1&lt;&lt;0); DDRD |= (1&lt;&lt;5);
		#define L_LED_OFF()		PORTC &amp;= ~(1&lt;&lt;7)
		#define L_LED_ON()		PORTC |= (1&lt;&lt;7)
		#define L_LED_TOGGLE()	PORTC ^= (1&lt;&lt;7)
		#define TX_LED_OFF()	PORTD |= (1&lt;&lt;5)
		#define TX_LED_ON()		PORTD &amp;= ~(1&lt;&lt;5)
		#define RX_LED_OFF()	PORTB |= (1&lt;&lt;0)
		#define RX_LED_ON()		PORTB &amp;= ~(1&lt;&lt;0)

	/* Type Defines: */
		/** Type define for a non-returning pointer to the start of the loaded application in flash memory. */
		typedef void (*AppPtr_t)(void) ATTR_NO_RETURN;

	/* Function Prototypes: */
		void StartSketch(void);
		void LEDPulse(void);
	
		void CDC_Task(void);
		void SetupHardware(void);

		void EVENT_USB_Device_ConfigurationChanged(void);

		#if defined(INCLUDE_FROM_CATERINA_C) || defined(__DOXYGEN__)
			#if !defined(NO_BLOCK_SUPPORT)
			static void    ReadWriteMemoryBlock(const uint8_t Command);
			#endif
			static uint8_t FetchNextCommandByte(void);
			static void    WriteNextResponseByte(const uint8_t Response);
		#endif

#endif

</pre></body></html>