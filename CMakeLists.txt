cmake_minimum_required(VERSION 3.12)
project(mailStone2)
set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")
set(CMAKE_CXX_STANDARD 14)

add_executable(mailStone2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManger.h FileCacheManager.cpp FileCacheManager.h State.cpp State.h ISearchable.h ISearcher.h Solution.h Problem.h BestFirstSerch.cpp BestFirstSerch.h Searcher.h DFS.cpp DFS.h stringReverser.cpp stringReverser.h HillClimbing.cpp HillClimbing.h BFS.cpp BFS.h Astar.cpp Astar.h matrix.cpp matrix.h StringConvertor.h matrixString.h)