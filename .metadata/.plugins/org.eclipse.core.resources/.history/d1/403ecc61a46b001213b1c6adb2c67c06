#include "FreeRTOS.h"
#include "task.h"


/* IO library includes. */
#include "FreeRTOS_IO.h"
//#include "IOUtils_Common.h"
//#include "FreeRTOS_uart.h"


#include "lpc17xx_pinsel.h"
#include "lpc17xx_gpio.h"

#include "FreeRTOS_lcd.h"


void delay(int count)
{
  int j=0,i=0;

  for(j=0;j<count;j++)
  {
    /* At 60Mhz, the below loop introduces
    delay of 10 us */
    for(i=0;i<35;i++);
  }
}


portBASE_TYPE FreeRTOS_LCD_open( Peripheral_Control_t * const pxPeripheralControl )
{
	portBASE_TYPE xReturn = pdFAIL;


	taskENTER_CRITICAL();


	GPIO_SetDir(2U,(1UL<<7UL),1);/*LCD control Register p2.1=output*/
	GPIO_SetDir(2U,(1UL<<5UL),1);
	GPIO_SetDir(2U,(1UL<<6UL),1);
	GPIO_SetDir(2U,(1UL<<29UL),1);


	GPIO_ClearValue(2U,(1UL<<7UL));
	GPIO_ClearValue(2U,(1UL<<5UL));
	GPIO_ClearValue(2U,(1UL<<6UL));
	GPIO_ClearValue(2U,(1UL<<29UL));

	GPIO_SetDir(0U,(1UL<<19UL),1);
	GPIO_SetDir(0U,(1UL<<20UL),1);
	GPIO_SetDir(0U,(1UL<<21UL),1);
	GPIO_SetDir(0U,(1UL<<22UL),1);


	taskEXIT_CRITICAL();

	pxPeripheralControl->write=FreeRTOS_LCD_write;
	pxPeripheralControl->ioctl=FreeRTOS_LCD_ioctl;
	xReturn=pdPASS;

	return xReturn;
}

portBASE_TYPE FreeRTOS_LCD_ioctl( Peripheral_Descriptor_t const pxPeripheral, uint32_t ulRequest, void *pvValue )
{
	int i;

	unsigned int temp=0;
	unsigned int temp1=0;

	char* val=(char*) pvValue;

	taskENTER_CRITICAL();

		switch(ulRequest)      //implement lcd writing in upper or lower lcd line
		{
			case first_line:
				val[5]=0x80;
				 for(i=0;i<6;i++)
				 {
					  temp=0,temp1=0;
					  temp=val[i];
					  temp=(temp>>4)&0x0F;
					  temp1=(temp<<DATA_POS)&LCD_DATA_MASK;

					  GPIO_ClearValue(2U,(1UL<<5UL));

					  GPIO_SetValue(2U,(1UL<<7UL));

					  GPIO_ClearValue(0U,((1UL<<19UL)|(1UL<<20UL)|(1UL<<21UL)|(1UL<<22UL)));
					  //GPIO_ClearValue(0U,(1UL<<20UL));
					  //GPIO_ClearValue(0U,(1UL<<21UL));
					  //GPIO_ClearValue(0U,(1UL<<22UL));

					  GPIO_SetValue(0U,temp1);

					  GPIO_ClearValue(2U,(1UL<<7UL));

					  temp=val[i];
					  temp&=0x0F;
					  temp1=(temp<<DATA_POS)&LCD_DATA_MASK;
					  delay(DELAY_COUNT);
					  GPIO_ClearValue(2U,(1UL<<5UL));

					  GPIO_SetValue(2U,(1UL<<7UL));

					  GPIO_ClearValue(0U,((1UL<<19UL)|(1UL<<20UL)|(1UL<<21UL)|(1UL<<22UL)));
					  //GPIO_ClearValue(0U,(1UL<<20UL));
					  //GPIO_ClearValue(0U,(1UL<<21UL));
					  //GPIO_ClearValue(0U,(1UL<<22UL));

					  GPIO_SetValue(0U,temp1);

					  GPIO_ClearValue(2U,(1UL<<7UL));
				  }
                   break;
			case second_line:
							val[5]=0xc0;
							 for(i=0;i<6;i++)
							 {
								  temp=0,temp1=0;
								  temp=val[i];
								  temp=(temp>>4)&0x0F;
								  temp1=(temp<<DATA_POS)&LCD_DATA_MASK;

								  GPIO_ClearValue(2U,(1UL<<5UL));

								  GPIO_SetValue(2U,(1UL<<7UL));

								  GPIO_ClearValue(0U,((1UL<<19UL)|(1UL<<20UL)|(1UL<<21UL)|(1UL<<22UL)));
								 // GPIO_ClearValue(0U,(1UL<<20UL));
								  //GPIO_ClearValue(0U,(1UL<<21UL));
								  //GPIO_ClearValue(0U,(1UL<<22UL));

								  GPIO_SetValue(0U,temp1);

								  GPIO_ClearValue(2U,(1UL<<7UL));

								  temp=val[i];
								  temp&=0x0F;
								  temp1=(temp<<DATA_POS)&LCD_DATA_MASK;
								  delay(DELAY_COUNT);
								  GPIO_ClearValue(2U,(1UL<<5UL));

								  GPIO_SetValue(2U,(1UL<<7UL));

								  GPIO_ClearValue(0U,((1UL<<19UL)|(1UL<<20UL)|(1UL<<21UL)|(1UL<<22UL)));
								 // GPIO_ClearValue(0U,(1UL<<20UL));
								  //GPIO_ClearValue(0U,(1UL<<21UL));
								  //GPIO_ClearValue(0U,(1UL<<22UL));

								  GPIO_SetValue(0U,temp1);

								  GPIO_ClearValue(2U,(1UL<<7UL));
							  }
			                   break;


				}

		taskEXIT_CRITICAL();
	}




