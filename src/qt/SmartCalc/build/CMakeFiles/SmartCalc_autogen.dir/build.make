# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/goinfre/longshot/homebrew/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /opt/goinfre/longshot/homebrew/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/longshot/projects/SmartCalc/src/qt/SmartCalc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/build

# Utility rule file for SmartCalc_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/SmartCalc_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SmartCalc_autogen.dir/progress.make

CMakeFiles/SmartCalc_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/longshot/projects/SmartCalc/src/qt/SmartCalc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target SmartCalc"
	/opt/goinfre/longshot/homebrew/Cellar/cmake/3.25.1/bin/cmake -E cmake_autogen /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/build/CMakeFiles/SmartCalc_autogen.dir/AutogenInfo.json ""

SmartCalc_autogen: CMakeFiles/SmartCalc_autogen
SmartCalc_autogen: CMakeFiles/SmartCalc_autogen.dir/build.make
.PHONY : SmartCalc_autogen

# Rule to build all files generated by this target.
CMakeFiles/SmartCalc_autogen.dir/build: SmartCalc_autogen
.PHONY : CMakeFiles/SmartCalc_autogen.dir/build

CMakeFiles/SmartCalc_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SmartCalc_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SmartCalc_autogen.dir/clean

CMakeFiles/SmartCalc_autogen.dir/depend:
	cd /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/longshot/projects/SmartCalc/src/qt/SmartCalc /Users/longshot/projects/SmartCalc/src/qt/SmartCalc /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/build /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/build /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/build/CMakeFiles/SmartCalc_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SmartCalc_autogen.dir/depend

