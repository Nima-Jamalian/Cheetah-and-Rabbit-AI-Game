cmake_minimum_required(VERSION 3.3)
project(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    button.cpp
    button.hpp
    Cheetah.cpp
    Cheetah.hpp
    collectables.cpp
    collectables.hpp
    Entity.cpp
    Entity.hpp
    Grid.cpp
    Grid.hpp
    Linked_List.cpp
    main.cpp
    Menu.cpp
    Menu.hpp
    Obstacle.cpp
    Obstacle.hpp
    ofApp.cpp
    ofApp.h
    Priority_Queue.hpp
    Rabbit.cpp
    Rabbit.hpp
    Stack.hpp)

add_executable(src ${SOURCE_FILES})