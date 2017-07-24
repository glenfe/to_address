# Copyright 2017 Glen Joseph Fernandes (glenjofe@gmail.com)
# Distributed under the Boost Software License, Version 1.0.

cmake_minimum_required(VERSION 3.1)

project(to_address)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(test)
