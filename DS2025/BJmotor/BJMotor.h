#ifndef _BJMOTOR_H
#define _BJMOTOR_H
#include "ti_msp_dl_config.h"

//extern uint8_t data[13];
//extern uint8_t dataSize ;  // 计算数组大小
void send_BJ_Motor_command(uint8_t add,uint8_t dir,uint8_t v1,uint8_t v2,uint8_t a,uint8_t pul1,uint8_t pul2,uint8_t pul3,uint8_t pul4,uint8_t ablu,uint8_t mul);
void uart0_send_char(char ch); //串口0发送单个字符
void uart0_send_string(char* str); //串口0发送字符串

#endif
