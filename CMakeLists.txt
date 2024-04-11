cmake_minimum_required(VERSION 3.22)
project(state_machine)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)

# List of source files
set(SOURCE_FILES
        main.cpp
        src/input/input.cpp
        src/Elevator/Elevator.cpp
        # src/Program/program.cpp
)

add_executable(state_machine ${SOURCE_FILES})

# Add sanitizer flags for Debug build type
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer")