size_t FreeRTOS_LCD_write( Peripheral_Descriptor_t const pxPeripheral, const void *pvBuffer, const size_t xBytes )
{
	int i;
	unsigned int temp,temp1;
	//char* val=(char*) pvBuffer;
	char val[10]="ravi";
	taskENTER_CRITICAL();
	//GPIO_ClearValue(2U,(1UL<<6UL));
	for(i=0;i<4;i++)
			{
						 // temp=0,temp1=0;
						  temp=val[i];
						  temp=(temp>>4)&0x0F;
						  temp1=(temp<<DATA_POS)&LCD_DATA_MASK;

						  GPIO_SetValue(2U,(1UL<<5UL));

						  GPIO_SetValue(2U,(1UL<<7UL));

						  GPIO_ClearValue(0U,((1UL<<19UL)|(1UL<<20UL)|(1UL<<21UL)|(1UL<<22UL)));
						 // GPIO_ClearValue(0U,(1UL<<20UL));
						  //GPIO_ClearValue(0U,(1UL<<21UL));
						  //GPIO_ClearValue(0U,(1UL<<22UL));

						  GPIO_SetValue(0U,temp1);
						  GPIO_ClearValue(2U,(1UL<<7UL));

						  temp=val[i];
						  temp&=0x0F;
						  temp1=(temp<<DATA_POS)&LCD_DATA_MASK;
						  delay(DELAY_COUNT);
						  GPIO_SetValue(2U,(1UL<<5UL));

						  GPIO_SetValue(2U,(1UL<<7UL));

						  GPIO_ClearValue(0U,((1UL<<19UL)|(1UL<<20UL)|(1UL<<21UL)|(1UL<<22UL)));
						  //GPIO_ClearValue(0U,(1UL<<20UL));
						  //GPIO_ClearValue(0U,(1UL<<21UL));
						  //GPIO_ClearValue(0U,(1UL<<22UL));

						  GPIO_SetValue(0U,temp1);
						  GPIO_ClearValue(2U,(1UL<<7UL));
			}

			taskEXIT_CRITICAL();

	}





