#include "files/uart.h"
#include "files/delay.h"

uint8_t ui8_msg;
uint32_t ui32_delay_ms = 10;

int32_t main(void);

int32_t
main(void)
{
    uart_init();

    while(1)
    {
        ui8_msg = uart_receive();
        uart_send(ui8_msg);
        delay_msec(ui32_delay_ms);
    }
}
