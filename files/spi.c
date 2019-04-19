#include "spi.h"

void
spi_init(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA2_SSI0CLK);
    GPIOPinConfigure(GPIO_PA3_SSI0FSS);
    GPIOPinConfigure(GPIO_PA4_SSI0RX);
    GPIOPinConfigure(GPIO_PA5_SSI0TX);

    GPIOPinTypeSSI(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_3|GPIO_PIN_2);

    SSIConfigSetExpClk(SSI0_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0, SSI_MODE_MASTER, 1000000, 8);
    SSIEnable(SSI0_BASE);
}

void
spi_send(uint8_t ui8_send_char, uint8_t ui8_command)
{
    pi32DataTx[0] = ui8_command;
    pi32DataTx[1] = ui8_send_char;

    for(ui32Index = 0; ui32Index < NUM_SSI_DATA; ui32Index++)
    {
        SSIDataPut(SSI0_BASE, pi32DataTx[ui32Index]);
    }

    while(SSIBusy(SSI0_BASE));
}
