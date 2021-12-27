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

/**
 * 暂停/恢复
 * @param {暂停/恢复} _stop
 */
void SET_top(int _instop);

/**
 * 重置数字
 * @param {重置} _reset
 */
void SET_reset(int _inreset);

/**
 * 显示数字加
 */
void ADD_number(int _num);

/**
 * 按钮
 */
void SCAN_Keys();
#endif
