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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andreyzhelannikov/Ihopethatislast

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andreyzhelannikov/Ihopethatislast/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/testus.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/testus.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/testus.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/testus.dir/flags.make

tests/CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.o: tests/CMakeFiles/testus.dir/flags.make
tests/CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.o: tests/testus_autogen/mocs_compilation.cpp
tests/CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.o: tests/CMakeFiles/testus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andreyzhelannikov/Ihopethatislast/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.o"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.o -MF CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.o -c /Users/andreyzhelannikov/Ihopethatislast/build/tests/testus_autogen/mocs_compilation.cpp

tests/CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.i"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andreyzhelannikov/Ihopethatislast/build/tests/testus_autogen/mocs_compilation.cpp > CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.i

tests/CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.s"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andreyzhelannikov/Ihopethatislast/build/tests/testus_autogen/mocs_compilation.cpp -o CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.s

tests/CMakeFiles/testus.dir/calc_test.c.o: tests/CMakeFiles/testus.dir/flags.make
tests/CMakeFiles/testus.dir/calc_test.c.o: ../tests/calc_test.c
tests/CMakeFiles/testus.dir/calc_test.c.o: tests/CMakeFiles/testus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andreyzhelannikov/Ihopethatislast/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/testus.dir/calc_test.c.o"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/testus.dir/calc_test.c.o -MF CMakeFiles/testus.dir/calc_test.c.o.d -o CMakeFiles/testus.dir/calc_test.c.o -c /Users/andreyzhelannikov/Ihopethatislast/tests/calc_test.c

tests/CMakeFiles/testus.dir/calc_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testus.dir/calc_test.c.i"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andreyzhelannikov/Ihopethatislast/tests/calc_test.c > CMakeFiles/testus.dir/calc_test.c.i

tests/CMakeFiles/testus.dir/calc_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testus.dir/calc_test.c.s"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andreyzhelannikov/Ihopethatislast/tests/calc_test.c -o CMakeFiles/testus.dir/calc_test.c.s

tests/CMakeFiles/testus.dir/polish_test.c.o: tests/CMakeFiles/testus.dir/flags.make
tests/CMakeFiles/testus.dir/polish_test.c.o: ../tests/polish_test.c
tests/CMakeFiles/testus.dir/polish_test.c.o: tests/CMakeFiles/testus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andreyzhelannikov/Ihopethatislast/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/testus.dir/polish_test.c.o"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/testus.dir/polish_test.c.o -MF CMakeFiles/testus.dir/polish_test.c.o.d -o CMakeFiles/testus.dir/polish_test.c.o -c /Users/andreyzhelannikov/Ihopethatislast/tests/polish_test.c

tests/CMakeFiles/testus.dir/polish_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testus.dir/polish_test.c.i"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andreyzhelannikov/Ihopethatislast/tests/polish_test.c > CMakeFiles/testus.dir/polish_test.c.i

tests/CMakeFiles/testus.dir/polish_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testus.dir/polish_test.c.s"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andreyzhelannikov/Ihopethatislast/tests/polish_test.c -o CMakeFiles/testus.dir/polish_test.c.s

tests/CMakeFiles/testus.dir/__/calculator/calc.c.o: tests/CMakeFiles/testus.dir/flags.make
tests/CMakeFiles/testus.dir/__/calculator/calc.c.o: ../calculator/calc.c
tests/CMakeFiles/testus.dir/__/calculator/calc.c.o: tests/CMakeFiles/testus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andreyzhelannikov/Ihopethatislast/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/CMakeFiles/testus.dir/__/calculator/calc.c.o"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/testus.dir/__/calculator/calc.c.o -MF CMakeFiles/testus.dir/__/calculator/calc.c.o.d -o CMakeFiles/testus.dir/__/calculator/calc.c.o -c /Users/andreyzhelannikov/Ihopethatislast/calculator/calc.c

tests/CMakeFiles/testus.dir/__/calculator/calc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testus.dir/__/calculator/calc.c.i"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andreyzhelannikov/Ihopethatislast/calculator/calc.c > CMakeFiles/testus.dir/__/calculator/calc.c.i

tests/CMakeFiles/testus.dir/__/calculator/calc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testus.dir/__/calculator/calc.c.s"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andreyzhelannikov/Ihopethatislast/calculator/calc.c -o CMakeFiles/testus.dir/__/calculator/calc.c.s

tests/CMakeFiles/testus.dir/__/calculator/converting.c.o: tests/CMakeFiles/testus.dir/flags.make
tests/CMakeFiles/testus.dir/__/calculator/converting.c.o: ../calculator/converting.c
tests/CMakeFiles/testus.dir/__/calculator/converting.c.o: tests/CMakeFiles/testus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andreyzhelannikov/Ihopethatislast/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object tests/CMakeFiles/testus.dir/__/calculator/converting.c.o"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/testus.dir/__/calculator/converting.c.o -MF CMakeFiles/testus.dir/__/calculator/converting.c.o.d -o CMakeFiles/testus.dir/__/calculator/converting.c.o -c /Users/andreyzhelannikov/Ihopethatislast/calculator/converting.c

