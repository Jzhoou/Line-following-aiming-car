#include"Motor.h"
float Velcity_Kp=2.6f,  Velcity_Ki=1.3f,  Velcity_Kd; //�����ٶ�PID����
void Set_Duty(float duty,uint8_t channel)
{
    uint32_t CompareValue;
    CompareValue=32000-32000*duty;//duty=(32000-ccv)/32000
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
/***************************************************************************
函数功能：电机的PID闭环控制
入口参数：左右电机的编码器值
返回值  ：电机的PWM
***************************************************************************/
int Velocity_A(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;  //定义相关变量
		static int ControlVelocityA, Last_biasA; //静态变量，函数调用结束后其值依然存在
		
		Bias=TargetVelocity-CurrentVelocity; //求速度偏差
		
		ControlVelocityA+=Velcity_Ki*(Bias-Last_biasA)+Velcity_Kp*Bias;  //增量式PI控制器
                                                                   //Velcity_Kp*(Bias-Last_bias) 作用为限制加速度
	                                                                 //Velcity_Ki*Bias             速度控制值由Bias不断积分得到 偏差越大加速度越大
		Last_biasA=Bias;	
	    if(ControlVelocityA>7000) ControlVelocityA=7000;
	    else if(ControlVelocityA<-7000) ControlVelocityA=-7000;
		return ControlVelocityA; //返回速度控制值
}

/***************************************************************************
函数功能：电机的PID闭环控制
入口参数：左右电机的编码器值
返回值  ：电机的PWM
***************************************************************************/
int Velocity_B(int TargetVelocity, int CurrentVelocity)
{  
    int Bias;  //定义相关变量
		static int ControlVelocityB, Last_biasB; //静态变量，函数调用结束后其值依然存在
		
		Bias=TargetVelocity-CurrentVelocity; //求速度偏差
		
		ControlVelocityB+=Velcity_Ki*(Bias-Last_biasB)+Velcity_Kp*Bias;  //增量式PI控制器
                                                                   //Velcity_Kp*(Bias-Last_bias) 作用为限制加速度
	                                                                 //Velcity_Ki*Bias             速度控制值由Bias不断积分得到 偏差越大加速度越大
		Last_biasB=Bias;	
	    if(ControlVelocityB>7000) ControlVelocityB=7000;
	    else if(ControlVelocityB<-7000) ControlVelocityB=-7000;
		return ControlVelocityB; //返回速度控制值
}