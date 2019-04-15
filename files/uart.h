#ifndef __UART_H__
#define __UART_H__

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

void uart_init(void);
uint8_t uart_receive(void);
void uart_send(uint8_t ui8_send_char);

uint8_t ui8_rec_char;

#endif /* __UART_H__ */
