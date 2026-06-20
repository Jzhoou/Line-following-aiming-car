#ifndef _MOTOR_H
#define _MOTOR_H
#include "ti_msp_dl_config.h"
enum{
    A,B
};
void Set_Duty(float duty,uint8_t channel);
void Set_Dir(int dir,uint8_t motor);
int Velocity_A(int TargetVelocity, int CurrentVelocity);
int Velocity_B(int TargetVelocity, int CurrentVelocity);

#endif