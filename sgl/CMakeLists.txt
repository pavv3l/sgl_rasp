set(LIB_NAME SGL_LIB)

project(${LIB_NAME})
add_subdirectory(fonts)

aux_source_directory(src SRC_FILES)
add_library(${LIB_NAME} STATIC ${SRC_FILES})
target_include_directories(${LIB_NAME} PUBLIC include)
target_link_libraries(${LIB_NAME} PUBLIC SGL_FONTS)