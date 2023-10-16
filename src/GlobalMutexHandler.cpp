#include <freeRTOS-lib/inc/GlobalMutex.hpp>
#include <freeRTOS-lib/inc/GlobalMutexHandler.hpp>



namespace rtos
{

global_mutex<mutex_type::DMA> dma_mutex;
global_mutex<mutex_type::TCP> tcp_mutex;
global_mutex<mutex_type::AAA> aaa_mutex;

template<>
mutex_state GlobalMutexHandler::acquire<mutex_type::DMA>(){
    dma_mutex.acquire();
    return mutex_state::ACQUIRED;
}
template<>
mutex_state GlobalMutexHandler::acquire<mutex_type::TCP>(){
    tcp_mutex.acquire();
    return mutex_state::NOT_ACQUIRED;

    }
template<>
mutex_state GlobalMutexHandler::acquire<mutex_type::AAA>(){
        return mutex_state::ACQUIRED;
    }

}//rtos

