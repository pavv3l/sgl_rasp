# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/nte/clion-2021.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nte/clion-2021.1.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nte/CLionProjects/SGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nte/CLionProjects/SGL/cmake-build-debug

# Include any dependencies generated for this target.
include libs/pigpio/CMakeFiles/pigpiod.dir/depend.make

# Include the progress variables for this target.
include libs/pigpio/CMakeFiles/pigpiod.dir/progress.make

# Include the compile flags for this target's objects.
include libs/pigpio/CMakeFiles/pigpiod.dir/flags.make

libs/pigpio/CMakeFiles/pigpiod.dir/pigpiod.c.o: libs/pigpio/CMakeFiles/pigpiod.dir/flags.make
libs/pigpio/CMakeFiles/pigpiod.dir/pigpiod.c.o: ../libs/pigpio/pigpiod.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nte/CLionProjects/SGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/pigpio/CMakeFiles/pigpiod.dir/pigpiod.c.o"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pigpiod.dir/pigpiod.c.o -c /home/nte/CLionProjects/SGL/libs/pigpio/pigpiod.c

libs/pigpio/CMakeFiles/pigpiod.dir/pigpiod.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pigpiod.dir/pigpiod.c.i"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nte/CLionProjects/SGL/libs/pigpio/pigpiod.c > CMakeFiles/pigpiod.dir/pigpiod.c.i

libs/pigpio/CMakeFiles/pigpiod.dir/pigpiod.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pigpiod.dir/pigpiod.c.s"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nte/CLionProjects/SGL/libs/pigpio/pigpiod.c -o CMakeFiles/pigpiod.dir/pigpiod.c.s

# Object files for target pigpiod
pigpiod_OBJECTS = \
"CMakeFiles/pigpiod.dir/pigpiod.c.o"

# External object files for target pigpiod
pigpiod_EXTERNAL_OBJECTS =

libs/pigpio/pigpiod: libs/pigpio/CMakeFiles/pigpiod.dir/pigpiod.c.o
libs/pigpio/pigpiod: libs/pigpio/CMakeFiles/pigpiod.dir/build.make
libs/pigpio/pigpiod: libs/pigpio/libpigpio.so
libs/pigpio/pigpiod: /home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf/usr/lib/librt.so
libs/pigpio/pigpiod: libs/pigpio/CMakeFiles/pigpiod.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nte/CLionProjects/SGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pigpiod"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pigpiod.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/pigpio/CMakeFiles/pigpiod.dir/build: libs/pigpio/pigpiod

.PHONY : libs/pigpio/CMakeFiles/pigpiod.dir/build

libs/pigpio/CMakeFiles/pigpiod.dir/clean:
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && $(CMAKE_COMMAND) -P CMakeFiles/pigpiod.dir/cmake_clean.cmake
.PHONY : libs/pigpio/CMakeFiles/pigpiod.dir/clean

libs/pigpio/CMakeFiles/pigpiod.dir/depend:
	cd /home/nte/CLionProjects/SGL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nte/CLionProjects/SGL /home/nte/CLionProjects/SGL/libs/pigpio /home/nte/CLionProjects/SGL/cmake-build-debug /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio/CMakeFiles/pigpiod.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/pigpio/CMakeFiles/pigpiod.dir/depend

