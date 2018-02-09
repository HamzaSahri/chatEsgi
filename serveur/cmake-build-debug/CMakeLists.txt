cmake_minimum_required(VERSION 3.8)
project(cmake_build_debug)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    cmake_install.cmake
    CMakeCache.txt
    connexionServeur
    connexionServeur.cbp
    Makefile)

add_executable(cmake_build_debug ${SOURCE_FILES})