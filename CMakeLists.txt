cmake_minimum_required (VERSION 3.4.3)

project(pubsub)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-g -Wall -Werror)


file (GLOB SRC_FILES src/graph.cpp
                     src/main.cpp
                     src/qstack.cpp
                     src/server.cpp
                     src/trie.cpp)


add_executable(facebook ${SRC_FILES})
target_include_directories(facebook PRIVATE include)
target_link_libraries(facebook pthread)
