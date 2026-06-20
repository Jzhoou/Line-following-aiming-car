#include "ti_msp_dl_config.h"
#include "BJMotor.h"

//uint8_t data[] = {0x01,0xFD,0x00,0x07,0xDC,0xCC,0x00,0x00,0x5D,0x00,0x00,0x00,0x6B};//命令格式：地址 + 0xFD + 方向 + 速度+ 加速度 + 脉冲数 + 相对/绝对模式标志 + 多机同步标志 + 校验字节




int main(void)
{
    SYSCFG_DL_init();
    //清除串口中断标志
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    //使能串口中断
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN);

    //uart0_send_string("uart0 start work\r\n");
    send_BJ_Motor_command(0x01,0x00,0x07,0xdc,0x77,0x00,0x00,0x5d,0x00,0x00,0x00);
    while (1)
    {

    }
}

