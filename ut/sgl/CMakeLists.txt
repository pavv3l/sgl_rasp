set(APP_NAME SGL_UT)
project(${APP_NAME})

aux_source_directory(src SRC_FILES)
add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE SGL_LIB)
target_link_libraries(${APP_NAME} PRIVATE gtest)
target_link_libraries(${APP_NAME} PRIVATE gmock)
target_link_libraries(${APP_NAME} PRIVATE gmock_main)
target_include_directories(${APP_NAME} PUBLIC include)