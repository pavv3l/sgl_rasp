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
include libs/googletest/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include libs/googletest/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include libs/googletest/googletest/CMakeFiles/gtest.dir/flags.make

libs/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: libs/googletest/googletest/CMakeFiles/gtest.dir/flags.make
libs/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../libs/googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nte/CLionProjects/SGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/googletest/googletest && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/nte/CLionProjects/SGL/libs/googletest/googletest/src/gtest-all.cc

libs/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/googletest/googletest && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nte/CLionProjects/SGL/libs/googletest/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

libs/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/googletest/googletest && /home/nte/crosscompile/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++ --sysroot=/home/nte/crosscompile/sysroot-glibc-linaro-2.25-2019.12-arm-linux-gnueabihf $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nte/CLionProjects/SGL/libs/googletest/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtestd.a: libs/googletest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtestd.a: libs/googletest/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtestd.a: libs/googletest/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nte/CLionProjects/SGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgtestd.a"
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/googletest/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/googletest/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/googletest/googletest/CMakeFiles/gtest.dir/build: lib/libgtestd.a

.PHONY : libs/googletest/googletest/CMakeFiles/gtest.dir/build

libs/googletest/googletest/CMakeFiles/gtest.dir/clean:
	cd /home/nte/CLionProjects/SGL/cmake-build-debug/libs/googletest/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : libs/googletest/googletest/CMakeFiles/gtest.dir/clean

libs/googletest/googletest/CMakeFiles/gtest.dir/depend:
	cd /home/nte/CLionProjects/SGL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nte/CLionProjects/SGL /home/nte/CLionProjects/SGL/libs/googletest/googletest /home/nte/CLionProjects/SGL/cmake-build-debug /home/nte/CLionProjects/SGL/cmake-build-debug/libs/googletest/googletest /home/nte/CLionProjects/SGL/cmake-build-debug/libs/googletest/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/googletest/googletest/CMakeFiles/gtest.dir/depend

