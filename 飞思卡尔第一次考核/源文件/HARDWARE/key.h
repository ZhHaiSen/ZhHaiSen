#ifndef __KEY_H
#define __KEY_H	

#include "sys.h"

#define  KEY1  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
#define  KEY2  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)
#define  KEY3  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_2)
#define  KEY4  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)
#define  KEY5  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)

void GPIO_KEY_Init(void);
void EXTIX_Init(void);

#endif
