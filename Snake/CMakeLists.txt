# CMakeList.txt : CMake project for Snake, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Snake "Snake.cpp" "Snake.h" "SnakeFood.h" "Game.h")

#Include Raylib headers
target_include_directories(Snake PRIVATE "${CMAKE_SOURCE_DIR}/Dependencies/src")

#Link raylib statically
target_link_directories(Snake PRIVATE  "${CMAKE_SOURCE_DIR}/Dependencies")

target_link_libraries(Snake raylib opengl32 gdi32 winmm)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Snake PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
