cmake_minimum_required(VERSION 3.24)
project(Process_Scheduler_DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Process_Scheduler_DS
        CircularQueue.cpp
        CircularQueue.h
        FCFSProcessor.cpp
        FCFSProcessor.h
        PriorityQueue.cpp
        PriorityQueue.h
        Process.cpp
        Process.h
        Process_Scheduler_DS.cpp
        Processor.cpp
        Processor.h
        Queue.cpp
        Queue.h
        RRProcessor.cpp
        RRProcessor.h
        Scheduler.cpp
        Scheduler.h
        SJFProcessor.cpp
        SJFProcessor.h
        UI.cpp
        UI.h)
