#ifndef __LED_H
#define __LED_H

#include "sys.h"

//����λѡ�˿�
#define  S1  PBout(8)
#define  S2  PBout(9)
#define  S3  PBout(10)
#define  S4  PBout(11)
#define  frequency  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2)
#define 	GPIO_WriteHigh(GPIOx,a)    GPIOx->BSRR=(((uint8_t)(uint8_t)~(a))<<24)|(((uint32_t)(uint8_t)(a))<<8)

extern unsigned char number[10];   //����0~9�ı���

void GPIO_LED_Init(void);   //IO�ڳ�ʼ������
void LED_Number(float x);   //��ʾ����
void delayfunc(unsigned int x);   //��ʱ����	

#endif
