# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.20.0)


# set the enviroment variable VCPKG_ROOT to the absolute path of your vcpkg isntallation. If vcpkg is installed at C:/vcpkg, then the command
# should like like this:
#set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

# Define your project name and the language it uses
project(SoundProject C)

# grab all the c files from src
file(GLOB SOURCES "src/*.c")
add_executable(main ${SOURCES})

find_package(portaudio CONFIG REQUIRED)
target_link_libraries(main PRIVATE portaudio)


find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)

# local includes
include_directories(include)


