# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/toor/jetbrain/clion-2017.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/toor/jetbrain/clion-2017.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/toor/storage/vsProject/clion/inventory_system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/toor/storage/vsProject/clion/inventory_system/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/inventory_system.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/inventory_system.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inventory_system.dir/flags.make

CMakeFiles/inventory_system.dir/main.cpp.o: CMakeFiles/inventory_system.dir/flags.make
CMakeFiles/inventory_system.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/toor/storage/vsProject/clion/inventory_system/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/inventory_system.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/inventory_system.dir/main.cpp.o -c /media/toor/storage/vsProject/clion/inventory_system/main.cpp

CMakeFiles/inventory_system.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inventory_system.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/toor/storage/vsProject/clion/inventory_system/main.cpp > CMakeFiles/inventory_system.dir/main.cpp.i

CMakeFiles/inventory_system.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inventory_system.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/toor/storage/vsProject/clion/inventory_system/main.cpp -o CMakeFiles/inventory_system.dir/main.cpp.s

CMakeFiles/inventory_system.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/inventory_system.dir/main.cpp.o.requires

CMakeFiles/inventory_system.dir/main.cpp.o.provides: CMakeFiles/inventory_system.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/inventory_system.dir/build.make CMakeFiles/inventory_system.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/inventory_system.dir/main.cpp.o.provides

CMakeFiles/inventory_system.dir/main.cpp.o.provides.build: CMakeFiles/inventory_system.dir/main.cpp.o


CMakeFiles/inventory_system.dir/inventory.cpp.o: CMakeFiles/inventory_system.dir/flags.make
CMakeFiles/inventory_system.dir/inventory.cpp.o: ../inventory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/toor/storage/vsProject/clion/inventory_system/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/inventory_system.dir/inventory.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/inventory_system.dir/inventory.cpp.o -c /media/toor/storage/vsProject/clion/inventory_system/inventory.cpp

CMakeFiles/inventory_system.dir/inventory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inventory_system.dir/inventory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/toor/storage/vsProject/clion/inventory_system/inventory.cpp > CMakeFiles/inventory_system.dir/inventory.cpp.i

CMakeFiles/inventory_system.dir/inventory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inventory_system.dir/inventory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/toor/storage/vsProject/clion/inventory_system/inventory.cpp -o CMakeFiles/inventory_system.dir/inventory.cpp.s

CMakeFiles/inventory_system.dir/inventory.cpp.o.requires:

.PHONY : CMakeFiles/inventory_system.dir/inventory.cpp.o.requires

CMakeFiles/inventory_system.dir/inventory.cpp.o.provides: CMakeFiles/inventory_system.dir/inventory.cpp.o.requires
	$(MAKE) -f CMakeFiles/inventory_system.dir/build.make CMakeFiles/inventory_system.dir/inventory.cpp.o.provides.build
.PHONY : CMakeFiles/inventory_system.dir/inventory.cpp.o.provides

CMakeFiles/inventory_system.dir/inventory.cpp.o.provides.build: CMakeFiles/inventory_system.dir/inventory.cpp.o


# Object files for target inventory_system
inventory_system_OBJECTS = \
"CMakeFiles/inventory_system.dir/main.cpp.o" \
"CMakeFiles/inventory_system.dir/inventory.cpp.o"

# External object files for target inventory_system
inventory_system_EXTERNAL_OBJECTS =

inventory_system: CMakeFiles/inventory_system.dir/main.cpp.o
inventory_system: CMakeFiles/inventory_system.dir/inventory.cpp.o
inventory_system: CMakeFiles/inventory_system.dir/build.make
inventory_system: CMakeFiles/inventory_system.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/toor/storage/vsProject/clion/inventory_system/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable inventory_system"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inventory_system.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inventory_system.dir/build: inventory_system

.PHONY : CMakeFiles/inventory_system.dir/build

CMakeFiles/inventory_system.dir/requires: CMakeFiles/inventory_system.dir/main.cpp.o.requires
CMakeFiles/inventory_system.dir/requires: CMakeFiles/inventory_system.dir/inventory.cpp.o.requires

.PHONY : CMakeFiles/inventory_system.dir/requires

CMakeFiles/inventory_system.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inventory_system.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inventory_system.dir/clean

CMakeFiles/inventory_system.dir/depend:
	cd /media/toor/storage/vsProject/clion/inventory_system/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/toor/storage/vsProject/clion/inventory_system /media/toor/storage/vsProject/clion/inventory_system /media/toor/storage/vsProject/clion/inventory_system/cmake-build-debug /media/toor/storage/vsProject/clion/inventory_system/cmake-build-debug /media/toor/storage/vsProject/clion/inventory_system/cmake-build-debug/CMakeFiles/inventory_system.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/inventory_system.dir/depend

