project(pigpio LANGUAGES C VERSION 0.71)
set(LIBNAME PIGPIO)

list (APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

find_package(Threads REQUIRED)
find_package(RT REQUIRED)

add_compile_options(-Wall)

# libpigpio.(so|a)
add_library(${LIBNAME} STATIC pigpio.c command.c custom.cext)
target_link_libraries(${LIBNAME} RT::RT Threads::Threads)
target_include_directories(${LIBNAME} INTERFACE .)