tests/CMakeFiles/testus.dir/__/calculator/converting.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testus.dir/__/calculator/converting.c.i"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andreyzhelannikov/Ihopethatislast/calculator/converting.c > CMakeFiles/testus.dir/__/calculator/converting.c.i

tests/CMakeFiles/testus.dir/__/calculator/converting.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testus.dir/__/calculator/converting.c.s"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andreyzhelannikov/Ihopethatislast/calculator/converting.c -o CMakeFiles/testus.dir/__/calculator/converting.c.s

tests/CMakeFiles/testus.dir/__/calculator/smartcalc.c.o: tests/CMakeFiles/testus.dir/flags.make
tests/CMakeFiles/testus.dir/__/calculator/smartcalc.c.o: ../calculator/smartcalc.c
tests/CMakeFiles/testus.dir/__/calculator/smartcalc.c.o: tests/CMakeFiles/testus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andreyzhelannikov/Ihopethatislast/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object tests/CMakeFiles/testus.dir/__/calculator/smartcalc.c.o"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/testus.dir/__/calculator/smartcalc.c.o -MF CMakeFiles/testus.dir/__/calculator/smartcalc.c.o.d -o CMakeFiles/testus.dir/__/calculator/smartcalc.c.o -c /Users/andreyzhelannikov/Ihopethatislast/calculator/smartcalc.c

tests/CMakeFiles/testus.dir/__/calculator/smartcalc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testus.dir/__/calculator/smartcalc.c.i"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andreyzhelannikov/Ihopethatislast/calculator/smartcalc.c > CMakeFiles/testus.dir/__/calculator/smartcalc.c.i

tests/CMakeFiles/testus.dir/__/calculator/smartcalc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testus.dir/__/calculator/smartcalc.c.s"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andreyzhelannikov/Ihopethatislast/calculator/smartcalc.c -o CMakeFiles/testus.dir/__/calculator/smartcalc.c.s

tests/CMakeFiles/testus.dir/__/calculator/validate.c.o: tests/CMakeFiles/testus.dir/flags.make
tests/CMakeFiles/testus.dir/__/calculator/validate.c.o: ../calculator/validate.c
tests/CMakeFiles/testus.dir/__/calculator/validate.c.o: tests/CMakeFiles/testus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andreyzhelannikov/Ihopethatislast/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object tests/CMakeFiles/testus.dir/__/calculator/validate.c.o"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/testus.dir/__/calculator/validate.c.o -MF CMakeFiles/testus.dir/__/calculator/validate.c.o.d -o CMakeFiles/testus.dir/__/calculator/validate.c.o -c /Users/andreyzhelannikov/Ihopethatislast/calculator/validate.c

tests/CMakeFiles/testus.dir/__/calculator/validate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testus.dir/__/calculator/validate.c.i"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/andreyzhelannikov/Ihopethatislast/calculator/validate.c > CMakeFiles/testus.dir/__/calculator/validate.c.i

tests/CMakeFiles/testus.dir/__/calculator/validate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testus.dir/__/calculator/validate.c.s"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/andreyzhelannikov/Ihopethatislast/calculator/validate.c -o CMakeFiles/testus.dir/__/calculator/validate.c.s

# Object files for target testus
testus_OBJECTS = \
"CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/testus.dir/calc_test.c.o" \
"CMakeFiles/testus.dir/polish_test.c.o" \
"CMakeFiles/testus.dir/__/calculator/calc.c.o" \
"CMakeFiles/testus.dir/__/calculator/converting.c.o" \
"CMakeFiles/testus.dir/__/calculator/smartcalc.c.o" \
"CMakeFiles/testus.dir/__/calculator/validate.c.o"

# External object files for target testus
testus_EXTERNAL_OBJECTS =

tests/testus: tests/CMakeFiles/testus.dir/testus_autogen/mocs_compilation.cpp.o
tests/testus: tests/CMakeFiles/testus.dir/calc_test.c.o
tests/testus: tests/CMakeFiles/testus.dir/polish_test.c.o
tests/testus: tests/CMakeFiles/testus.dir/__/calculator/calc.c.o
tests/testus: tests/CMakeFiles/testus.dir/__/calculator/converting.c.o
tests/testus: tests/CMakeFiles/testus.dir/__/calculator/smartcalc.c.o
tests/testus: tests/CMakeFiles/testus.dir/__/calculator/validate.c.o
tests/testus: tests/CMakeFiles/testus.dir/build.make
tests/testus: tests/CMakeFiles/testus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andreyzhelannikov/Ihopethatislast/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable testus"
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/testus.dir/build: tests/testus
.PHONY : tests/CMakeFiles/testus.dir/build

tests/CMakeFiles/testus.dir/clean:
	cd /Users/andreyzhelannikov/Ihopethatislast/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/testus.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/testus.dir/clean

tests/CMakeFiles/testus.dir/depend:
	cd /Users/andreyzhelannikov/Ihopethatislast/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andreyzhelannikov/Ihopethatislast /Users/andreyzhelannikov/Ihopethatislast/tests /Users/andreyzhelannikov/Ihopethatislast/build /Users/andreyzhelannikov/Ihopethatislast/build/tests /Users/andreyzhelannikov/Ihopethatislast/build/tests/CMakeFiles/testus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/testus.dir/depend

