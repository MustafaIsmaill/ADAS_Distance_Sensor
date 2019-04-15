#ifndef __DELAY_H__
#define __DELAY_H__

#include <stdbool.h>
#include <stdint.h>
#include "driverlib/sysctl.h"

void delay_msec(uint32_t ms);
void delay_one_sec(void);

#endif /* __DELAY_H__ */
