#ifndef __LED_H
#define __LED_H

#include "sys.h"

//定义位选端口
#define  S1  PBout(8)
#define  S2  PBout(9)
#define  S3  PBout(10)
#define  S4  PBout(11)
#define  frequency  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)
#define 	GPIO_WriteHigh(GPIOx,a)    GPIOx->BSRR=(((uint8_t)(uint8_t)~(a))<<24)|(((uint32_t)(uint8_t)(a))<<8)

extern unsigned char number[10];   //数字0~9的编码

void GPIO_LED_Init(void);   //IO口初始化配置
void LED_Number(float x);   //显示数字
void delayfunc(unsigned int x);   //延时函数	

#endif
