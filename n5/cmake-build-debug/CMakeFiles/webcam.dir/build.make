# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\wrk\evm\webcam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\wrk\evm\webcam\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/webcam.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/webcam.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/webcam.dir/flags.make

CMakeFiles/webcam.dir/main.cpp.obj: CMakeFiles/webcam.dir/flags.make
CMakeFiles/webcam.dir/main.cpp.obj: CMakeFiles/webcam.dir/includes_CXX.rsp
CMakeFiles/webcam.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\wrk\evm\webcam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/webcam.dir/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\webcam.dir\main.cpp.obj -c D:\wrk\evm\webcam\main.cpp

CMakeFiles/webcam.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webcam.dir/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\wrk\evm\webcam\main.cpp > CMakeFiles\webcam.dir\main.cpp.i

CMakeFiles/webcam.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webcam.dir/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\wrk\evm\webcam\main.cpp -o CMakeFiles\webcam.dir\main.cpp.s

# Object files for target webcam
webcam_OBJECTS = \
"CMakeFiles/webcam.dir/main.cpp.obj"

# External object files for target webcam
webcam_EXTERNAL_OBJECTS =

webcam.exe: CMakeFiles/webcam.dir/main.cpp.obj
webcam.exe: CMakeFiles/webcam.dir/build.make
webcam.exe: D:/wrk/evm/opencv-master/mingw-build/install/x64/mingw/lib/libopencv_highgui451.dll.a
webcam.exe: D:/wrk/evm/opencv-master/mingw-build/install/x64/mingw/lib/libopencv_videoio451.dll.a
webcam.exe: D:/wrk/evm/opencv-master/mingw-build/install/x64/mingw/lib/libopencv_imgcodecs451.dll.a
webcam.exe: D:/wrk/evm/opencv-master/mingw-build/install/x64/mingw/lib/libopencv_imgproc451.dll.a
webcam.exe: D:/wrk/evm/opencv-master/mingw-build/install/x64/mingw/lib/libopencv_core451.dll.a
webcam.exe: CMakeFiles/webcam.dir/linklibs.rsp
webcam.exe: CMakeFiles/webcam.dir/objects1.rsp
webcam.exe: CMakeFiles/webcam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\wrk\evm\webcam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable webcam.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\webcam.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/webcam.dir/build: webcam.exe

.PHONY : CMakeFiles/webcam.dir/build

CMakeFiles/webcam.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\webcam.dir\cmake_clean.cmake
.PHONY : CMakeFiles/webcam.dir/clean

CMakeFiles/webcam.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\wrk\evm\webcam D:\wrk\evm\webcam D:\wrk\evm\webcam\cmake-build-debug D:\wrk\evm\webcam\cmake-build-debug D:\wrk\evm\webcam\cmake-build-debug\CMakeFiles\webcam.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/webcam.dir/depend

