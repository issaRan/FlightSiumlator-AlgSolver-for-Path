cmake_minimum_required(VERSION 3.12)
project(mailStone2)

set(CMAKE_CXX_STANDARD 14)

add_executable(mailStone2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManger.cpp CacheManger.h FileCacheManager.cpp FileCacheManager.h)