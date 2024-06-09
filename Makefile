# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/levizor/isteg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/levizor/isteg

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target package
package: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Run CPack packaging tool..."
	/usr/bin/cpack --config ./CPackConfig.cmake
.PHONY : package

# Special rule for the target package
package/fast: package
.PHONY : package/fast

# Special rule for the target package_source
package_source:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Run CPack packaging tool for source..."
	/usr/bin/cpack --config ./CPackSourceConfig.cmake /home/levizor/isteg/CPackSourceConfig.cmake
.PHONY : package_source

# Special rule for the target package_source
package_source/fast: package_source
.PHONY : package_source/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Available install components are: \"Unspecified\" \"devel\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/levizor/isteg/CMakeFiles /home/levizor/isteg//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/levizor/isteg/CMakeFiles 0
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
# Target rules for targets named isteg

# Build rule for target.
isteg: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 isteg
.PHONY : isteg

# fast build rule for target.
isteg/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/build
.PHONY : isteg/fast

#=============================================================================
# Target rules for targets named fmt

# Build rule for target.
fmt: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 fmt
.PHONY : fmt

# fast build rule for target.
fmt/fast:
	$(MAKE) $(MAKESILENT) -f _deps/fmt-build/CMakeFiles/fmt.dir/build.make _deps/fmt-build/CMakeFiles/fmt.dir/build
.PHONY : fmt/fast

#=============================================================================
# Target rules for targets named sfml-system

# Build rule for target.
sfml-system: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 sfml-system
.PHONY : sfml-system

# fast build rule for target.
sfml-system/fast:
	$(MAKE) $(MAKESILENT) -f _deps/sfml-build/src/SFML/System/CMakeFiles/sfml-system.dir/build.make _deps/sfml-build/src/SFML/System/CMakeFiles/sfml-system.dir/build
.PHONY : sfml-system/fast

#=============================================================================
# Target rules for targets named sfml-window

# Build rule for target.
sfml-window: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 sfml-window
.PHONY : sfml-window

# fast build rule for target.
sfml-window/fast:
	$(MAKE) $(MAKESILENT) -f _deps/sfml-build/src/SFML/Window/CMakeFiles/sfml-window.dir/build.make _deps/sfml-build/src/SFML/Window/CMakeFiles/sfml-window.dir/build
.PHONY : sfml-window/fast

#=============================================================================
# Target rules for targets named sfml-graphics

# Build rule for target.
sfml-graphics: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 sfml-graphics
.PHONY : sfml-graphics

# fast build rule for target.
sfml-graphics/fast:
	$(MAKE) $(MAKESILENT) -f _deps/sfml-build/src/SFML/Graphics/CMakeFiles/sfml-graphics.dir/build.make _deps/sfml-build/src/SFML/Graphics/CMakeFiles/sfml-graphics.dir/build
.PHONY : sfml-graphics/fast

Args.o: Args.cpp.o
.PHONY : Args.o

# target to build an object file
Args.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/Args.cpp.o
.PHONY : Args.cpp.o

Args.i: Args.cpp.i
.PHONY : Args.i

# target to preprocess a source file
Args.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/Args.cpp.i
.PHONY : Args.cpp.i

Args.s: Args.cpp.s
.PHONY : Args.s

# target to generate assembly for a file
Args.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/Args.cpp.s
.PHONY : Args.cpp.s

Exceptions.o: Exceptions.cpp.o
.PHONY : Exceptions.o

# target to build an object file
Exceptions.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/Exceptions.cpp.o
.PHONY : Exceptions.cpp.o

Exceptions.i: Exceptions.cpp.i
.PHONY : Exceptions.i

# target to preprocess a source file
Exceptions.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/Exceptions.cpp.i
.PHONY : Exceptions.cpp.i

Exceptions.s: Exceptions.cpp.s
.PHONY : Exceptions.s

# target to generate assembly for a file
Exceptions.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/Exceptions.cpp.s
.PHONY : Exceptions.cpp.s

Format.o: Format.cpp.o
.PHONY : Format.o

# target to build an object file
Format.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/Format.cpp.o
.PHONY : Format.cpp.o

Format.i: Format.cpp.i
.PHONY : Format.i

# target to preprocess a source file
Format.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/Format.cpp.i
.PHONY : Format.cpp.i

Format.s: Format.cpp.s
.PHONY : Format.s

# target to generate assembly for a file
Format.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/Format.cpp.s
.PHONY : Format.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/isteg.dir/build.make CMakeFiles/isteg.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... package"
	@echo "... package_source"
	@echo "... rebuild_cache"
	@echo "... fmt"
	@echo "... isteg"
	@echo "... sfml-graphics"
	@echo "... sfml-system"
	@echo "... sfml-window"
	@echo "... Args.o"
	@echo "... Args.i"
	@echo "... Args.s"
	@echo "... Exceptions.o"
	@echo "... Exceptions.i"
	@echo "... Exceptions.s"
	@echo "... Format.o"
	@echo "... Format.i"
	@echo "... Format.s"
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

