/*
 * 5611bh.c
 *
 *  Created on: Dec 22, 2021
 *      Author: zhans.dong
 */



#include <time.h>
#include "5611bh.h"
#include "stm32f1xx_hal.h"
#include "main.h"

//GPIO_TypeDef GPIO_LIST[8] = {BH_A_GPIO_Port, BH_B_GPIO_Port, BH_C_GPIO_Port, BH_D_GPIO_Port, BH_E_GPIO_Port, BH_F_GPIO_Port, BH_G_GPIO_Port, PH_DP_GPIO_Port};
//
//uint16_t PIN_LIST[8] = {BH_A_Pin, BH_B_Pin, BH_C_Pin, BH_D_Pin, BH_E_Pin, BH_F_Pin, BH_G_Pin, BH_DP_Pin};
//
int NUMBERS[10][7] = {
		{0,1,2,3,4,5,-1}, // 0
		{1,2,-1,-1,-1,-1,-1}, // 1
		{0,1,6,4,3,-1,-1}, // 2
		{0,1,2,6,3,-1,-1}, // 3
		{5,6,1,2,-1,-1,-1}, // 4
		{0,5,6,2,3,-1,-1}, // 5
		{0,5,4,3,2,6,-1}, // 6
		{0,1,2,-1,-1,-1,-1}, // 7
		{0,1,2,3,4,5,6}, // 8
		{0,1,2,3,5,6,7}, // 9 + .
};

void SHOW_GPIO (int num) {
	switch(num) {
		case 0:
			HAL_GPIO_WritePin(BH_A_GPIO_Port, BH_A_Pin, GPIO_PIN_RESET);// 亮
			break;
		case 1:
			HAL_GPIO_WritePin(BH_B_GPIO_Port, BH_B_Pin, GPIO_PIN_RESET);// 亮
			break;
		case 2:
			HAL_GPIO_WritePin(BH_C_GPIO_Port, BH_C_Pin, GPIO_PIN_RESET);// 亮
			break;
		case 3:
			HAL_GPIO_WritePin(BH_D_GPIO_Port, BH_D_Pin, GPIO_PIN_RESET);// 亮
			break;
		case 4:
			HAL_GPIO_WritePin(BH_E_GPIO_Port, BH_E_Pin, GPIO_PIN_RESET);// 亮
			break;
		case 5:
			HAL_GPIO_WritePin(BH_F_GPIO_Port, BH_F_Pin, GPIO_PIN_RESET);// 亮
			break;
		case 6:
			HAL_GPIO_WritePin(BH_G_GPIO_Port, BH_G_Pin, GPIO_PIN_RESET);// 亮
			break;
		case 7:
			HAL_GPIO_WritePin(BH_H_GPIO_Port, BH_H_Pin, GPIO_PIN_RESET);// 亮
			break;
	}
}

void SHOW_GPIOS (int nums[]) {
	for( int index = 0; index < 7; index++ ){
		SHOW_GPIO(nums[index]);
	}
}


void BH_RESET() {
	HAL_GPIO_WritePin(BH_A_GPIO_Port, BH_A_Pin, GPIO_PIN_SET);// 灭
	HAL_GPIO_WritePin(BH_B_GPIO_Port, BH_B_Pin, GPIO_PIN_SET);// 灭
	HAL_GPIO_WritePin(BH_C_GPIO_Port, BH_C_Pin, GPIO_PIN_SET);// 灭
	HAL_GPIO_WritePin(BH_D_GPIO_Port, BH_D_Pin, GPIO_PIN_SET);// 灭
	HAL_GPIO_WritePin(BH_E_GPIO_Port, BH_E_Pin, GPIO_PIN_SET);// 灭
	HAL_GPIO_WritePin(BH_F_GPIO_Port, BH_F_Pin, GPIO_PIN_SET);// 灭
	HAL_GPIO_WritePin(BH_G_GPIO_Port, BH_G_Pin, GPIO_PIN_SET);// 灭
	HAL_GPIO_WritePin(BH_H_GPIO_Port, BH_H_Pin, GPIO_PIN_SET);// 灭
}


void GPIO_SetBits(int letter) {
	BH_RESET();
	SHOW_GPIOS(NUMBERS[letter]);
}
int _time = 0;
void BH_init() {
	GPIO_SetBits(_time);
	_time++;
	if (_time >=10) {
		_time=0;
	}

	HAL_Delay(1000);
	BH_init();
}
