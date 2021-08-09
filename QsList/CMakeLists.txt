cmake_minimum_required(VERSION 3.19)
project(QsList)

set(CMAKE_CXX_STANDARD 20)

add_executable(QsList main.cpp map/Qlist.h map/unidirectLink.h map/staticLink.h map/circularLink.h map/Queue.h map/MutualLink.h map/abstractLink.h "map/generalStack.h" "map/chainStack.h" map/circularQueue.h test/Qnode.h test/ListNode.h)