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
include libs/pigpio/CMakeFiles/pigpiod_if.dir/depend.make

# Include the progress variables for this target.
include libs/pigpio/CMakeFiles/pigpiod_if.dir/progress.make

# Include the compile flags for this target's objects.
include libs/pigpio/CMakeFiles/pigpiod_if.dir/flags.make

libs/pigpio/CMakeFiles/pigpiod_if.dir/pigpiod_if.c.o: libs/pigpio/CMakeFiles/pigpiod_if.dir/flags.make
libs/pigpio/CMakeFiles/pigpiod_if.dir/pigpiod_if.c.o: ../libs/pigpio/pigpiod_if.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nte/CLionProjects/SGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/pigpio/CMakeFiles/pigpiod_if.dir/pigpiod_if.c.o"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pigpiod_if.dir/pigpiod_if.c.o -c /home/nte/CLionProjects/SGL/libs/pigpio/pigpiod_if.c

libs/pigpio/CMakeFiles/pigpiod_if.dir/pigpiod_if.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pigpiod_if.dir/pigpiod_if.c.i"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nte/CLionProjects/SGL/libs/pigpio/pigpiod_if.c > CMakeFiles/pigpiod_if.dir/pigpiod_if.c.i

libs/pigpio/CMakeFiles/pigpiod_if.dir/pigpiod_if.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pigpiod_if.dir/pigpiod_if.c.s"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nte/CLionProjects/SGL/libs/pigpio/pigpiod_if.c -o CMakeFiles/pigpiod_if.dir/pigpiod_if.c.s

libs/pigpio/CMakeFiles/pigpiod_if.dir/command.c.o: libs/pigpio/CMakeFiles/pigpiod_if.dir/flags.make
libs/pigpio/CMakeFiles/pigpiod_if.dir/command.c.o: ../libs/pigpio/command.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nte/CLionProjects/SGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libs/pigpio/CMakeFiles/pigpiod_if.dir/command.c.o"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pigpiod_if.dir/command.c.o -c /home/nte/CLionProjects/SGL/libs/pigpio/command.c

libs/pigpio/CMakeFiles/pigpiod_if.dir/command.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pigpiod_if.dir/command.c.i"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nte/CLionProjects/SGL/libs/pigpio/command.c > CMakeFiles/pigpiod_if.dir/command.c.i

libs/pigpio/CMakeFiles/pigpiod_if.dir/command.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pigpiod_if.dir/command.c.s"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nte/CLionProjects/SGL/libs/pigpio/command.c -o CMakeFiles/pigpiod_if.dir/command.c.s

# Object files for target pigpiod_if
pigpiod_if_OBJECTS = \
"CMakeFiles/pigpiod_if.dir/pigpiod_if.c.o" \
"CMakeFiles/pigpiod_if.dir/command.c.o"

# External object files for target pigpiod_if
pigpiod_if_EXTERNAL_OBJECTS =

libs/pigpio/libpigpiod_if.so: libs/pigpio/CMakeFiles/pigpiod_if.dir/pigpiod_if.c.o
libs/pigpio/libpigpiod_if.so: libs/pigpio/CMakeFiles/pigpiod_if.dir/command.c.o
libs/pigpio/libpigpiod_if.so: libs/pigpio/CMakeFiles/pigpiod_if.dir/build.make
libs/pigpio/libpigpiod_if.so: libs/pigpio/CMakeFiles/pigpiod_if.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nte/CLionProjects/SGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library libpigpiod_if.so"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pigpiod_if.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/pigpio/CMakeFiles/pigpiod_if.dir/build: libs/pigpio/libpigpiod_if.so

.PHONY : libs/pigpio/CMakeFiles/pigpiod_if.dir/build

libs/pigpio/CMakeFiles/pigpiod_if.dir/clean:
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio && $(CMAKE_COMMAND) -P CMakeFiles/pigpiod_if.dir/cmake_clean.cmake
.PHONY : libs/pigpio/CMakeFiles/pigpiod_if.dir/clean

libs/pigpio/CMakeFiles/pigpiod_if.dir/depend:
	cd /home/nte/CLionProjects/SGL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nte/CLionProjects/SGL /home/nte/CLionProjects/SGL/libs/pigpio /home/nte/CLionProjects/SGL/cmake-build-debug /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio /home/nte/CLionProjects/SGL/cmake-build-debug/libs/pigpio/CMakeFiles/pigpiod_if.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/pigpio/CMakeFiles/pigpiod_if.dir/depend

