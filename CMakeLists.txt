cmake_minimum_required(VERSION 3.15...3.22)

project(DemoPowerPC LANGUAGES C)

enable_testing()

include(CheckIncludeFile)

# --- Detect CPU

message(STATUS "CPU ARCH ${CMAKE_HOST_SYSTEM_PROCESSOR}")

check_include_file(sys/platform/ppc.h HAS_PPC_H)
if(NOT HAS_PPC_H)
  message(FATAL_ERROR "PowerPC system header not available, is host using a PowerPC CPU?")
endif()

# --- examples

add_executable(demo_time demo_time.c)
add_test(NAME PPCtime COMMAND demo_time)
