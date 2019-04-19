#include "files/uart.h"
#include "files/delay.h"
#include "files/spi.h"
#include "files/fsm.h"

uint8_t ui8_duty_cycle;
int8_t i8_distance;
uint8_t ui8_command;

uint32_t ui32_delay_ms = 10;

int32_t main(void);

int32_t
main(void)
{
    uart_init();
    spi_init();

    while(1)
    {
        /* receive msg from sensor */
        ui8_duty_cycle = uart_receive();

        /* calculate distance */
        i8_distance = calc_distance(ui8_duty_cycle);

        /* compute command */
        ui8_command = compute_cmd(i8_distance);

        /* send distance and command over spi */
        spi_send(i8_distance, ui8_command);
        delay_msec(ui32_delay_ms);
    }
}
