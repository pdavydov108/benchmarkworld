cmake_minimum_required(VERSION 3.0)
project(benchmarkworld)

#enable_language(ASM)

add_subdirectory(benchmark)

file(GLOB SOURCES *.cpp *.S)

include_directories(benchmark/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -masm=intel")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -march=native -g -flto")

add_executable(bench ${SOURCES})
target_link_libraries(bench benchmark)
