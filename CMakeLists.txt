cmake_minimum_required(VERSION 3.10)
project(posits_in_linmath)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)
include_directories(softposit_cpp/include)
include_directories(softposit_cpp/src/include)

# Define include directories
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/softposit_cpp/include/
  ${CMAKE_CURRENT_SOURCE_DIR}/softposit_cpp/include/8086-SSE/
  ${CMAKE_CURRENT_SOURCE_DIR}/softposit_cpp/src/
)

# Add the softposit_cpp source files
file(GLOB SOFTPOSIT_SOURCES softposit_cpp/src/*.c)

# Add source files
add_executable(metrics src/metrics.cpp ${SOFTPOSIT_SOURCES})

# Link the softposit library
target_link_libraries(metrics m) # Link math library if needed