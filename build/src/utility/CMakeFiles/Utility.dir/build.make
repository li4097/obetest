# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/hgfs/share/objtest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/share/objtest/build

# Include any dependencies generated for this target.
include src/utility/CMakeFiles/Utility.dir/depend.make

# Include the progress variables for this target.
include src/utility/CMakeFiles/Utility.dir/progress.make

# Include the compile flags for this target's objects.
include src/utility/CMakeFiles/Utility.dir/flags.make

src/utility/CMakeFiles/Utility.dir/utility.cpp.o: src/utility/CMakeFiles/Utility.dir/flags.make
src/utility/CMakeFiles/Utility.dir/utility.cpp.o: ../src/utility/utility.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /mnt/hgfs/share/objtest/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/utility/CMakeFiles/Utility.dir/utility.cpp.o"
	cd /mnt/hgfs/share/objtest/build/src/utility && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Utility.dir/utility.cpp.o -c /mnt/hgfs/share/objtest/src/utility/utility.cpp

src/utility/CMakeFiles/Utility.dir/utility.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Utility.dir/utility.cpp.i"
	cd /mnt/hgfs/share/objtest/build/src/utility && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /mnt/hgfs/share/objtest/src/utility/utility.cpp > CMakeFiles/Utility.dir/utility.cpp.i

src/utility/CMakeFiles/Utility.dir/utility.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Utility.dir/utility.cpp.s"
	cd /mnt/hgfs/share/objtest/build/src/utility && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /mnt/hgfs/share/objtest/src/utility/utility.cpp -o CMakeFiles/Utility.dir/utility.cpp.s

src/utility/CMakeFiles/Utility.dir/utility.cpp.o.requires:
.PHONY : src/utility/CMakeFiles/Utility.dir/utility.cpp.o.requires

src/utility/CMakeFiles/Utility.dir/utility.cpp.o.provides: src/utility/CMakeFiles/Utility.dir/utility.cpp.o.requires
	$(MAKE) -f src/utility/CMakeFiles/Utility.dir/build.make src/utility/CMakeFiles/Utility.dir/utility.cpp.o.provides.build
.PHONY : src/utility/CMakeFiles/Utility.dir/utility.cpp.o.provides

src/utility/CMakeFiles/Utility.dir/utility.cpp.o.provides.build: src/utility/CMakeFiles/Utility.dir/utility.cpp.o

# Object files for target Utility
Utility_OBJECTS = \
"CMakeFiles/Utility.dir/utility.cpp.o"

# External object files for target Utility
Utility_EXTERNAL_OBJECTS =

../lib/libUtility.so: src/utility/CMakeFiles/Utility.dir/utility.cpp.o
../lib/libUtility.so: src/utility/CMakeFiles/Utility.dir/build.make
../lib/libUtility.so: src/utility/CMakeFiles/Utility.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../../lib/libUtility.so"
	cd /mnt/hgfs/share/objtest/build/src/utility && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Utility.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/utility/CMakeFiles/Utility.dir/build: ../lib/libUtility.so
.PHONY : src/utility/CMakeFiles/Utility.dir/build

src/utility/CMakeFiles/Utility.dir/requires: src/utility/CMakeFiles/Utility.dir/utility.cpp.o.requires
.PHONY : src/utility/CMakeFiles/Utility.dir/requires

src/utility/CMakeFiles/Utility.dir/clean:
	cd /mnt/hgfs/share/objtest/build/src/utility && $(CMAKE_COMMAND) -P CMakeFiles/Utility.dir/cmake_clean.cmake
.PHONY : src/utility/CMakeFiles/Utility.dir/clean

src/utility/CMakeFiles/Utility.dir/depend:
	cd /mnt/hgfs/share/objtest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/share/objtest /mnt/hgfs/share/objtest/src/utility /mnt/hgfs/share/objtest/build /mnt/hgfs/share/objtest/build/src/utility /mnt/hgfs/share/objtest/build/src/utility/CMakeFiles/Utility.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/utility/CMakeFiles/Utility.dir/depend
