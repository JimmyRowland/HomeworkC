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
CMAKE_SOURCE_DIR = /media/toor/storage/vsProject/clion/wallet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/toor/storage/vsProject/clion/wallet/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/wallet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wallet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wallet.dir/flags.make

CMakeFiles/wallet.dir/main1.cpp.o: CMakeFiles/wallet.dir/flags.make
CMakeFiles/wallet.dir/main1.cpp.o: ../main1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/toor/storage/vsProject/clion/wallet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wallet.dir/main1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wallet.dir/main1.cpp.o -c /media/toor/storage/vsProject/clion/wallet/main1.cpp

CMakeFiles/wallet.dir/main1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wallet.dir/main1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/toor/storage/vsProject/clion/wallet/main1.cpp > CMakeFiles/wallet.dir/main1.cpp.i

CMakeFiles/wallet.dir/main1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wallet.dir/main1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/toor/storage/vsProject/clion/wallet/main1.cpp -o CMakeFiles/wallet.dir/main1.cpp.s

CMakeFiles/wallet.dir/main1.cpp.o.requires:

.PHONY : CMakeFiles/wallet.dir/main1.cpp.o.requires

CMakeFiles/wallet.dir/main1.cpp.o.provides: CMakeFiles/wallet.dir/main1.cpp.o.requires
	$(MAKE) -f CMakeFiles/wallet.dir/build.make CMakeFiles/wallet.dir/main1.cpp.o.provides.build
.PHONY : CMakeFiles/wallet.dir/main1.cpp.o.provides

CMakeFiles/wallet.dir/main1.cpp.o.provides.build: CMakeFiles/wallet.dir/main1.cpp.o


CMakeFiles/wallet.dir/Wallet1.cpp.o: CMakeFiles/wallet.dir/flags.make
CMakeFiles/wallet.dir/Wallet1.cpp.o: ../Wallet1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/toor/storage/vsProject/clion/wallet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/wallet.dir/Wallet1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wallet.dir/Wallet1.cpp.o -c /media/toor/storage/vsProject/clion/wallet/Wallet1.cpp

CMakeFiles/wallet.dir/Wallet1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wallet.dir/Wallet1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/toor/storage/vsProject/clion/wallet/Wallet1.cpp > CMakeFiles/wallet.dir/Wallet1.cpp.i

CMakeFiles/wallet.dir/Wallet1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wallet.dir/Wallet1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/toor/storage/vsProject/clion/wallet/Wallet1.cpp -o CMakeFiles/wallet.dir/Wallet1.cpp.s

CMakeFiles/wallet.dir/Wallet1.cpp.o.requires:

.PHONY : CMakeFiles/wallet.dir/Wallet1.cpp.o.requires

CMakeFiles/wallet.dir/Wallet1.cpp.o.provides: CMakeFiles/wallet.dir/Wallet1.cpp.o.requires
	$(MAKE) -f CMakeFiles/wallet.dir/build.make CMakeFiles/wallet.dir/Wallet1.cpp.o.provides.build
.PHONY : CMakeFiles/wallet.dir/Wallet1.cpp.o.provides

CMakeFiles/wallet.dir/Wallet1.cpp.o.provides.build: CMakeFiles/wallet.dir/Wallet1.cpp.o


# Object files for target wallet
wallet_OBJECTS = \
"CMakeFiles/wallet.dir/main1.cpp.o" \
"CMakeFiles/wallet.dir/Wallet1.cpp.o"

# External object files for target wallet
wallet_EXTERNAL_OBJECTS =

wallet: CMakeFiles/wallet.dir/main1.cpp.o
wallet: CMakeFiles/wallet.dir/Wallet1.cpp.o
wallet: CMakeFiles/wallet.dir/build.make
wallet: CMakeFiles/wallet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/toor/storage/vsProject/clion/wallet/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable wallet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wallet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wallet.dir/build: wallet

.PHONY : CMakeFiles/wallet.dir/build

CMakeFiles/wallet.dir/requires: CMakeFiles/wallet.dir/main1.cpp.o.requires
CMakeFiles/wallet.dir/requires: CMakeFiles/wallet.dir/Wallet1.cpp.o.requires

.PHONY : CMakeFiles/wallet.dir/requires

CMakeFiles/wallet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wallet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wallet.dir/clean

CMakeFiles/wallet.dir/depend:
	cd /media/toor/storage/vsProject/clion/wallet/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/toor/storage/vsProject/clion/wallet /media/toor/storage/vsProject/clion/wallet /media/toor/storage/vsProject/clion/wallet/cmake-build-debug /media/toor/storage/vsProject/clion/wallet/cmake-build-debug /media/toor/storage/vsProject/clion/wallet/cmake-build-debug/CMakeFiles/wallet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wallet.dir/depend

