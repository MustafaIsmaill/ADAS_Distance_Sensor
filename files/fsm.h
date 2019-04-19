#ifndef __FSM_H__
#define __FSM_H__

#include <stdbool.h>
#include <stdint.h>
#include <math.h>

enum state {error = 'E', fire = 'F', brake = 'B', decrease = 'D', maintain = 'M'};

int8_t calc_distance(uint8_t ui8_duty_cycle);
uint8_t compute_cmd(int8_t ui8_distance);

#endif /* __FSM_H__ */
