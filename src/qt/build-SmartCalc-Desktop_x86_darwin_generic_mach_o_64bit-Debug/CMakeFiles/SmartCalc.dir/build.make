# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/longshot/projects/SmartCalc/src/qt/SmartCalc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug

# Include any dependencies generated for this target.
include CMakeFiles/SmartCalc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SmartCalc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SmartCalc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SmartCalc.dir/flags.make

CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o: SmartCalc_autogen/mocs_compilation.cpp
CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o -MF CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o -c /Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug/SmartCalc_autogen/mocs_compilation.cpp

CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug/SmartCalc_autogen/mocs_compilation.cpp > CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.i

CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug/SmartCalc_autogen/mocs_compilation.cpp -o CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.s

CMakeFiles/SmartCalc.dir/main.cpp.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/main.cpp.o: /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/main.cpp
CMakeFiles/SmartCalc.dir/main.cpp.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SmartCalc.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/main.cpp.o -MF CMakeFiles/SmartCalc.dir/main.cpp.o.d -o CMakeFiles/SmartCalc.dir/main.cpp.o -c /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/main.cpp

CMakeFiles/SmartCalc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SmartCalc.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/main.cpp > CMakeFiles/SmartCalc.dir/main.cpp.i

CMakeFiles/SmartCalc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SmartCalc.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/main.cpp -o CMakeFiles/SmartCalc.dir/main.cpp.s

CMakeFiles/SmartCalc.dir/mainwindow.cpp.o: CMakeFiles/SmartCalc.dir/flags.make
CMakeFiles/SmartCalc.dir/mainwindow.cpp.o: /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/mainwindow.cpp
CMakeFiles/SmartCalc.dir/mainwindow.cpp.o: CMakeFiles/SmartCalc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SmartCalc.dir/mainwindow.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SmartCalc.dir/mainwindow.cpp.o -MF CMakeFiles/SmartCalc.dir/mainwindow.cpp.o.d -o CMakeFiles/SmartCalc.dir/mainwindow.cpp.o -c /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/mainwindow.cpp

CMakeFiles/SmartCalc.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SmartCalc.dir/mainwindow.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/mainwindow.cpp > CMakeFiles/SmartCalc.dir/mainwindow.cpp.i

CMakeFiles/SmartCalc.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SmartCalc.dir/mainwindow.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/longshot/projects/SmartCalc/src/qt/SmartCalc/mainwindow.cpp -o CMakeFiles/SmartCalc.dir/mainwindow.cpp.s

# Object files for target SmartCalc
SmartCalc_OBJECTS = \
"CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/SmartCalc.dir/main.cpp.o" \
"CMakeFiles/SmartCalc.dir/mainwindow.cpp.o"

# External object files for target SmartCalc
SmartCalc_EXTERNAL_OBJECTS =

SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/SmartCalc_autogen/mocs_compilation.cpp.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/main.cpp.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/mainwindow.cpp.o
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/build.make
SmartCalc.app/Contents/MacOS/SmartCalc: /usr/local/lib/QtWidgets.framework/Versions/A/QtWidgets
SmartCalc.app/Contents/MacOS/SmartCalc: /usr/local/lib/QtGui.framework/Versions/A/QtGui
SmartCalc.app/Contents/MacOS/SmartCalc: /usr/local/lib/QtCore.framework/Versions/A/QtCore
SmartCalc.app/Contents/MacOS/SmartCalc: CMakeFiles/SmartCalc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable SmartCalc.app/Contents/MacOS/SmartCalc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SmartCalc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SmartCalc.dir/build: SmartCalc.app/Contents/MacOS/SmartCalc
.PHONY : CMakeFiles/SmartCalc.dir/build

CMakeFiles/SmartCalc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SmartCalc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SmartCalc.dir/clean

CMakeFiles/SmartCalc.dir/depend:
	cd /Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/longshot/projects/SmartCalc/src/qt/SmartCalc /Users/longshot/projects/SmartCalc/src/qt/SmartCalc /Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/longshot/projects/SmartCalc/src/qt/build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles/SmartCalc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SmartCalc.dir/depend

