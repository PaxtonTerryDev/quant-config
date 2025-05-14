cmake_minimum_required(VERSION 3.16)
project(quant_config VERSION 1.0 LANGUAGES CXX)

add_library(quant_config INTERFACE)
target_include_directories(quant_config INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
