/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ti_msp_dl_config.h"
volatile long Velocity_L, Velocity_R ;   //左右轮编码器数据
int Velocity_Left, Velocity_Right = 0, Velocity, Turn;   //左右轮速度
int main(void)
{
    SYSCFG_DL_init();
    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);
    NVIC_EnableIRQ(GPIO_hal_INT_IRQN);

    DL_TimerA_startCounter(TIMER_0_INST);
    while (1) {
    }
}

void TIMER_0_INST_IRQHandler(void)
{
  Velocity_Left = Velocity_L;    Velocity_L = 0;  //读取左轮编码器数据，并清零，这就是通过M法测速（单位时间内的脉冲数）得到速度。
  Velocity_Right = Velocity_R;    Velocity_R = 0; //读取右轮编码器数据，并清零
}
void GROUP1_IRQHandler(void) {
  switch (DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1)) {
  case GPIO_hal_PIN_A_IIDX:
    //DL_GPIO_togglePins(GPIO_GRP_LED_PORT, GPIO_GRP_LED_PIN_LED_PIN);
    break;
  case GPIO_hal_PIN_B_IIDX:
    {
          if (DL_GPIO_readPins(GPIO_hal_PORT,GPIO_hal_PIN_A_PIN) == 0) {     //如果是下降沿触发的中断
            if (DL_GPIO_readPins(GPIO_hal_PORT,GPIO_hal_PIN_B_PIN) == 0)      Velocity_L--;  //根据另外一相电平判定方向
            else      Velocity_L++;
        }
        else {     //如果是上升沿触发的中断
            if (DL_GPIO_readPins(GPIO_hal_PORT,GPIO_hal_PIN_B_PIN) == 0)      Velocity_L++; //根据另外一相电平判定方向
            else     Velocity_L--;
        }
        DL_GPIO_clearInterruptStatus(GPIO_hal_PORT,GPIO_hal_PIN_B_PIN);
    }
    break;
  }
}
