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

# Utility rule file for tidy_quiet_tests__send_window.cc.

# Include any custom commands dependencies for this target.
include CMakeFiles/tidy_quiet_tests__send_window.cc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tidy_quiet_tests__send_window.cc.dir/progress.make

CMakeFiles/tidy_quiet_tests__send_window.cc:
	clang-tidy -checks='*,-fuchsia-*,-hicpp-signed-bitwise,-google-build-using-namespace,-android*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-google-runtime-references,-readability-avoid-const-params-in-decls,-llvm-header-guard' -header-filter=.* -p=/home/gsh/csdiy/libsponge/build /home/gsh/csdiy/libsponge/tests/send_window.cc 2>/dev/null

tidy_quiet_tests__send_window.cc: CMakeFiles/tidy_quiet_tests__send_window.cc
tidy_quiet_tests__send_window.cc: CMakeFiles/tidy_quiet_tests__send_window.cc.dir/build.make
.PHONY : tidy_quiet_tests__send_window.cc

# Rule to build all files generated by this target.
CMakeFiles/tidy_quiet_tests__send_window.cc.dir/build: tidy_quiet_tests__send_window.cc
.PHONY : CMakeFiles/tidy_quiet_tests__send_window.cc.dir/build

CMakeFiles/tidy_quiet_tests__send_window.cc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tidy_quiet_tests__send_window.cc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tidy_quiet_tests__send_window.cc.dir/clean

CMakeFiles/tidy_quiet_tests__send_window.cc.dir/depend:
	cd /home/gsh/csdiy/libsponge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gsh/csdiy/libsponge /home/gsh/csdiy/libsponge /home/gsh/csdiy/libsponge/build /home/gsh/csdiy/libsponge/build /home/gsh/csdiy/libsponge/build/CMakeFiles/tidy_quiet_tests__send_window.cc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tidy_quiet_tests__send_window.cc.dir/depend

