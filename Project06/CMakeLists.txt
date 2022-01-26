cmake_minimum_required(VERSION 3.20)
project(Project06 C)

set(CMAKE_C_STANDARD 99)

add_executable(Project06 C/tasks/src/Linkedlist.c  C/tasks/src/WordCounter.c C/tasks/src/wctest.c)

