#define DATA_POS 19
#define DELAY_COUNT 100

#include "portmacro.h"
#include "FreeRTOS_DriverInterface.h"

#define first_line 1
#define second_line 2
#define LCD_D4 (1 << 19)
#define LCD_D5 (1 << 20)
#define LCD_D6 (1 << 21)
#define LCD_D7 (1 << 22)

#define LCD_DATA_MASK           (LCD_D4 | LCD_D5 | LCD_D6 | LCD_D7)
void delay(int);

portBASE_TYPE FreeRTOS_LCD_open( Peripheral_Control_t *const pxPeripheralControl );
portBASE_TYPE FreeRTOS_LCD_ioctl( Peripheral_Descriptor_t const pxPeripheral, uint32_t ulRequest, void *pvValue );
size_t FreeRTOS_LCD_write( Peripheral_Descriptor_t const pxPeripheral, const void *pvBuffer, const size_t xBytes );

void lcd_task_start(void);
