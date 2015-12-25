/*
 * FreeRTOS+IO V1.0.0 (C) 2012 Real Time Engineers ltd.
 *
 * FreeRTOS+IO is an add-on component to FreeRTOS.  It is not, in itself, part
 * of the FreeRTOS kernel.  FreeRTOS+IO is licensed separately from FreeRTOS,
 * and uses a different license to FreeRTOS.  FreeRTOS+IO uses a dual license
 * model, information on which is provided below:
 *
 * - Open source licensing -
 * FreeRTOS+IO is a free download and may be used, modified and distributed
 * without charge provided the user adheres to version two of the GNU General
 * Public license (GPL) and does not remove the copyright notice or this text.
 * The GPL V2 text is available on the gnu.org web site, and on the following
 * URL: http://www.FreeRTOS.org/gpl-2.0.txt
 *
 * - Commercial licensing -
 * Businesses and individuals who wish to incorporate FreeRTOS+IO into
 * proprietary software for redistribution in any form must first obtain a low
 * cost commercial license - and in-so-doing support the maintenance, support
 * and further development of the FreeRTOS+IO product.  Commercial licenses can
 * be obtained from http://shop.freertos.org and do not require any source files
 * to be changed.
 *
 * FreeRTOS+IO is distributed in the hope that it will be useful.  You cannot
 * use FreeRTOS+IO unless you agree that you use the software 'as is'.
 * FreeRTOS+IO is provided WITHOUT ANY WARRANTY; without even the implied
 * warranties of NON-INFRINGEMENT, MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. Real Time Engineers Ltd. disclaims all conditions and terms, be they
 * implied, expressed, or statutory.
 *
 * 1 tab == 4 spaces!
 *
 * http://www.FreeRTOS.org
 * http://www.FreeRTOS.org/FreeRTOS-Plus
 *
 */

#ifndef LPCXPRESSO_BASE_BOARD_H
#define LPCXPRESSO_BASE_BOARD_H

/* Header files for all the driver libraries that can be used with this BSP. */
#include "lpc17xx_uart.h"
#include "lpc17xx_i2c.h"

/*******************************************************************************
 * Definitions used by FreeRTOS+IO to determine the peripherals that are
 * available on the board, and the functions used to interface with the target
 * specific peripheral drivers.
 ******************************************************************************/

/*******************************************************************************
 * Definitions used by the UART-interrupt-driven-command-console.c example file.
 *
 * See http://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_IO/Board_Support_Packages.shtml
 *
 ******************************************************************************/
#define boardAVAILABLE_DEVICES_LIST												\
{																				\
	{ ( const int8_t * const ) "/UART3/", eUART_TYPE, ( void * ) LPC_UART3 },	\
	{ ( const int8_t * const ) "/I2C0/", eI2C_TYPE, ( void * ) LPC_I2C0 },		\
	{ ( const int8_t * const ) "/UART1/", eUART_TYPE, ( void * ) LPC_UART1 },	\
	{ ( const int8_t * const ) "/LCD/", eLCD_TYPE, ( void * )0}					\
}

/*******************************************************************************
 * Map the FreeRTOS+IO interface to the LPC17xx specific functions.
 ******************************************************************************/
portBASE_TYPE vFreeRTOS_lpc17xx_PopulateFunctionPointers( const Peripheral_Types_t ePeripheralType, Peripheral_Control_t * const pxPeripheralControl );
#define boardFreeRTOS_PopulateFunctionPointers vFreeRTOS_lpc17xx_PopulateFunctionPointers

/*******************************************************************************
 * These define the number of peripherals available on the microcontroller -
 * not the number of peripherals that are supported by the software
 ******************************************************************************/
#define boardNUM_SSPS				2 /* SSP0 to SSP1. */
#define boardNUM_UARTS				4 /* UART0 to UART3. */
#define boardNUM_I2CS				3 /* I2C0 to I2C2. */


/*******************************************************************************
 * Configure port UART port pins to be correct for the wiring of the
 * LPCXpresso base board.
 ******************************************************************************/
#define boardCONFIGURE_UART_PINS( cPeripheralNumber, xPinConfig )					\
	switch( ( cPeripheralNumber ) )													\
	{																				\
		case 3	:	( xPinConfig ).Funcnum = 2;										\
					( xPinConfig ).Pinnum = 0;										\
					( xPinConfig ).Portnum = 0;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					( xPinConfig ).Pinnum = 1;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					break;															\
		case 1 :	( xPinConfig ).Funcnum = 1;										\
					( xPinConfig ).Pinnum = 15;										\
					( xPinConfig ).Portnum = 0;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					( xPinConfig ).Pinnum = 16;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					break;															\
																					\
		default	:	/* These are either not implemented yet, or not available		\
					on this board.  Force an assert failure. */						\
					configASSERT( ( cPeripheralNumber ) - ( cPeripheralNumber ) );	\
					break;															\
	}


 //* Configure port ENET port pins to be correct for the wiring of the
 //* LPCXpresso base board.
 /******************************************************************************/
