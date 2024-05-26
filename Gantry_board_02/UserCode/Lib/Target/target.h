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

#include "UpperStart.h"
void Upper_Target_Init();
void Upper_Target_Decode();
void Target_Decode_TaskStart();
void Target_Decode_Task();
/************************ 用户定义 ***************************/
#define Tar_UART_HANDLE huart5 // 串口选项
#define Tar_UART        USART5  // 串口选项

/************************变量定义 ***************************/
extern float weight_placement[5];
extern uint8_t receive_buffer[24];
//extern int tar_count;
extern float final_weight_placement[5];

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

#endif