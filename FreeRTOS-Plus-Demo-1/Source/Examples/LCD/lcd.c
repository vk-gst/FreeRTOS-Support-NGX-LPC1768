#include "string.h"






/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "FreeRTOS_IO.h"

#include "FreeRTOS_lcd.h"

static void lcd_task(void *pvParameters);

xTaskHandle xlcdtask=NULL;

void lcd_task_start(void)
{

	xTaskCreate( 	lcd_task,
						( const int8_t * const ) "LCD",
						configLCD_TASK_STACK_SIZE,
						NULL,
						configLCD_TASK_PRIORITY,
						&xlcdtask );
}

static void lcd_task(void *pvParameters)
{

	Peripheral_Descriptor_t xLCD=0;
	char cmd[10]={0x28,0x01,0x02,0x06,0x0c};

	char line_1_buffer[15]="writing in eeprom";
	char line_2_buffer[15]="readin from eeprom";

	xLCD = FreeRTOS_open( boardLCD,0);

	configASSERT( xLCD );

	FreeRTOS_ioctl( xLCD,first_line,cmd );

	 FreeRTOS_write( xLCD, line_1_buffer, sizeof(line_1_buffer));

	 FreeRTOS_ioctl( xLCD,second_line,cmd );

	 FreeRTOS_write( xLCD, line_2_buffer, sizeof(line_2_buffer));
while(1);

}
