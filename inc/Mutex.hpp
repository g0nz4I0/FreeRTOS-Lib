/**
 * @file Mutex.hpp
 * @author gonzalo
 * @brief mutex utility by Hyperloop team
 * @version 0.1
 * @date 2023-10-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <freeRTOS-lib/inc/defs.hpp>
namespace rtos
{
    /**
     * @class mutex
     * @brief mutex class abstraction above native FreeRTOS mutexes 
     * 
     */
class mutex{

public:
    /**
     * @brief Construct a new mutex object
     * 
     */
    mutex();
    /**
     * @brief Get the handle object
     * 
     * @return SemaphoreHandle_t 
     */
    SemaphoreHandle_t get_handle()const;
    /**
     * @brief need to check return value to see if the mutex has been acquired or not 
     * @param time time to wait before returning if the mutex cannot be acquired, 
     * by default is set to portMAX_DELAY which wait indefinely, a value of 0 will return inmediatly if it is not available
     * @return mutex_state::ACQUIRED if the mutex was acquired, mutex_state::NOT_ACQUIRED if it could not be acquired after the time specified
     */
    [[nodiscard("the function can return if a timeout occurs and the mutex is not acquired")]]mutex_state acquire(TickType_t time = portMAX_DELAY);
    
    /**
     * @brief releases the mutex
     * @return none if suceeds, if it fails to release because you are not the owner it goes into the ErrorHandler
     * 
     */
    void release();
private:
    SemaphoreHandle_t handle;
};
}//rtos


