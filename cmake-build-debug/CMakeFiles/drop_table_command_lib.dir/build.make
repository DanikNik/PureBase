# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ivanmorozov/BMSTU/technopark/cpp/PureBase

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ivanmorozov/BMSTU/technopark/cpp/PureBase/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/drop_table_command_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/drop_table_command_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/drop_table_command_lib.dir/flags.make

CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.o: CMakeFiles/drop_table_command_lib.dir/flags.make
CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.o: ../DropTableCommand/drop_table_command.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivanmorozov/BMSTU/technopark/cpp/PureBase/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.o -c /Users/ivanmorozov/BMSTU/technopark/cpp/PureBase/DropTableCommand/drop_table_command.cc

CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivanmorozov/BMSTU/technopark/cpp/PureBase/DropTableCommand/drop_table_command.cc > CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.i

CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivanmorozov/BMSTU/technopark/cpp/PureBase/DropTableCommand/drop_table_command.cc -o CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.s

# Object files for target drop_table_command_lib
drop_table_command_lib_OBJECTS = \
"CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.o"

# External object files for target drop_table_command_lib
drop_table_command_lib_EXTERNAL_OBJECTS =

libdrop_table_command_lib.a: CMakeFiles/drop_table_command_lib.dir/DropTableCommand/drop_table_command.cc.o
libdrop_table_command_lib.a: CMakeFiles/drop_table_command_lib.dir/build.make
libdrop_table_command_lib.a: CMakeFiles/drop_table_command_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ivanmorozov/BMSTU/technopark/cpp/PureBase/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdrop_table_command_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/drop_table_command_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/drop_table_command_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/drop_table_command_lib.dir/build: libdrop_table_command_lib.a

.PHONY : CMakeFiles/drop_table_command_lib.dir/build

CMakeFiles/drop_table_command_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/drop_table_command_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/drop_table_command_lib.dir/clean

CMakeFiles/drop_table_command_lib.dir/depend:
	cd /Users/ivanmorozov/BMSTU/technopark/cpp/PureBase/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivanmorozov/BMSTU/technopark/cpp/PureBase /Users/ivanmorozov/BMSTU/technopark/cpp/PureBase /Users/ivanmorozov/BMSTU/technopark/cpp/PureBase/cmake-build-debug /Users/ivanmorozov/BMSTU/technopark/cpp/PureBase/cmake-build-debug /Users/ivanmorozov/BMSTU/technopark/cpp/PureBase/cmake-build-debug/CMakeFiles/drop_table_command_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/drop_table_command_lib.dir/depend

