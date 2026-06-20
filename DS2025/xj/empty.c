
#include "ti_msp_dl_config.h"
#include"Motor.h"

int x1,x2,x3,x4,x5,x6,x7,x8,quan;
int turn_flag,count_corner;
int run=0;
int32_t encoderA_cnt,PWMA,encoderB_cnt,PWMB;
float MA_RPM=0,MB_RPM=0;
volatile unsigned int delay_times = 0;
uint32_t gpio_interrup1,gpio_interrup2;
int Get_Encoder_countA,Get_Encoder_countB;

//搭配滴答定时器实现的精确ms延时
void delay_ms(unsigned int ms)
{
    delay_times = ms;
    while( delay_times != 0 );
}

int main(void)
{
    SYSCFG_DL_init();
//    NVIC_ClearPendingIRQ(GPIO_MULTIPLE_GPIOB_INT_IRQN);
 //   NVIC_ClearPendingIRQ(GPIO_MULTIPLE_GPIOA_INT_IRQN);
    NVIC_EnableIRQ(GPIO_GRP_Switch_GPIOB_INT_IRQN);
    NVIC_EnableIRQ(GPIO_GRP_Switch_GPIOA_INT_IRQN);
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    DL_TimerA_startCounter(TIMER_0_INST);
    DL_TimerG_startCounter(PWM_0_INST);



//	NVIC_ClearPendingIRQ(TIMER_0_INST_INT_IRQN);
//	NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);


    while (1) {

        while(!run)
        {
            if(quan==0)
            {
                DL_GPIO_setPins(GPIO_GRP_LED_PIN_LED1_PORT,GPIO_GRP_LED_PIN_LED1_PIN);
                DL_GPIO_setPins(GPIO_GRP_LED_PIN_LED2_PORT,GPIO_GRP_LED_PIN_LED2_PIN);
                DL_GPIO_setPins(GPIO_GRP_LED_PIN_LED3_PORT,GPIO_GRP_LED_PIN_LED3_PIN);
            }
            else if(quan==1)
            {
                DL_GPIO_clearPins(GPIO_GRP_LED_PIN_LED1_PORT,GPIO_GRP_LED_PIN_LED1_PIN);
                DL_GPIO_setPins(GPIO_GRP_LED_PIN_LED2_PORT,GPIO_GRP_LED_PIN_LED2_PIN);
                DL_GPIO_setPins(GPIO_GRP_LED_PIN_LED3_PORT,GPIO_GRP_LED_PIN_LED3_PIN);
            }
            else if(quan==2)
            {
                DL_GPIO_setPins(GPIO_GRP_LED_PIN_LED1_PORT,GPIO_GRP_LED_PIN_LED1_PIN);
                DL_GPIO_clearPins(GPIO_GRP_LED_PIN_LED2_PORT,GPIO_GRP_LED_PIN_LED2_PIN);
                DL_GPIO_setPins(GPIO_GRP_LED_PIN_LED3_PORT,GPIO_GRP_LED_PIN_LED3_PIN);
            }
            else if(quan==3)
            {
                DL_GPIO_clearPins(GPIO_GRP_LED_PIN_LED1_PORT,GPIO_GRP_LED_PIN_LED1_PIN);
                DL_GPIO_clearPins(GPIO_GRP_LED_PIN_LED2_PORT,GPIO_GRP_LED_PIN_LED2_PIN);
                DL_GPIO_setPins(GPIO_GRP_LED_PIN_LED3_PORT,GPIO_GRP_LED_PIN_LED3_PIN);
            }
            else if(quan==4)
            {
                DL_GPIO_setPins(GPIO_GRP_LED_PIN_LED1_PORT,GPIO_GRP_LED_PIN_LED1_PIN);
                DL_GPIO_setPins(GPIO_GRP_LED_PIN_LED2_PORT,GPIO_GRP_LED_PIN_LED2_PIN);
                DL_GPIO_clearPins(GPIO_GRP_LED_PIN_LED3_PORT,GPIO_GRP_LED_PIN_LED3_PIN);
            }
            else if(quan==5)
            {
                DL_GPIO_clearPins(GPIO_GRP_LED_PIN_LED1_PORT,GPIO_GRP_LED_PIN_LED1_PIN);
                DL_GPIO_setPins(GPIO_GRP_LED_PIN_LED2_PORT,GPIO_GRP_LED_PIN_LED2_PIN);
                DL_GPIO_clearPins(GPIO_GRP_LED_PIN_LED3_PORT,GPIO_GRP_LED_PIN_LED3_PIN);
            }
        }
        if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 1&&x5 == 1&&x6 == 0&&x7 == 0&&x8 == 0)  //go
        {
            Set_Duty(0.5,0);//L
            Set_Duty(0.5,1);
            Set_Dir(1,A);//L
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 1&&x5 == 0&&x6 == 0&&x7 == 0&&x8 == 0) //TR 00010000
        {
            Set_Duty(0.5,0);
            Set_Duty(0.45,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 0&&x5 == 1&&x6 == 0&&x7 == 0&&x8 == 0)  //TL 00001000
        {
            Set_Duty(0.45,0);
            Set_Duty(0.5,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 1&&x4 == 1&&x5 == 0&&x6 == 0&&x7 == 0&&x8 == 0)  //TR 00110000
        {
            Set_Duty(0.5,0);
            Set_Duty(0.4,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 0&&x5 == 1&&x6 == 1&&x7 == 0&&x8 == 0)  //TL 00001100
        {
            Set_Duty(0.4,0);
            Set_Duty(0.5,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 1&&x4 == 0&&x5 == 0&&x6 == 0&&x7 == 0&&x8 == 0)  //TR 00100000
        {
            Set_Duty(0.5,0);
            Set_Duty(0.35,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 0&&x5 == 0&&x6 == 1&&x7 == 0&&x8 == 0)  //TL 00000100
        {
            Set_Duty(0.35,0);
            Set_Duty(0.5,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 1&&x3 == 1&&x4 == 0&&x5 == 0&&x6 == 0&&x7 == 0&&x8 == 0)  //TR 01100000
        {
            Set_Duty(0.5,0);
            Set_Duty(0.3,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 0&&x5 == 0&&x6 == 1&&x7 == 1&&x8 == 0)  //TL 00000110
        {
            Set_Duty(0.3,0);
            Set_Duty(0.5,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 1&&x3 == 0&&x4 == 0&&x5 == 0&&x6 == 0&&x7 == 0&&x8 == 0) //TR 01000000
        {
            Set_Duty(0.5,0);
            Set_Duty(0.25,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 0&&x5 == 0&&x6 == 0&&x7 == 1&&x8 == 0)  //TL 00000010
        {
            Set_Duty(0.25,0);
            Set_Duty(0.5,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 1&&x2 == 1&&x3 == 0&&x4 == 0&&x5 == 0&&x6 == 0&&x7 == 0&&x8 == 0)  //TR 11000000
        {
            Set_Duty(0.5,0);
            Set_Duty(0.2,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 0&&x5 == 0&&x6 == 0&&x7 == 1&&x8 == 1) //TL 00000011
        {
            Set_Duty(0.2,0);
            Set_Duty(0.5,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 1&&x2 == 0&&x3 == 0&&x4 == 0&&x5 == 0&&x6 == 0&&x7 == 0&&x8 == 0)  //TR 10000000
        {
            Set_Duty(0.5,0);
            Set_Duty(0.15,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 0&&x5 == 0&&x6 == 0&&x7 == 0&&x8 == 1)  //TL 00000001
        {
            Set_Duty(0.15,0);
            Set_Duty(0.5,1);
            Set_Dir(1,A);
            Set_Dir(1,B);
            turn_flag=0;
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else if(x1 == 1&&x2 == 1&&x3 == 1&&x4 == 1&&x5 == 1&&x6 == 1&&x7 == 1&&x8 == 0)  //11111110
        {
            Set_Duty(0.3,0);
            Set_Duty(0.1,1);
            Set_Dir(1,A);
            Set_Dir(-1,B);
            turn_flag=1;
        }
        else if(x1 == 0&&x2 == 1&&x3 == 1&&x4 == 1&&x5 == 1&&x6 == 1&&x7 == 1&&x8 == 1)  //01111111
        {
            Set_Duty(0.1,0);
            Set_Duty(0.3,1);
            Set_Dir(-1,A);
            Set_Dir(1,B);
            turn_flag=1;
        }
        else if(x1 == 1&&x2 == 1&&x3 == 1&&x4 == 1&&x5 == 1&&x6 == 1&&x7 == 0&&x8 == 0)  //11111100
        {
            Set_Duty(0.3,0);
            Set_Duty(0.1,1);
            Set_Dir(1,A);
            Set_Dir(-1,B);
            turn_flag=1;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 1&&x4 == 1&&x5 == 1&&x6 == 1&&x7 == 1&&x8 == 1)  //00111111
        {
            Set_Duty(0.1,0);
            Set_Duty(0.3,1);
            Set_Dir(-1,A);
            Set_Dir(1,B);
            turn_flag=1;
        }
        else if(x1 == 1&&x2 == 1&&x3 == 1&&x4 == 1&&x5 == 1&&x6 == 0&&x7 == 0&&x8 == 0)  //11111000
        {
            Set_Duty(0.3,0);
            Set_Duty(0.1,1);
            Set_Dir(1,A);
            Set_Dir(-1,B);
            turn_flag=1;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 1&&x5 == 1&&x6 == 1&&x7 == 1&&x8 == 1)  //00011111
        {
            Set_Duty(0.1,0);
            Set_Duty(0.3,1);
            Set_Dir(-1,A);
            Set_Dir(1,B);
            turn_flag=1;
        }
        else if(x1 == 1&&x2 == 1&&x3 == 1&&x4 == 1&&x5 == 0&&x6 == 0&&x7 == 0&&x8 == 0)  //11110000
        {
            Set_Duty(0.3,0);
            Set_Duty(0.1,1);
            Set_Dir(1,A);
            Set_Dir(-1,B);
            turn_flag=1;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 0&&x5 == 1&&x6 == 1&&x7 == 1&&x8 == 1)  //00001111
        {
            Set_Duty(0.1,0);
            Set_Duty(0.3,1);
            Set_Dir(-1,A);
            Set_Dir(1,B);
            turn_flag=1;
        }
        else if(x1 == 1&&x2 == 1&&x3 == 1&&x4 == 0&&x5 == 0&&x6 == 0&&x7 == 0&&x8 == 0)  //11100000
        {
            Set_Duty(0.3,0);
            Set_Duty(0.1,1);
            Set_Dir(1,A);
            Set_Dir(-1,B);
            turn_flag=1;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 0&&x5 == 0&&x6 == 1&&x7 == 1&&x8 == 1)  //00000111
        {
            Set_Duty(0.1,0);
            Set_Duty(0.3,1);
            Set_Dir(-1,A);
            Set_Dir(1,B);
            turn_flag=1;
        }
        /*else if(x1 == 0&&x2 == 1&&x3 == 1&&x4 == 1&&x5 == 0&&x6 == 0&&x7 == 0&&x8 == 0)  //01110000
        {
            Set_Duty(0.3,0);
            Set_Duty(0.3,1);
            Set_Dir(1,A);
            Set_Dir(-1,B);
            turn_flag=1;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 0&&x5 == 1&&x6 == 1&&x7 == 1&&x8 == 0)  //00001110
        {
            Set_Duty(0.3,0);
            Set_Duty(0.3,1);
            Set_Dir(-1,A);
            Set_Dir(1,B);
            turn_flag=1;
        }*/
        else if(x1 == 0&&x2 == 1&&x3 == 1&&x4 == 1&&x5 == 1&&x6 == 0&&x7 == 0&&x8 == 0)  //01111000
        {
            Set_Duty(0.3,0);
            Set_Duty(0.1,1);
            Set_Dir(1,A);
            Set_Dir(-1,B);
            turn_flag=1;
        }
        else if(x1 == 0&&x2 == 0&&x3 == 0&&x4 == 1&&x5 == 1&&x6 == 1&&x7 == 1&&x8 == 0)  //00011110
        {
            Set_Duty(0.1,0);
            Set_Duty(0.3,1);
            Set_Dir(-1,A);
            Set_Dir(1,B);
            turn_flag=1;
        }
        else turn_flag=0;
        if(turn_flag==1)
        {
            count_corner++;
            delay_ms(1250);
        }
        if(count_corner==4*quan)
        //if(count_corner==1)
        {
            Set_Dir(0,A);
            Set_Dir(0,B);
            //while(1);
            run=!run;
            count_corner=0;
        }

    }
}
void TIMER_0_INST_IRQHandler(void)
{
    switch (DL_TimerA_getPendingInterrupt(TIMER_0_INST)) {
        case DL_TIMERA_IIDX_ZERO:
            {
                if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_1_PORT,GPIO_GRP_XJ_PIN_1_PIN)==GPIO_GRP_XJ_PIN_1_PIN)x1=1;
                else if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_1_PORT,GPIO_GRP_XJ_PIN_1_PIN)!=GPIO_GRP_XJ_PIN_1_PIN)x1=0;
                if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_2_PORT,GPIO_GRP_XJ_PIN_2_PIN)==GPIO_GRP_XJ_PIN_2_PIN)x2=1;
                else if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_2_PORT,GPIO_GRP_XJ_PIN_2_PIN)!=GPIO_GRP_XJ_PIN_2_PIN)x2=0;
                if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_3_PORT,GPIO_GRP_XJ_PIN_3_PIN)==GPIO_GRP_XJ_PIN_3_PIN)x3=1;
                else if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_3_PORT,GPIO_GRP_XJ_PIN_3_PIN)!=GPIO_GRP_XJ_PIN_3_PIN)x3=0;
                if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_4_PORT,GPIO_GRP_XJ_PIN_4_PIN)==GPIO_GRP_XJ_PIN_4_PIN)x4=1;
                else if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_4_PORT,GPIO_GRP_XJ_PIN_4_PIN)!=GPIO_GRP_XJ_PIN_4_PIN)x4=0;
                if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_5_PORT,GPIO_GRP_XJ_PIN_5_PIN)==GPIO_GRP_XJ_PIN_5_PIN)x5=1;
                else if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_5_PORT,GPIO_GRP_XJ_PIN_5_PIN)!=GPIO_GRP_XJ_PIN_5_PIN)x5=0;
                if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_6_PORT,GPIO_GRP_XJ_PIN_6_PIN)==GPIO_GRP_XJ_PIN_6_PIN)x6=1;
                else if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_6_PORT,GPIO_GRP_XJ_PIN_6_PIN)!=GPIO_GRP_XJ_PIN_6_PIN)x6=0;
                if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_7_PORT,GPIO_GRP_XJ_PIN_7_PIN)==GPIO_GRP_XJ_PIN_7_PIN)x7=1;
                else if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_7_PORT,GPIO_GRP_XJ_PIN_7_PIN)!=GPIO_GRP_XJ_PIN_7_PIN)x7=0;
                if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_8_PORT,GPIO_GRP_XJ_PIN_8_PIN)==GPIO_GRP_XJ_PIN_8_PIN)x8=1;
                else if(DL_GPIO_readPins(GPIO_GRP_XJ_PIN_8_PORT,GPIO_GRP_XJ_PIN_8_PIN)!=GPIO_GRP_XJ_PIN_8_PIN)x8=0;
                /*MA_RPM=Calculate_Motor_RPM(Get_Encoder_countA, 10);//���㵱ǰA��������ת��     ��λ:תÿ����
                MB_RPM=Calculate_Motor_RPM(-Get_Encoder_countB, 10);//���㵱ǰB��������ת��      ��λ:תÿ����
                Get_Encoder_countA=Get_Encoder_countB=0;
                PWMA = -Velocity_A(60,MA_RPM);//PID�ջ�����ת��,��λ:תÿ����
				PWMB = -Velocity_B(60,MB_RPM);//PID�ջ�����ת��,��λ:תÿ����*/
            }
            break;
        default:
            break;
    }
}
void GROUP1_IRQHandler(void)
{
    
    switch (DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1)) {
        case GPIO_GRP_Switch_GPIOB_INT_IIDX:
            if (DL_GPIO_readPins(GPIO_GRP_Switch_PIN_Counter_PORT, GPIO_GRP_Switch_PIN_Counter_PIN)!=GPIO_GRP_Switch_PIN_Counter_PIN) {
                //DL_GPIO_clearInterruptStatus(GPIO_GRP_Switch_PORT, GPIO_GRP_Switch_PIN_Counter_PIN);      
                if(quan>=5)quan=0;
                quan++;
            }
        case GPIO_GRP_Switch_GPIOA_INT_IIDX:
            if (DL_GPIO_readPins(GPIO_GRP_Switch_PIN_confirm_PORT, GPIO_GRP_Switch_PIN_confirm_PIN)!=GPIO_GRP_Switch_PIN_confirm_PIN)
            {
                run=!run;
            }

            break;
    }
    	//��ȡ�ж��ź�
   /* gpio_interrup1 = DL_GPIO_getEnabledInterruptStatus(ENCODERA_PORT,ENCODERA_E1A_PIN|ENCODERA_E1B_PIN);
    gpio_interrup2 = DL_GPIO_getEnabledInterruptStatus(ENCODERB_PORT,ENCODERB_E2A_PIN|ENCODERB_E2B_PIN);
    
    
	//encoderA
	if((gpio_interrup1 & ENCODERA_E1A_PIN)==ENCODERA_E1A_PIN)
	{
		if(!DL_GPIO_readPins(ENCODERA_PORT,ENCODERA_E1B_PIN))
		{
			Get_Encoder_countA--;
		}
		else
		{
			Get_Encoder_countA++;
		}
	}
	else if((gpio_interrup1 & ENCODERA_E1B_PIN)==ENCODERA_E1B_PIN)
	{
		if(!DL_GPIO_readPins(ENCODERA_PORT,ENCODERA_E1A_PIN))
		{
			Get_Encoder_countA++;
		}
		else
		{
			Get_Encoder_countA--;
		}
	}
	
	//encoderB
	if((gpio_interrup2 & ENCODERB_E2A_PIN)==ENCODERB_E2A_PIN)
	{
		if(!DL_GPIO_readPins(ENCODERB_PORT,ENCODERB_E2B_PIN))
		{
			Get_Encoder_countB--;
		}
		else
		{
			Get_Encoder_countB++;
		}
	}
	else if((gpio_interrup2 & ENCODERB_E2B_PIN)==ENCODERB_E2B_PIN)
	{
		if(!DL_GPIO_readPins(ENCODERB_PORT,ENCODERB_E2A_PIN))
		{
			Get_Encoder_countB++;
		}                 
		else              
		{                 
			Get_Encoder_countB--;
		}
	}
	DL_GPIO_clearInterruptStatus(ENCODERA_PORT,ENCODERA_E1A_PIN|ENCODERA_E1B_PIN);
	DL_GPIO_clearInterruptStatus(ENCODERB_PORT,ENCODERB_E2A_PIN|ENCODERB_E2B_PIN);*/
}
//滴答定时器中断服务函数
void SysTick_Handler(void)
{
    if( delay_times != 0 )
    {
        delay_times--;
    }
}




