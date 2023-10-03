/**
 * @file GlobalMutexHandler.hpp
 * @author gonzalo
 * @brief GlobalMutex handler by Hyperloop UPV team
 * @version 0.1
 * @date 2023-10-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "defs.hpp"

#include <unordered_map>
#include <array>
namespace rtos
{
    /**
     * @class GlobalMutexHandler
     * @brief Global class that handles several global mutexes
     */
class GlobalMutexHandler{
public:
    GlobalMutexHandler() = delete;
    static constexpr unsigned int num_semaphores = 10;
    static std::array<StaticSemaphore_t,num_semaphores> semaphore_buffer;
    /**
     * @brief tries to acquire a mutex
     * 
     * @tparam mutex_type that want to be acquired
     * @return mutex_state 
     */
    template<mutex_type>
    static mutex_state acquire();
    /**
     * @brief releases the mutex specified as the template argument
     * 
     * @tparam mutex_type that wants to be released
     * @return true if the mutex could be released
     * @return false if the mutex could not be released
     */
    template <mutex_type>
    static bool release();
};
}//rtos