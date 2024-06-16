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
include tests/CMakeFiles/fsm_retx_win.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/fsm_retx_win.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/fsm_retx_win.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/fsm_retx_win.dir/flags.make

tests/CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.o: tests/CMakeFiles/fsm_retx_win.dir/flags.make
tests/CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.o: /home/gsh/csdiy/libsponge/tests/fsm_retx_win.cc
tests/CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.o: tests/CMakeFiles/fsm_retx_win.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gsh/csdiy/libsponge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.o"
	cd /home/gsh/csdiy/libsponge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.o -MF CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.o.d -o CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.o -c /home/gsh/csdiy/libsponge/tests/fsm_retx_win.cc

tests/CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.i"
	cd /home/gsh/csdiy/libsponge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gsh/csdiy/libsponge/tests/fsm_retx_win.cc > CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.i

tests/CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.s"
	cd /home/gsh/csdiy/libsponge/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gsh/csdiy/libsponge/tests/fsm_retx_win.cc -o CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.s

# Object files for target fsm_retx_win
fsm_retx_win_OBJECTS = \
"CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.o"

# External object files for target fsm_retx_win
fsm_retx_win_EXTERNAL_OBJECTS =

tests/fsm_retx_win: tests/CMakeFiles/fsm_retx_win.dir/fsm_retx_win.cc.o
tests/fsm_retx_win: tests/CMakeFiles/fsm_retx_win.dir/build.make
tests/fsm_retx_win: tests/libspongechecks.a
tests/fsm_retx_win: libsponge/libsponge.a
tests/fsm_retx_win: tests/CMakeFiles/fsm_retx_win.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gsh/csdiy/libsponge/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fsm_retx_win"
	cd /home/gsh/csdiy/libsponge/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fsm_retx_win.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/fsm_retx_win.dir/build: tests/fsm_retx_win
.PHONY : tests/CMakeFiles/fsm_retx_win.dir/build

tests/CMakeFiles/fsm_retx_win.dir/clean:
	cd /home/gsh/csdiy/libsponge/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/fsm_retx_win.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/fsm_retx_win.dir/clean

tests/CMakeFiles/fsm_retx_win.dir/depend:
	cd /home/gsh/csdiy/libsponge/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gsh/csdiy/libsponge /home/gsh/csdiy/libsponge/tests /home/gsh/csdiy/libsponge/build /home/gsh/csdiy/libsponge/build/tests /home/gsh/csdiy/libsponge/build/tests/CMakeFiles/fsm_retx_win.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/fsm_retx_win.dir/depend
