# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = "/media/toor/storage/ubuntu download/clion-2016.3.5/bin/cmake/bin/cmake"

# The command to remove a file.
RM = "/media/toor/storage/ubuntu download/clion-2016.3.5/bin/cmake/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/toor/storage/vsProject/clion/ClosestValue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/toor/storage/vsProject/clion/ClosestValue/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ClosestValue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ClosestValue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ClosestValue.dir/flags.make

CMakeFiles/ClosestValue.dir/main.cpp.o: CMakeFiles/ClosestValue.dir/flags.make
CMakeFiles/ClosestValue.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/toor/storage/vsProject/clion/ClosestValue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ClosestValue.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ClosestValue.dir/main.cpp.o -c /media/toor/storage/vsProject/clion/ClosestValue/main.cpp

CMakeFiles/ClosestValue.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClosestValue.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/toor/storage/vsProject/clion/ClosestValue/main.cpp > CMakeFiles/ClosestValue.dir/main.cpp.i

CMakeFiles/ClosestValue.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClosestValue.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/toor/storage/vsProject/clion/ClosestValue/main.cpp -o CMakeFiles/ClosestValue.dir/main.cpp.s

CMakeFiles/ClosestValue.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ClosestValue.dir/main.cpp.o.requires

CMakeFiles/ClosestValue.dir/main.cpp.o.provides: CMakeFiles/ClosestValue.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ClosestValue.dir/build.make CMakeFiles/ClosestValue.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ClosestValue.dir/main.cpp.o.provides

CMakeFiles/ClosestValue.dir/main.cpp.o.provides.build: CMakeFiles/ClosestValue.dir/main.cpp.o


# Object files for target ClosestValue
ClosestValue_OBJECTS = \
"CMakeFiles/ClosestValue.dir/main.cpp.o"

# External object files for target ClosestValue
ClosestValue_EXTERNAL_OBJECTS =

ClosestValue: CMakeFiles/ClosestValue.dir/main.cpp.o
ClosestValue: CMakeFiles/ClosestValue.dir/build.make
ClosestValue: CMakeFiles/ClosestValue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/toor/storage/vsProject/clion/ClosestValue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ClosestValue"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ClosestValue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ClosestValue.dir/build: ClosestValue

.PHONY : CMakeFiles/ClosestValue.dir/build

CMakeFiles/ClosestValue.dir/requires: CMakeFiles/ClosestValue.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ClosestValue.dir/requires

CMakeFiles/ClosestValue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ClosestValue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ClosestValue.dir/clean

CMakeFiles/ClosestValue.dir/depend:
	cd /media/toor/storage/vsProject/clion/ClosestValue/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/toor/storage/vsProject/clion/ClosestValue /media/toor/storage/vsProject/clion/ClosestValue /media/toor/storage/vsProject/clion/ClosestValue/cmake-build-debug /media/toor/storage/vsProject/clion/ClosestValue/cmake-build-debug /media/toor/storage/vsProject/clion/ClosestValue/cmake-build-debug/CMakeFiles/ClosestValue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ClosestValue.dir/depend

