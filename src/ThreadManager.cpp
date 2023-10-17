/**
 * @file ThreadManager.cpp
 * @author gonzalo
 * @brief 
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <freeRTOS-lib/inc/ThreadManager.hpp>
#include <freeRTOS-lib/inc/Thread.hpp>

namespace rtos{
    std::array<thread*,ThreadManager::MAX_THREADS> ThreadManager::threads{};
    void ThreadManager::notify_thread(uint8_t thread_id)
    {
        if(ThreadManager::threads[thread_id] == nullptr)
        {
            Error_Handler();
        }else
        {
            xTaskNotifyGive(ThreadManager::threads[thread_id]->get_handle());
        }
    }
    void ThreadManager::register_thread(uint8_t thread_id,thread* thread)
    {
        if(ThreadManager::threads[thread_id] != nullptr)
        {
            Error_Handler();
        }
        ThreadManager::threads[thread_id] = thread;
    }




}