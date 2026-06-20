#include"Motor.h"
void Set_Duty(float duty,uint8_t channel)
{
    uint32_t CompareValue;
    CompareValue=32000-32000*duty;
    if(channel==0)
    {
        DL_TimerA_setCaptureCompareValue(PWM_0_INST,CompareValue,DL_TIMER_CC_0_INDEX);
    }
    else if(channel==1)
    {
        DL_TimerA_setCaptureCompareValue(PWM_0_INST,CompareValue,DL_TIMER_CC_1_INDEX);
    }
}
void Set_Dir(int dir,uint8_t motor)
{
    if(motor==A)
    {
        if(dir==1)
        {
            DL_GPIO_setPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_AIN1_PIN);
            DL_GPIO_clearPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_AIN2_PIN);
        }
        else if(dir==-1)
        {
            DL_GPIO_clearPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_AIN1_PIN);
            DL_GPIO_setPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_AIN2_PIN);
        }
        else if(dir==0)
        {
            DL_GPIO_setPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_AIN1_PIN);
            DL_GPIO_setPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_AIN2_PIN);
        }
    }
    else if(motor==B)
    {
        if(dir==1)
        {
            DL_GPIO_setPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_BIN1_PIN);
            DL_GPIO_clearPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_BIN2_PIN);
        }
        else if(dir==-1)
        {
            DL_GPIO_clearPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_BIN1_PIN);
            DL_GPIO_setPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_BIN2_PIN);
        }
        else if(dir==0)
        {
            DL_GPIO_setPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_BIN1_PIN);
            DL_GPIO_setPins(GPIO_Motor_PORT, GPIO_Motor_PIN_MR_BIN2_PIN);
        }

    }
}