# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gsh/csdiy/libsponge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gsh/csdiy/libsponge/build

# Include any dependencies generated for this target.
include apps/CMakeFiles/tcp_benchmark.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include apps/CMakeFiles/tcp_benchmark.dir/compiler_depend.make

# Include the progress variables for this target.
include apps/CMakeFiles/tcp_benchmark.dir/progress.make

# Include the compile flags for this target's objects.
include apps/CMakeFiles/tcp_benchmark.dir/flags.make

apps/CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.o: apps/CMakeFiles/tcp_benchmark.dir/flags.make
apps/CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.o: /home/gsh/csdiy/libsponge/apps/tcp_benchmark.cc
apps/CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.o: apps/CMakeFiles/tcp_benchmark.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gsh/csdiy/libsponge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object apps/CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.o"
	cd /home/gsh/csdiy/libsponge/build/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT apps/CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.o -MF CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.o.d -o CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.o -c /home/gsh/csdiy/libsponge/apps/tcp_benchmark.cc

apps/CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.i"
	cd /home/gsh/csdiy/libsponge/build/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gsh/csdiy/libsponge/apps/tcp_benchmark.cc > CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.i

apps/CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.s"
	cd /home/gsh/csdiy/libsponge/build/apps && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gsh/csdiy/libsponge/apps/tcp_benchmark.cc -o CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.s

# Object files for target tcp_benchmark
tcp_benchmark_OBJECTS = \
"CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.o"

# External object files for target tcp_benchmark
tcp_benchmark_EXTERNAL_OBJECTS =

apps/tcp_benchmark: apps/CMakeFiles/tcp_benchmark.dir/tcp_benchmark.cc.o
apps/tcp_benchmark: apps/CMakeFiles/tcp_benchmark.dir/build.make
apps/tcp_benchmark: libsponge/libsponge.a
apps/tcp_benchmark: /usr/lib/x86_64-linux-gnu/libpthread.so
apps/tcp_benchmark: apps/CMakeFiles/tcp_benchmark.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gsh/csdiy/libsponge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tcp_benchmark"
	cd /home/gsh/csdiy/libsponge/build/apps && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tcp_benchmark.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
apps/CMakeFiles/tcp_benchmark.dir/build: apps/tcp_benchmark
.PHONY : apps/CMakeFiles/tcp_benchmark.dir/build

apps/CMakeFiles/tcp_benchmark.dir/clean:
	cd /home/gsh/csdiy/libsponge/build/apps && $(CMAKE_COMMAND) -P CMakeFiles/tcp_benchmark.dir/cmake_clean.cmake
.PHONY : apps/CMakeFiles/tcp_benchmark.dir/clean

apps/CMakeFiles/tcp_benchmark.dir/depend:
	cd /home/gsh/csdiy/libsponge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gsh/csdiy/libsponge /home/gsh/csdiy/libsponge/apps /home/gsh/csdiy/libsponge/build /home/gsh/csdiy/libsponge/build/apps /home/gsh/csdiy/libsponge/build/apps/CMakeFiles/tcp_benchmark.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : apps/CMakeFiles/tcp_benchmark.dir/depend

