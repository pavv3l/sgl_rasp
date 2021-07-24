cmake_minimum_required(VERSION 3.19)
set(CMAKE_TOOLCHAIN_FILE "/home/nte/crosscompile/gcc-linaro-toolchain-file.cmake")
project(SGL LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
add_compile_options(-Wall -Wno-comment)

add_subdirectory(sgl)
add_subdirectory(drivers)
add_subdirectory(libs)
add_subdirectory(application)
add_subdirectory(ut)

add_custom_target(CreateInstaller
        COMMAND ${CMAKE_COMMAND} --build . --target install
        COMMENT "Running target install"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
