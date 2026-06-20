#include "BJMotor.h"

uint8_t data[13];
unsigned char uart_data = 0;
uint8_t dataSize ;  // 计算数组大小

void send_BJ_Motor_command(uint8_t add,uint8_t dir,uint8_t v1,uint8_t v2,uint8_t a,uint8_t pul1,uint8_t pul2,uint8_t pul3,uint8_t pul4,uint8_t ablu,uint8_t mul)
{
    data[0]=add;
    data[1]=0xfd;
    data[2]=dir;
    data[3]=v1;
    data[4]=v2;
    data[5]=a;
    data[6]=pul1;
    data[7]=pul2;
    data[8]=pul3;
    data[9]=pul4;
    data[10]=ablu;
    data[11]=mul;
    data[12]=0x6b;
    dataSize = sizeof(data) / sizeof(data[0]);  // 计算数组大小
    for(uint8_t i = 0; i < dataSize; i++) {
        uart0_send_char(data[i]);
        // 如果需要，可以添加延时或检查发送状态，但DL_UART_Main_transmitData通常阻塞
    }
}
//串口发送单个字符
void uart0_send_char(char ch)
{
    //当串口0忙的时候等待，不忙的时候再发送传进来的字符
    while( DL_UART_isBusy(UART_0_INST) == true );
    //发送单个字符
    DL_UART_Main_transmitData(UART_0_INST, ch);
}
//串口发送字符串
void uart0_send_string(char* str)
{
    //当前字符串地址不在结尾 并且 字符串首地址不为空
    while(*str!=0&&str!=0)
    {
        //发送字符串首地址中的字符，并且在发送完成之后首地址自增
        uart0_send_char(*str++);
    }
}

//串口的中断服务函数
void UART_0_INST_IRQHandler(void)
{
    //如果产生了串口中断
    switch( DL_UART_getPendingInterrupt(UART_0_INST) )
    {
        case DL_UART_IIDX_RX://如果是接收中断
            //将发送过来的数据保存在变量中
            uart_data = DL_UART_Main_receiveData(UART_0_INST);
            //将保存的数据再发送出去
            uart0_send_char(uart_data);
            break;

        default://其他的串口中断
            break;
    }
}
