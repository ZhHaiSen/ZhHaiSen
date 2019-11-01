#include "led.h"

//数字0~9的编码
extern unsigned char number[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void GPIO_LED_Init(void)   //IO口初始化配置
{
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD, ENABLE);   //开PA，PC，PD的时钟

		//LED的数据输出IO口
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
		//LED的位选IO口
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;				
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
		//用作判断定时器中断
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void LED_Number(float x)   //显示数字
{
		if(frequency == 0)
		{
				int a, b, c, d, num;
				num = x * 10;
				a = num / 1000;
				b = num % 1000 / 100;
				c = num % 100 / 10;
				d = num % 10;
				{
						S1 = 0;
						S2 = 1;
						S3 = 1;
						S4 = 1;
						GPIO_WriteHigh(GPIOC, number[a]);
						delayfunc(1);
						GPIO_WriteHigh(GPIOC, 0);
				}
				{
						S1 = 1;
						S2 = 0;
						S3 = 1;
						S4 = 1;
						GPIO_WriteHigh(GPIOC, number[b]);
						delayfunc(1);
						GPIO_WriteHigh(GPIOC, 0);
				}
				{
						S1 = 1;
						S2 = 1;
						S3 = 0;
						S4 = 1;
						GPIO_WriteHigh(GPIOC, number[c]+0x80);
						delayfunc(1);
						GPIO_WriteHigh(GPIOC, 0);
				}
				{
						S1 = 1;
						S2 = 1;
						S3 = 1;
						S4 = 0;
						GPIO_WriteHigh(GPIOC, number[d]);
						delayfunc(1);
						GPIO_WriteHigh(GPIOC, 0);
				}
		}
}

void delayfunc(unsigned int x)   //延时函数
{
    unsigned char i;
    while(x--) 
				for(i=0;i<120;i++);
}
