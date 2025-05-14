cmake_minimum_required(VERSION 3.16)
project(quant_config VERSION 1.0 LANGUAGES CXX)

# Header-only library
add_library(quant_config INTERFACE)

# Proper include path export for FetchContent usage
target_include_directories(quant_config INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
