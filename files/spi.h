#ifndef __SPI_H__
#define __SPI_H__

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/ssi.h"
#include "driverlib/sysctl.h"

#define NUM_SSI_DATA            2

int32_t pi32DataTx[NUM_SSI_DATA];
uint32_t ui32Index;

void spi_init(void);
void spi_send(uint8_t ui8_send_char, uint8_t ui8_command);

#endif /* __SPI_H__ */
