# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /root/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7442.42/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /root/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.7442.42/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/cpp/newa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/cpp/newa/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/newa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/newa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/newa.dir/flags.make

CMakeFiles/newa.dir/main.cpp.o: CMakeFiles/newa.dir/flags.make
CMakeFiles/newa.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cpp/newa/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/newa.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/newa.dir/main.cpp.o -c /root/cpp/newa/main.cpp

CMakeFiles/newa.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/newa.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/cpp/newa/main.cpp > CMakeFiles/newa.dir/main.cpp.i

CMakeFiles/newa.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/newa.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/cpp/newa/main.cpp -o CMakeFiles/newa.dir/main.cpp.s

# Object files for target newa
newa_OBJECTS = \
"CMakeFiles/newa.dir/main.cpp.o"

# External object files for target newa
newa_EXTERNAL_OBJECTS =

newa: CMakeFiles/newa.dir/main.cpp.o
newa: CMakeFiles/newa.dir/build.make
newa: CMakeFiles/newa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/cpp/newa/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable newa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/newa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/newa.dir/build: newa

.PHONY : CMakeFiles/newa.dir/build

CMakeFiles/newa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/newa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/newa.dir/clean

CMakeFiles/newa.dir/depend:
	cd /root/cpp/newa/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/cpp/newa /root/cpp/newa /root/cpp/newa/cmake-build-debug /root/cpp/newa/cmake-build-debug /root/cpp/newa/cmake-build-debug/CMakeFiles/newa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/newa.dir/depend

