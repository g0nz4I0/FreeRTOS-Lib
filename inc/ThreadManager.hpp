/**
 * @file ThreadManager.hpp
 * @author gonzalo
 * @brief 
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#pragma once

#include <unordered_map>
#include <string>

namespace rtos{

class thread;

class ThreadManager{

public:
    /**
     * @brief notifies the thread specified by thread_name
     * 
     * @param thread_id the thread id to be notified
     */
    static void notify_thread(uint8_t thread_id);
    /**
     * @brief called by the thread constructor to register itself
     * 
     * @param thread_id the id it was given
     * @param thread a pointer to the thread (this)
     */
    static void register_thread(uint8_t thread_id,thread* thread);
private:
    static constexpr uint8_t MAX_THREADS = 10;
    static std::array<thread*,MAX_THREADS> threads;
};

} // namespace rtos