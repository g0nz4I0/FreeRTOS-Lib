#include "Mutex.hpp"
#include "defs.hpp"
namespace rtos
{
mutex::mutex()
{
    handle = xSemaphoreCreateMutex();
    if(handle == NULL)
    {
        ErrorHandler("Could not allocate specified stack size");
    }
}
mutex_state mutex::acquire(TickType_t time = portMAX_DELAY)
{
    if(xSemaphoreTake(handle,time) == pdTRUE)
    {
        return mutex_state::ACQUIRED;
    }else{
        return mutex_state::NOT_ACQUIRED;
    }
}
void mutex::release()
{
   if(xSemaphoreGive(handle) == pdPASS)
   {
    return;
   }else{
        ErrorHandler("the mutex is not owned by you");
   }
}
SemaphoreHandle_t mutex::get_handle()const{
    return handle;
}
}//rtos