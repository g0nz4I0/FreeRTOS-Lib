/**
 * @file Thread.cpp
 * @author gonzalo
 * @brief 
 * @version 0.1
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <freeRTOS-lib/inc/Thread.hpp>

TaskHandle_t rtos::thread::get_handle()const
{
    return this->handle;
}  