#define boardCONFIGURE_ENET_PINS( xPinConfig )		\
	( xPinConfig ).Funcnum = 1;						\
	( xPinConfig ).OpenDrain = 0;					\
	( xPinConfig ).Pinmode = 0;						\
	( xPinConfig ).Portnum = 1;						\
	( xPinConfig ).Pinnum = 0;						\
	PINSEL_ConfigPin( &( xPinConfig ) );			\
	( xPinConfig ).Pinnum = 1;						\
	PINSEL_ConfigPin( &( xPinConfig ) );			\
	( xPinConfig ).Pinnum = 4;						\
	PINSEL_ConfigPin( &( xPinConfig ) );			\
	( xPinConfig ).Pinnum = 8;						\
	PINSEL_ConfigPin( &( xPinConfig ) );			\
	( xPinConfig ).Pinnum = 9;						\
	PINSEL_ConfigPin( &( xPinConfig ) );			\
	( xPinConfig ).Pinnum = 10;						\
	PINSEL_ConfigPin( &( xPinConfig ) );			\
	( xPinConfig ).Pinnum = 14;						\
	PINSEL_ConfigPin( &( xPinConfig ) );			\
	( xPinConfig ).Pinnum = 15;						\
	PINSEL_ConfigPin( &( xPinConfig ) );			\
	( xPinConfig ).Pinnum = 16;						\
	PINSEL_ConfigPin( &( xPinConfig ) );			\
	( xPinConfig ).Pinnum = 17;						\
	PINSEL_ConfigPin( &( xPinConfig ) )

/*******************************************************************************
 * Configure port I2C port pins to be correct for the wiring of the
 * LPCXpresso base board.
 ******************************************************************************/
#define boardCONFIGURE_I2C_PINS( cPeripheralNumber, xPinConfig )					\
	switch( ( cPeripheralNumber ) )													\
	{																				\
		case 0	:	( xPinConfig ).Funcnum = 1;										\
					( xPinConfig ).Pinnum = 27;										\
					( xPinConfig ).Portnum = 0;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					( xPinConfig ).Pinnum = 28;										\
					PINSEL_ConfigPin( &( xPinConfig ) );							\
					break;															\
																					\
		default	:	/* These are either not implemented yet, or not available		\
					on this board.  Force an assert failure. */						\
					configASSERT( ( cPeripheralNumber ) - ( cPeripheralNumber ) );	\
					break;															\
	}

/*******************************************************************************
 * Set the default baud rate used by a UART.
 ******************************************************************************/
#define boardDEFAULT_UART_BAUD		115200

/*******************************************************************************
 * Command console definitions.
 ******************************************************************************/
#define boardCOMMAND_CONSOLE_UART	( const int8_t * const ) "/UART3/"
/*----------------------------MY UART-----------------------------------------*/
#define boardMY_UART ( const int8_t * const) "/UART1/"

/*******************************************************************************
 * GPIO/LED polarities
 ******************************************************************************/
#define boardGPIO_OUTPUT			( 1 )
#define boardGPIO_INPUT				( 0 )
#define boardLED_ON					( 1 )
#define boardLED_OFF				( 0 )


/*******************************************************************************
 * PHY ID
 *
 * NOTE!!! This is here for information only.  The ID is hard coded into the
 * NXP driver, so changing this has no effect.  Search for the text boardPHY_ID
 * in lpc17xx_emac.c to see where the value is coded.
 ******************************************************************************/
#define boardPHY_ID 0x0007C0F0UL /* LAN8720_ID */


/*******************************************************************************
 * EEPROM I2C port connections/configuration
 ******************************************************************************/
#define boardDEFAULT_I2C_SPEED					( 100000UL )

#define boardI2C_MAX_RETRANSMISSIONS			( 3UL )
#define boardEEPROM_I2C_PORT					( const int8_t * const ) "/I2C0/"

/*******************************************************************************
 * Definitions used if the generic software timer LED code is included in the build.
 ******************************************************************************/
#define boardSOFTWARE_TIMER_LED_PORT_INITIALISER	{ 2, 0 } /* The third LED output is also on port 2. */
#define boardSOFTWARE_TIMER_LED_INITIALISER			{ 1, ( 1 << 26 ) } /* The third LED output is on bit ( 1 << 1 ). */
#define boardNUM_SOFTWARE_TIMER_LEDS				( 2 ) /* The third is not used as it conflicts with the OLED power. */

#define boardLCD	( const int8_t * const ) "/LCD/"


#endif /* LPCXPRESSO_BASE_BOARD_H */




