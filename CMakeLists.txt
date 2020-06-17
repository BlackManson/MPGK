cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled Program.cpp Program.h Wektor.h Macierz.h Przeksztalcenia.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(untitled ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
set(FREEGLUT_INCLUDE_DIRS freeglut/include)
set(FREEGLUT_LIBRARY_DIRS freeglut/lib)
set(FREEGLUT_LIBRARIES freeglut)

find_package(GLEW REQUIRED)
target_link_libraries(untitled GLEW::GLEW)