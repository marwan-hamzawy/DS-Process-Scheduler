cmake_minimum_required(VERSION 3.24)
project(Process_Scheduler_DS)

set(CMAKE_CXX_STANDARD 17)

add_executable(Process_Scheduler_DS Process_Scheduler_DS.cpp CircularQueue.h CircularQueue.cpp FCFSProcessor.cpp FCFSProcessor.h PriorityQueue.cpp PriorityQueue.cpp CircularQueue.cpp CircularQueue.cpp Process.cpp Processor.cpp Queue.cpp RRProcessor.cpp Scheduler.cpp SJFProcessor.cpp UI.cpp)
