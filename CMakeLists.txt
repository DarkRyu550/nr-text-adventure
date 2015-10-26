cmake_minimum_required(VERSION 3.1)

# Define C11 and C++14
set(CMAKE_C_STANDARD   11)
set(CMAKE_CXX_STANDARD 14)

# Include PkgConfig
find_package(PkgConfig REQUIRED)

###################
##  NrAdventure  ##
###################

# Define project
project(Adventure)

# Include Sources
include(Sources.cmake)

# Include JsonCpp
pkg_check_modules(JSON REQUIRED jsoncpp)

add_definitions(${JSON_CFLAGS} ${JSON_CFLAGS_OTHER})

link_libraries(${JSON_LIBRARIES})
link_directories(${JSON_LIBRARY_DIRS})

# Link executable
add_executable(Adventure ${Adventure_SOURCES})

# Copy all files within data to the current directory
add_custom_command(TARGET Adventure POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/data"
        ./)
