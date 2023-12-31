/**
 * @file Thread.hpp
 * @author gonzalo
 * @brief thread utility by Hyperloop Team
 * @version 0.1
 * @date 2023-10-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <free-rtos/include/FreeRTOS.h>
#include <free-rtos/include/task.h>

#include <freeRTOS-lib/inc/ThreadManager.hpp>

#include "ErrorHandler/ErrorHandler.hpp"

namespace rtos
{


/**
 * @class this_thread
 * @brief contains wrapper methods that capture the current context, therefore
 * they can ONLY be used to manipulate the calling thread
 */

struct this_thread{
	/**
	 * @brief suspends execution for the specified time
	 *
	 * @param ref last wake time
	 * @param ms time to sleep in ms
	 */
	static void sleep_for(TickType_t* ref, float ms)
	{
		if(ms < 0){
			ErrorHandler("INVALID PERIOD, please enter a period greater than 0");
		}
		vTaskDelayUntil(ref,(ms*configTICK_RATE_HZ)/1'000);
	}
	/**
	 * @brief Get the time reference object
	 *
	 * @return TickType_t
	 */
	static TickType_t get_time_reference()
	{
		return  xTaskGetTickCount();
	}

    /**
     * @brief deletes the thread
     * 
     */
    static void join(){
        vTaskDelete(NULL);
    }
    /**
     * @brief blocks indefinitely until a notification is received
     * 
     */
    static void wait_for_notif(){
        xTaskNotifyWait(pdFALSE,ULONG_MAX,NULL,portMAX_DELAY);
    }

};//this_thread
/**
 * @class thread
 * @brief thread class abstraction above native FreeRTOS tasks
 */
class thread
{
public:
    /**
     * @brief
     *
     * @tparam T callable object
     * @tparam Args parameters to the callable object
     * @param t callable object
     * @param name name of the task (debugging)
     * @param stack_size stack size in bytes, must be bigger than 256
     * @param priority priority for the RTOS scheduler, between 1  and configMAX_PRIORITIES
     * @param args args to the callable
     * @return requires constexpr
     */
    template<typename T,typename... Args> requires std::invocable<T,Args...>
    constexpr thread(T t,const char* name,u8_t id, unsigned int stack_size, unsigned int priority,Args... args):handle{0}
    {
        this->id = id;
    	if(
    			stack_size < configMINIMAL_STACK_SIZE ||
				priority < 1 || priority > configMAX_PRIORITIES
    	)
		{
    		ErrorHandler("Failed constraints");
		}

    	if constexpr (sizeof...(args) > 0 )
        {
            if (xTaskCreate((void(*)(void*))(t), name,stack_size,args...,priority,&handle) != pdPASS)
            {
                ErrorHandler("Could not allocate specified stack size");
            }else{
                ThreadManager::register_thread(id,this);
            }
        }else
        {
            if(xTaskCreate((void(*)(void*))(t), name,stack_size,nullptr,priority,&handle) != pdPASS)
            {
                ErrorHandler("Could not allocate specified stack size");

            }else{
                ThreadManager::register_thread(id,this);
            }
        }
    }

    /**
     * @brief Get the handle object
     *
     * @return TaskHandle_t
     */
    TaskHandle_t get_handle()const;
private:
    u8_t id;
    TaskHandle_t handle{};
};
}//rtos