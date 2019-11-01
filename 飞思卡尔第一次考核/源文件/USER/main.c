#include "led.h"
#include "adc.h"
#include "key.h"

int main()
{
		GPIO_LED_Init();
		GPIO_KEY_Init();
		EXTIX_Init();
		GPIO_ADC_Init();
		ADC_Volt();
		while(1)
		{
				LED_Number(parameter);
		}
}
