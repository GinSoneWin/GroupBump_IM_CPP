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
CMAKE_COMMAND = /usr/local/clion/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/clion/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gin/ClionProjects/GroupBump_IM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gin/ClionProjects/GroupBump_IM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/testThread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testThread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testThread.dir/flags.make

CMakeFiles/testThread.dir/testThread.cpp.o: CMakeFiles/testThread.dir/flags.make
CMakeFiles/testThread.dir/testThread.cpp.o: ../testThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gin/ClionProjects/GroupBump_IM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testThread.dir/testThread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testThread.dir/testThread.cpp.o -c /home/gin/ClionProjects/GroupBump_IM/testThread.cpp

CMakeFiles/testThread.dir/testThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testThread.dir/testThread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gin/ClionProjects/GroupBump_IM/testThread.cpp > CMakeFiles/testThread.dir/testThread.cpp.i

CMakeFiles/testThread.dir/testThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testThread.dir/testThread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gin/ClionProjects/GroupBump_IM/testThread.cpp -o CMakeFiles/testThread.dir/testThread.cpp.s

CMakeFiles/testThread.dir/testThread.cpp.o.requires:

.PHONY : CMakeFiles/testThread.dir/testThread.cpp.o.requires

CMakeFiles/testThread.dir/testThread.cpp.o.provides: CMakeFiles/testThread.dir/testThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/testThread.dir/build.make CMakeFiles/testThread.dir/testThread.cpp.o.provides.build
.PHONY : CMakeFiles/testThread.dir/testThread.cpp.o.provides

CMakeFiles/testThread.dir/testThread.cpp.o.provides.build: CMakeFiles/testThread.dir/testThread.cpp.o


CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o: CMakeFiles/testThread.dir/flags.make
CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o: ../src/util/thread/AbstractThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gin/ClionProjects/GroupBump_IM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o -c /home/gin/ClionProjects/GroupBump_IM/src/util/thread/AbstractThread.cpp

CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gin/ClionProjects/GroupBump_IM/src/util/thread/AbstractThread.cpp > CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.i

CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gin/ClionProjects/GroupBump_IM/src/util/thread/AbstractThread.cpp -o CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.s

CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o.requires:

.PHONY : CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o.requires

CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o.provides: CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o.requires
	$(MAKE) -f CMakeFiles/testThread.dir/build.make CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o.provides.build
.PHONY : CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o.provides

CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o.provides.build: CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o


CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o: CMakeFiles/testThread.dir/flags.make
CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o: ../src/util/thread/AbstractThreadGroup.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gin/ClionProjects/GroupBump_IM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o -c /home/gin/ClionProjects/GroupBump_IM/src/util/thread/AbstractThreadGroup.cpp

CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gin/ClionProjects/GroupBump_IM/src/util/thread/AbstractThreadGroup.cpp > CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.i

CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gin/ClionProjects/GroupBump_IM/src/util/thread/AbstractThreadGroup.cpp -o CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.s

CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o.requires:

.PHONY : CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o.requires

CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o.provides: CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o.requires
	$(MAKE) -f CMakeFiles/testThread.dir/build.make CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o.provides.build
.PHONY : CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o.provides

CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o.provides.build: CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o


CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o: CMakeFiles/testThread.dir/flags.make
CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o: ../src/util/thread/BasicThreadGroup.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gin/ClionProjects/GroupBump_IM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o -c /home/gin/ClionProjects/GroupBump_IM/src/util/thread/BasicThreadGroup.cpp

CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gin/ClionProjects/GroupBump_IM/src/util/thread/BasicThreadGroup.cpp > CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.i

CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gin/ClionProjects/GroupBump_IM/src/util/thread/BasicThreadGroup.cpp -o CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.s

CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o.requires:

.PHONY : CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o.requires

CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o.provides: CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o.requires
	$(MAKE) -f CMakeFiles/testThread.dir/build.make CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o.provides.build
.PHONY : CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o.provides

CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o.provides.build: CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o


CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o: CMakeFiles/testThread.dir/flags.make
CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o: ../src/util/thread/ThreadGuard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gin/ClionProjects/GroupBump_IM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o -c /home/gin/ClionProjects/GroupBump_IM/src/util/thread/ThreadGuard.cpp

CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gin/ClionProjects/GroupBump_IM/src/util/thread/ThreadGuard.cpp > CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.i

CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gin/ClionProjects/GroupBump_IM/src/util/thread/ThreadGuard.cpp -o CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.s

CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o.requires:

.PHONY : CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o.requires

CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o.provides: CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o.requires
	$(MAKE) -f CMakeFiles/testThread.dir/build.make CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o.provides.build
.PHONY : CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o.provides

CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o.provides.build: CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o


# Object files for target testThread
testThread_OBJECTS = \
"CMakeFiles/testThread.dir/testThread.cpp.o" \
"CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o" \
"CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o" \
"CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o" \
"CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o"

# External object files for target testThread
testThread_EXTERNAL_OBJECTS =

testThread: CMakeFiles/testThread.dir/testThread.cpp.o
testThread: CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o
testThread: CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o
testThread: CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o
testThread: CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o
testThread: CMakeFiles/testThread.dir/build.make
testThread: CMakeFiles/testThread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gin/ClionProjects/GroupBump_IM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable testThread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testThread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testThread.dir/build: testThread

.PHONY : CMakeFiles/testThread.dir/build

CMakeFiles/testThread.dir/requires: CMakeFiles/testThread.dir/testThread.cpp.o.requires
CMakeFiles/testThread.dir/requires: CMakeFiles/testThread.dir/src/util/thread/AbstractThread.cpp.o.requires
CMakeFiles/testThread.dir/requires: CMakeFiles/testThread.dir/src/util/thread/AbstractThreadGroup.cpp.o.requires
CMakeFiles/testThread.dir/requires: CMakeFiles/testThread.dir/src/util/thread/BasicThreadGroup.cpp.o.requires
CMakeFiles/testThread.dir/requires: CMakeFiles/testThread.dir/src/util/thread/ThreadGuard.cpp.o.requires

.PHONY : CMakeFiles/testThread.dir/requires

CMakeFiles/testThread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testThread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testThread.dir/clean

CMakeFiles/testThread.dir/depend:
	cd /home/gin/ClionProjects/GroupBump_IM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gin/ClionProjects/GroupBump_IM /home/gin/ClionProjects/GroupBump_IM /home/gin/ClionProjects/GroupBump_IM/cmake-build-debug /home/gin/ClionProjects/GroupBump_IM/cmake-build-debug /home/gin/ClionProjects/GroupBump_IM/cmake-build-debug/CMakeFiles/testThread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testThread.dir/depend
