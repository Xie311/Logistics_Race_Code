/**
 * @file wtr_target.h
 * @author X311
 * @brief 
 * @version 0.0
 * @date 2024-04-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef __WTR_TARGET_H
#define __WTR_TARGET_H

#include "Chassis_Start.h"
void Chassis_Target_Init();
void Chassis_Target_Decode();
/************************ 用户定义 ***************************/
#define Tar_UART_HANDLE huart6 // 串口选项
#define Tar_UART        USART6  // 串口选项

/************************变量定义 ***************************/
extern float weight_placement[5];
extern uint8_t receive_buffer[24];
typedef struct Tar_t {
    float pos_x;   // x坐标
    float pos_y;   // y坐标
    float yaw;     //航向角
    
    float vx;      // x轴速度
    float vy;      // y轴速度
    float vw;      // 角速度w

    int state;   // 状态：1停止；2校准；3启动
} Tar_t;

extern Tar_t Tar_Data;
// extern uint8_t tar_buffer[30];

//uint8_t Tar_Decode(void);

#endif