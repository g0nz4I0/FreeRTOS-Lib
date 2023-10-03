cmake_minimum_required(VERSION 3.10)
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED TRUE)
add_compile_options(-std=c++20)
set(PROJECT_NAME GlobalMutex)
project(${PROJECT_NAME})

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GlobalMutexHandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
set(INC 
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    )
add_executable(${PROJECT_NAME} ${SRC} )
target_include_directories( ${PROJECT_NAME} PUBLIC  ${INC})

