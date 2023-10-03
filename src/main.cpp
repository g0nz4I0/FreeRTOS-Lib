
#include "GlobalMutex.hpp"
#include "GlobalMutexHandler.hpp"
#include "defs.hpp"


int main()
{
    rtos::GlobalMutexHandler::acquire<rtos::mutex_type::DMA>();
    rtos::GlobalMutexHandler::acquire<rtos::mutex_type::TCP>();
}