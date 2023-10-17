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
    static void notify_thread(std::string thread_name);
    static void register_thread(std::string thread_name,thread* thread);
private:
    static std::unordered_map<std::string,thread*> threads;
};

} // namespace rtos