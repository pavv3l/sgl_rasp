set(APP_NAME SGL_APP)
project(${APP_NAME})
aux_source_directory(src SRC_FILES)
add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE SGL_LIB_ILI9341)
target_include_directories(${APP_NAME} PUBLIC include)

install(TARGETS ${APPNAME}
        RUNTIME DESTINATION /home/nte/bin)