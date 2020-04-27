cmake_minimum_required(VERSION 3.13.4)

 project(supermarket)

 set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

set(PQXX /usr/local/include/pqxx)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

file(GLOB_RECURSE SOURCE_FILES "main.cpp")


add_executable(supermarket ${SOURCE_FILES})




TARGET_LINK_LIBRARIES(supermarket  ${PQXX_LIB} ${PQ_LIB})
