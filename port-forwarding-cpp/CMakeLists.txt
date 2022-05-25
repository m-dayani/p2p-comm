cmake_minimum_required(VERSION 3.16)
project(p2p_messaging)

set(CMAKE_CXX_STANDARD 11)

#find_package(Boost REQUIRED Components system)

include_directories(
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/src
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)



add_library(${PROJECT_NAME} SHARED
        src/chat_message.hpp
        src/Client.cpp
        src/Client.h
        src/Server.cpp
        src/Server.h
)

target_link_libraries(${PROJECT_NAME}
        -lboost_system
        -lboost_thread
        -lboost_filesystem
        -lboost_serialization
        -lcrypto
        -lpthread
)

add_executable(chat_app src/chat_app.cpp)

add_executable(chat_client src/chat_client.cpp)
target_link_libraries(chat_client ${PROJECT_NAME})

add_executable(chat_server src/chat_server.cpp)
target_link_libraries(chat_server ${PROJECT_NAME})