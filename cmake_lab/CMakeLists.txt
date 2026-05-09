cmake_minimum_required(VERSION 3.10)

project(Lab1_DataStructures)

# Include src directory for headers
include_directories(src)

# Create library from class files
add_library(DataLogic
    src/barrel.cpp
    src/matrix.cpp
    src/my_string.cpp
    src/rect.cpp
    src/text_wrapper.cpp
)

# Create executable from main file
add_executable(lab1 src/main.cpp)

# Link library to executable
target_link_libraries(lab1 PRIVATE DataLogic)

# Enable testing
enable_testing()
add_subdirectory(tests)