# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/kierian/Téléchargements/CLion-2020.3.1/clion-2020.3.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kierian/Téléchargements/CLion-2020.3.1/clion-2020.3.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kierian/CLionProjects/battleship

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kierian/CLionProjects/battleship/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/battleship.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/battleship.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/battleship.dir/flags.make

CMakeFiles/battleship.dir/src/CBateau.cpp.o: CMakeFiles/battleship.dir/flags.make
CMakeFiles/battleship.dir/src/CBateau.cpp.o: ../src/CBateau.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kierian/CLionProjects/battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/battleship.dir/src/CBateau.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/battleship.dir/src/CBateau.cpp.o -c /home/kierian/CLionProjects/battleship/src/CBateau.cpp

CMakeFiles/battleship.dir/src/CBateau.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battleship.dir/src/CBateau.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kierian/CLionProjects/battleship/src/CBateau.cpp > CMakeFiles/battleship.dir/src/CBateau.cpp.i

CMakeFiles/battleship.dir/src/CBateau.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battleship.dir/src/CBateau.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kierian/CLionProjects/battleship/src/CBateau.cpp -o CMakeFiles/battleship.dir/src/CBateau.cpp.s

CMakeFiles/battleship.dir/src/testCBateau.cpp.o: CMakeFiles/battleship.dir/flags.make
CMakeFiles/battleship.dir/src/testCBateau.cpp.o: ../src/testCBateau.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kierian/CLionProjects/battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/battleship.dir/src/testCBateau.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/battleship.dir/src/testCBateau.cpp.o -c /home/kierian/CLionProjects/battleship/src/testCBateau.cpp

CMakeFiles/battleship.dir/src/testCBateau.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battleship.dir/src/testCBateau.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kierian/CLionProjects/battleship/src/testCBateau.cpp > CMakeFiles/battleship.dir/src/testCBateau.cpp.i

CMakeFiles/battleship.dir/src/testCBateau.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battleship.dir/src/testCBateau.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kierian/CLionProjects/battleship/src/testCBateau.cpp -o CMakeFiles/battleship.dir/src/testCBateau.cpp.s

CMakeFiles/battleship.dir/src/CArmada.cpp.o: CMakeFiles/battleship.dir/flags.make
CMakeFiles/battleship.dir/src/CArmada.cpp.o: ../src/CArmada.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kierian/CLionProjects/battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/battleship.dir/src/CArmada.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/battleship.dir/src/CArmada.cpp.o -c /home/kierian/CLionProjects/battleship/src/CArmada.cpp

CMakeFiles/battleship.dir/src/CArmada.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battleship.dir/src/CArmada.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kierian/CLionProjects/battleship/src/CArmada.cpp > CMakeFiles/battleship.dir/src/CArmada.cpp.i

CMakeFiles/battleship.dir/src/CArmada.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battleship.dir/src/CArmada.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kierian/CLionProjects/battleship/src/CArmada.cpp -o CMakeFiles/battleship.dir/src/CArmada.cpp.s

CMakeFiles/battleship.dir/src/testCArmada.cpp.o: CMakeFiles/battleship.dir/flags.make
CMakeFiles/battleship.dir/src/testCArmada.cpp.o: ../src/testCArmada.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kierian/CLionProjects/battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/battleship.dir/src/testCArmada.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/battleship.dir/src/testCArmada.cpp.o -c /home/kierian/CLionProjects/battleship/src/testCArmada.cpp

CMakeFiles/battleship.dir/src/testCArmada.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battleship.dir/src/testCArmada.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kierian/CLionProjects/battleship/src/testCArmada.cpp > CMakeFiles/battleship.dir/src/testCArmada.cpp.i

CMakeFiles/battleship.dir/src/testCArmada.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battleship.dir/src/testCArmada.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kierian/CLionProjects/battleship/src/testCArmada.cpp -o CMakeFiles/battleship.dir/src/testCArmada.cpp.s

CMakeFiles/battleship.dir/src/CGui.cpp.o: CMakeFiles/battleship.dir/flags.make
CMakeFiles/battleship.dir/src/CGui.cpp.o: ../src/CGui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kierian/CLionProjects/battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/battleship.dir/src/CGui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/battleship.dir/src/CGui.cpp.o -c /home/kierian/CLionProjects/battleship/src/CGui.cpp

CMakeFiles/battleship.dir/src/CGui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battleship.dir/src/CGui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kierian/CLionProjects/battleship/src/CGui.cpp > CMakeFiles/battleship.dir/src/CGui.cpp.i

CMakeFiles/battleship.dir/src/CGui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battleship.dir/src/CGui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kierian/CLionProjects/battleship/src/CGui.cpp -o CMakeFiles/battleship.dir/src/CGui.cpp.s

CMakeFiles/battleship.dir/src/testCGui.cpp.o: CMakeFiles/battleship.dir/flags.make
CMakeFiles/battleship.dir/src/testCGui.cpp.o: ../src/testCGui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kierian/CLionProjects/battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/battleship.dir/src/testCGui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/battleship.dir/src/testCGui.cpp.o -c /home/kierian/CLionProjects/battleship/src/testCGui.cpp

CMakeFiles/battleship.dir/src/testCGui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battleship.dir/src/testCGui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kierian/CLionProjects/battleship/src/testCGui.cpp > CMakeFiles/battleship.dir/src/testCGui.cpp.i

CMakeFiles/battleship.dir/src/testCGui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battleship.dir/src/testCGui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kierian/CLionProjects/battleship/src/testCGui.cpp -o CMakeFiles/battleship.dir/src/testCGui.cpp.s

# Object files for target battleship
battleship_OBJECTS = \
"CMakeFiles/battleship.dir/src/CBateau.cpp.o" \
"CMakeFiles/battleship.dir/src/testCBateau.cpp.o" \
"CMakeFiles/battleship.dir/src/CArmada.cpp.o" \
"CMakeFiles/battleship.dir/src/testCArmada.cpp.o" \
"CMakeFiles/battleship.dir/src/CGui.cpp.o" \
"CMakeFiles/battleship.dir/src/testCGui.cpp.o"

# External object files for target battleship
battleship_EXTERNAL_OBJECTS =

battleship: CMakeFiles/battleship.dir/src/CBateau.cpp.o
battleship: CMakeFiles/battleship.dir/src/testCBateau.cpp.o
battleship: CMakeFiles/battleship.dir/src/CArmada.cpp.o
battleship: CMakeFiles/battleship.dir/src/testCArmada.cpp.o
battleship: CMakeFiles/battleship.dir/src/CGui.cpp.o
battleship: CMakeFiles/battleship.dir/src/testCGui.cpp.o
battleship: CMakeFiles/battleship.dir/build.make
battleship: CMakeFiles/battleship.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kierian/CLionProjects/battleship/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable battleship"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/battleship.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/battleship.dir/build: battleship

.PHONY : CMakeFiles/battleship.dir/build

CMakeFiles/battleship.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/battleship.dir/cmake_clean.cmake
.PHONY : CMakeFiles/battleship.dir/clean

CMakeFiles/battleship.dir/depend:
	cd /home/kierian/CLionProjects/battleship/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kierian/CLionProjects/battleship /home/kierian/CLionProjects/battleship /home/kierian/CLionProjects/battleship/cmake-build-debug /home/kierian/CLionProjects/battleship/cmake-build-debug /home/kierian/CLionProjects/battleship/cmake-build-debug/CMakeFiles/battleship.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/battleship.dir/depend

