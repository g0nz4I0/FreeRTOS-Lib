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
    std::unordered_map<std::string,thread*> ThreadManager::threads;
    void ThreadManager::notify_thread(std::string thread_name)
    {
        if(ThreadManager::threads.find(thread_name) == ThreadManager::threads.end())
        {
            Error_Handler();
        }else
        {
            xTaskNotifyGive(ThreadManager::threads[thread_name]->get_handle());
        }
    }
    void ThreadManager::register_thread(std::string thread_name,thread* thread)
    {
        if(ThreadManager::threads.find(thread_name) != ThreadManager::threads.end())
        {
            Error_Handler();
        }
        ThreadManager::threads[thread_name] = thread;
    }




}