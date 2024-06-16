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

# Utility rule file for check_lab2.

# Include any custom commands dependencies for this target.
include CMakeFiles/check_lab2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/check_lab2.dir/progress.make

CMakeFiles/check_lab2:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/gsh/csdiy/libsponge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Testing the TCP receiver..."
	/usr/local/bin/ctest --output-on-failure --timeout 10 -R 't_recv_|t_wrapping_|t_strm_reassem_|t_byte_stream|_dt'

check_lab2: CMakeFiles/check_lab2
check_lab2: CMakeFiles/check_lab2.dir/build.make
.PHONY : check_lab2

# Rule to build all files generated by this target.
CMakeFiles/check_lab2.dir/build: check_lab2
.PHONY : CMakeFiles/check_lab2.dir/build

CMakeFiles/check_lab2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/check_lab2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/check_lab2.dir/clean

CMakeFiles/check_lab2.dir/depend:
	cd /home/gsh/csdiy/libsponge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gsh/csdiy/libsponge /home/gsh/csdiy/libsponge /home/gsh/csdiy/libsponge/build /home/gsh/csdiy/libsponge/build /home/gsh/csdiy/libsponge/build/CMakeFiles/check_lab2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/check_lab2.dir/depend
