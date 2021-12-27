#include "stm32f1xx_hal.h"
#include "main.h"
#include "led1.h"

void SHOW_LED(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);// 亮--Low
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);// 亮--Low

	// 红
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);// 亮--Low
	HAL_GPIO_WritePin(LED_R2_GPIO_Port, LED_R2_Pin, GPIO_PIN_RESET);// 亮--Low
	// 绿
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);// 灭--High
}

void HIND_LED(){
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);// 灭--High
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);// 灭--High

	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);//灭--High
	HAL_GPIO_WritePin(LED_R2_GPIO_Port, LED_R2_Pin, GPIO_PIN_SET);//灭--High
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);//亮--Low
}

void LED_Init() {
	SHOW_LED();
	HAL_Delay(1000);
	HIND_LED();
	HAL_Delay(3000);
//	SHOW_LED();
}
