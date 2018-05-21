cmake_minimum_required (VERSION 3.1)
project(EnergyMonitor)

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wpedantic -Wextra -Werror")
set(CMAKE_CXX_STANDARD 11)

set(SOURCES
      ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
      ${CMAKE_CURRENT_SOURCE_DIR}/getnode.cpp
)

add_executable(energy-monitor ${SOURCES})