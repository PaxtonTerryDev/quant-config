cmake_minimum_required(VERSION 3.16)
project(quant_config VERSION 1.0 LANGUAGES CXX)

add_library(quant_config INTERFACE)

# This is key: this should point to the directory that contains the 'quant_config/' folder
target_include_directories(quant_config INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
