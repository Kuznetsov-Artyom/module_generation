cmake_minimum_required(VERSION 3.0.0)


project(module_one)


set(SRC
    sources/main.cpp 
)

set(HDR
    headers/generationModule.hpp
)


add_executable(module_one ${SRC})


set_target_properties(
    module_one PROPERTIES
    CXX_STANDART 11
    CXX_STANDART_REQUIRED ON
)