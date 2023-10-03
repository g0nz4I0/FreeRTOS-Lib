/**
 * @file GlobalMutex.hpp
 * @author gonzalo 
 * @brief global_mutex, templated on a mutex type
 * @version 0.1
 * @date 2023-10-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "defs.hpp"
#include <iostream>

namespace rtos
{
/**
 * @class global_mutex
 * @brief creates a mutex in the global namespace
 * @tparam mutex_type from the mutex_type enum
 */
template<mutex_type>
class global_mutex{
public:
/**
 * @brief Construct a new global mutex object in the global namespace
 * 
 */
    global_mutex();
    /**
     * @brief tries to acquire the mutex based on the type it is templated on
     * 
     * @return mutex_state::ACQUIRED if the mutex could be acquired, otherwise mutex_state::NOT_ACQUIRED
     */
    mutex_state acquire();
    /**
     * @brief tries to release the mutex
     * 
     * @return true if it could be released
     * @return false if it could not be released
     */
    bool release();
    /**
     * @brief Get the Handle object
     * 
     * @return SemaphoreHandle_t 
     */
    SemaphoreHandle_t getHandle();
protected:
    SemaphoreHandle_t handle;
};

template<>
class global_mutex<mutex_type::DMA>{
    public:
        global_mutex(){
            std::cout<<"Constructed DMA mutex";
        }
        mutex_state acquire(){
            std::cout<<"acquired DMA mutex";
            return mutex_state::ACQUIRED;
        }
    protected:
        SemaphoreHandle_t handle;
};
template<>
class global_mutex<mutex_type::TCP>{
    public:
        global_mutex(){
            std::cout<<"Constructed TCP mutex";
        }
        mutex_state acquire(){
            std::cout<<"acquired TCP mutex";
            return mutex_state::ACQUIRED;
        }
    protected:
        //SemaphoreHandle_t handle;
};
template<>
class global_mutex<mutex_type::AAA>{
    public:
        global_mutex(){
            std::cout<<"Constructed AAA mutex";
        }   
        mutex_state acquire(){
            std::cout<<"acquired AAA mutex";
            return mutex_state::ACQUIRED;
        }
    protected:
        //SemaphoreHandle_t handle;
};

}//rtos