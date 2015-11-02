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

# Include Gtkmm
set(USE_GTK false)
if(${USE_GTK})
    pkg_check_modules(GTK gtkmm-3.0)
    if(${GTK_FOUND})
        # Include Gtk source files
        include(GtkSources.cmake)

        # Add definitions
        add_definitions(${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})

        link_libraries(${GTK_LIBRARIES})
        link_directories(${GTK_LIBRARY_DIRS})

        # Define the GTK console as default
        set(Adventure_CONSOLE_CLASS ${Adventure_GTK_CONSOLE_CLASS})
        set(Adventure_CONSOLE_FILE  ${Adventure_GTK_CONSOLE_FILE})

        message("-- Using Embedded Terminal.")
    else(${GTK_FOUND})
        # Define system console as default
        set(Adventure_CONSOLE_CLASS ${Adventure_SYS_CONSOLE_CLASS})
        set(Adventure_CONSOLE_FILE  ${Adventure_SYS_CONSOLE_FILE})

        message("-- Cannot build Embedded Terminal, package \"gtkmm-3.0\" was not found. The game will be using Standard IO.")
    endif(${GTK_FOUND})
else(${USE_GTK})
    # Define system console as default
    set(Adventure_CONSOLE_CLASS ${Adventure_SYS_CONSOLE_CLASS})
    set(Adventure_CONSOLE_FILE  ${Adventure_SYS_CONSOLE_FILE})

    message("-- Embedded Terminal is disabled. The game will be using Standard IO.")
endif(${USE_GTK})

# Configure Metadata.h
configure_file (
  "${PROJECT_SOURCE_DIR}/src/MakeConsole.hh.in"
  "${PROJECT_BINARY_DIR}/MakeConsole.hh"
)
include_directories("${PROJECT_BINARY_DIR}")

# Link executable
add_executable(Adventure ${Adventure_SOURCES})

# Copy all files within data to the current directory
add_custom_command(TARGET Adventure POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/data"
        ./)
