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
namespace rtos
{
    /**
     * @class state enum
     * @brief holds two possible values, ACQUIRED and NOT_ACQUIRED, representing the mutex state
    */
    enum class mutex_state{
        ACQUIRED,
        NOT_ACQUIRED
    };
}//rtos
