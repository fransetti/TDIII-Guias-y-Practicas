cmake_minimum_required(VERSION 3.14)
project(libro)

add_executable(
  main
  main.cpp
  Libro.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)