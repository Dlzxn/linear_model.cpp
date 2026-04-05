cmake_minimum_required(VERSION 3.10)
project(Linear)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(. loss_func model optimizer)

add_executable(linear_app 
    main.cpp 
    loss_func/loss_function.cpp
    model/Linear_model.cpp
    optimizer/optimizer.cpp
)
