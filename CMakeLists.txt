cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME Roguelite)
project (${PROJECT_NAME})

# Required libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 3.2 REQUIRED)

# Store all files in src and include in variables 
file(GLOB_RECURSE Game_SOURCE "src/*.cpp")
file(GLOB_RECURSE Game_HEADERS "include/*.h")

# Add all header files in a list
set(Game_INCLUDE_DIRS "")
foreach (_headerFile ${Game_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Game_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Game_INCLUDE_DIRS)

# Include header files and compile source files into an executable
include_directories(${Game_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} ${Game_SOURCE})

# Link OpenGL, GL, and GLU (legacy, no need to include) libraries
#target_include_directories(${PROJECT_NAME} ${OPENGL_INCLUDE_DIR}) # For some reason this does not work, read over documentation later
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})
#target_link_libraries(${PROJECT_NAME} ${OPENGL_glu_LIBRARY})

# Set to make with debugging symbols "-g" and all warnings "-Wall"
set(CMAKE_CXX_FLAGS "-g -Wall -lglfw") # can be either "-lglfw" or "-lglfw3" depending on your GLFW installation

