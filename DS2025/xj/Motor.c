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
/*******************************************************
函数功能：计算编码器转速 (RPM) 
入口参数：encoder_count - 编码器计数值
         sample_time_ms - 采样时间间隔(毫秒)
返回  值：转速值(RPM)
说明：基于2倍频解码和13线编码器计算转速，30减速比
***********************************************************/
float Calculate_Motor_RPM(int encoder_count, int sample_time_ms) 
{
	//更换电机需修改此处参数
    const int ENCODER_LINES = 13;        // 编码器线数 (每转13个脉冲)
    const int MULTIPLY_FACTOR = 4;       // 2倍频系数 (只检测上升沿)
    const int GEAR_RATIO = 20;           // 减速比 30:1
    // 计算每转的脉冲数 = 线数 × 倍频系数
    int pulses_per_revolution = ENCODER_LINES * MULTIPLY_FACTOR; // 13 × 2 = 26
    
    // 电机轴转速计算公式：RPM = (脉冲计数 × 60000) / (每转脉冲数 × 采样时间ms)
    // 60000 = 60秒 × 1000毫秒，用于单位转换
    float motor_rpm = (float)encoder_count * 60000.0f / (pulses_per_revolution * sample_time_ms);
    
    return motor_rpm/GEAR_RATIO;//电机转速除以减速比得到输出轴的转速
}