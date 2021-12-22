#ifndef _5611BH_H
#define _5611BH_H

/**
 * 脚引转成数组 但是没有成功
 */
//extern GPIO_TypeDef GPIO_LIST[8];
//extern uint16_t PIN_LIST[8];

/**
 * 定义数字对应脚引
 */
extern int NUMBERS[10][7];

/**
 * 显示单个脚管
 */
void SHOW_GPIO (int num);

/**
 * 显示一组脚管
 */
void SHOW_GPIOS (int nums[]);

/**
 * 重置脚管 所有脚管设置为灭
 */
void BH_RESET();

/**
 * 设置显示某个数字
 */
void GPIO_SetBits(int letter);

/**
 * 初始化
 */
void BH_init();

#endif
