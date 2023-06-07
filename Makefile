# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/aaronfainman/Documents/6. Side Projects/DifferentialEqns"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/aaronfainman/Documents/6. Side Projects/DifferentialEqns"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.25.2/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.25.2/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/aaronfainman/Documents/6. Side Projects/DifferentialEqns/CMakeFiles" "/Users/aaronfainman/Documents/6. Side Projects/DifferentialEqns//CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/aaronfainman/Documents/6. Side Projects/DifferentialEqns/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named DifferentialEqns

# Build rule for target.
DifferentialEqns: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 DifferentialEqns
.PHONY : DifferentialEqns

# fast build rule for target.
DifferentialEqns/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/build
.PHONY : DifferentialEqns/fast

DrawablePixel.o: DrawablePixel.cpp.o
.PHONY : DrawablePixel.o

# target to build an object file
DrawablePixel.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/DrawablePixel.cpp.o
.PHONY : DrawablePixel.cpp.o

DrawablePixel.i: DrawablePixel.cpp.i
.PHONY : DrawablePixel.i

# target to preprocess a source file
DrawablePixel.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/DrawablePixel.cpp.i
.PHONY : DrawablePixel.cpp.i

DrawablePixel.s: DrawablePixel.cpp.s
.PHONY : DrawablePixel.s

# target to generate assembly for a file
DrawablePixel.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/DrawablePixel.cpp.s
.PHONY : DrawablePixel.cpp.s

EventHandler.o: EventHandler.cpp.o
.PHONY : EventHandler.o

# target to build an object file
EventHandler.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/EventHandler.cpp.o
.PHONY : EventHandler.cpp.o

EventHandler.i: EventHandler.cpp.i
.PHONY : EventHandler.i

# target to preprocess a source file
EventHandler.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/EventHandler.cpp.i
.PHONY : EventHandler.cpp.i

EventHandler.s: EventHandler.cpp.s
.PHONY : EventHandler.s

# target to generate assembly for a file
EventHandler.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/EventHandler.cpp.s
.PHONY : EventHandler.cpp.s

ExternalState.o: ExternalState.cpp.o
.PHONY : ExternalState.o

# target to build an object file
ExternalState.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/ExternalState.cpp.o
.PHONY : ExternalState.cpp.o

ExternalState.i: ExternalState.cpp.i
.PHONY : ExternalState.i

# target to preprocess a source file
ExternalState.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/ExternalState.cpp.i
.PHONY : ExternalState.cpp.i

ExternalState.s: ExternalState.cpp.s
.PHONY : ExternalState.s

# target to generate assembly for a file
ExternalState.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/ExternalState.cpp.s
.PHONY : ExternalState.cpp.s

Particle.o: Particle.cpp.o
.PHONY : Particle.o

# target to build an object file
Particle.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/Particle.cpp.o
.PHONY : Particle.cpp.o

Particle.i: Particle.cpp.i
.PHONY : Particle.i

# target to preprocess a source file
Particle.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/Particle.cpp.i
.PHONY : Particle.cpp.i

Particle.s: Particle.cpp.s
.PHONY : Particle.s

# target to generate assembly for a file
Particle.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/Particle.cpp.s
.PHONY : Particle.cpp.s

Simulation.o: Simulation.cpp.o
.PHONY : Simulation.o

# target to build an object file
Simulation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/Simulation.cpp.o
.PHONY : Simulation.cpp.o

Simulation.i: Simulation.cpp.i
.PHONY : Simulation.i

# target to preprocess a source file
Simulation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/Simulation.cpp.i
.PHONY : Simulation.cpp.i

Simulation.s: Simulation.cpp.s
.PHONY : Simulation.s

# target to generate assembly for a file
Simulation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/Simulation.cpp.s
.PHONY : Simulation.cpp.s

Window.o: Window.cpp.o
.PHONY : Window.o

# target to build an object file
Window.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/Window.cpp.o
.PHONY : Window.cpp.o

Window.i: Window.cpp.i
.PHONY : Window.i

# target to preprocess a source file
Window.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/Window.cpp.i
.PHONY : Window.cpp.i

Window.s: Window.cpp.s
.PHONY : Window.s

# target to generate assembly for a file
Window.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/Window.cpp.s
.PHONY : Window.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/DifferentialEqns.dir/build.make CMakeFiles/DifferentialEqns.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... DifferentialEqns"
	@echo "... DrawablePixel.o"
	@echo "... DrawablePixel.i"
	@echo "... DrawablePixel.s"
	@echo "... EventHandler.o"
	@echo "... EventHandler.i"
	@echo "... EventHandler.s"
	@echo "... ExternalState.o"
	@echo "... ExternalState.i"
	@echo "... ExternalState.s"
	@echo "... Particle.o"
	@echo "... Particle.i"
	@echo "... Particle.s"
	@echo "... Simulation.o"
	@echo "... Simulation.i"
	@echo "... Simulation.s"
	@echo "... Window.o"
	@echo "... Window.i"
	@echo "... Window.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
