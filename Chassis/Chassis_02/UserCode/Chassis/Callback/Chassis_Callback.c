/*
 * @Author: X311
 * @Date: 2024-04-16
 * @LastEditors: x311 
 * @LastEditTime: 2024-05-06 23:12:44
 * @FilePath: \Chassis_02\UserCode\Chassis\Callback\Chassis_Callback.c
 * @Brief: 底盘用中断回调函数
 */

#include "Chassis_Callback.h"

/**
 * @brief: 串口接收中断回调函数
 * @param {UART_HandleTypeDef} *huart 中断串口
 * @return {*}
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == OPS_UART) 
    {
        //HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
        // 检查起始和结束字符以确保数据完整性
        if ((ops_buffer[0] == 0x0D) && (ops_buffer[1] == 0x0A) && (ops_buffer[26] == 0x0A) && (ops_buffer[27] == 0x0D))
        {
            OPS_Decode(); // 当数据接收完成时调用OPS码盘解码函数
        }
        HAL_UART_Receive_IT(&huart8, ops_buffer, sizeof(ops_buffer)); 
    }

    if (huart->Instance == Tar_UART) 
    {
        //接收上位机数据并解码
        Chassis_Target_Decode();
        HAL_UART_Receive_IT(&huart6, (uint8_t *)receive_buffer, sizeof(receive_buffer));
    }
}


