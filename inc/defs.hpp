/**
 * @file defs.hpp
 * @author gonzalo
 * @brief contains project defs
 * @version 0.1
 * @date 2023-10-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <free-rtos/include/FreeRTOS.h>
#include <free-rtos/include/task.h>
#include <free-rtos/include/semphr.h>

#include "ErrorHandler/ErrorHandler.hpp"


namespace rtos
{
    /**
     * @class mutex_state
     * @brief holds two possible values, ACQUIRED and NOT_ACQUIRED, representing the mutex state
    */
    enum class mutex_state{
        ACQUIRED,
        NOT_ACQUIRED
    };
    /**
     * @class mutex_type
     * @brief holds all of the several possible mutex_types 
     * 
     */
    enum class mutex_type{
        AAA,
        DMA,
        TCP,
    };
}//rtos
