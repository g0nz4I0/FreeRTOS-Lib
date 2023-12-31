/**
 * @file GlobalMutexHandler.cpp
 * @author gonzalo
 * @brief 
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <freeRTOS-lib/inc/GlobalMutexHandler.hpp>


namespace rtos
{

std::array<global_mutex*,mutex_type::mutex_type_MAX>GlobalMutexHandler<mutex_type>::mutexes {};
std::array<StaticSemaphore_t,mutex_type::mutex_type_MAX>GlobalMutexHandler<mutex_type>::semaphore_buffer{};
} //rtos
rtos::GlobalMutexHandler<rtos::mutex_type> MutexHandler;