
# VOLUME WARNING

If you build and run this project, it will make sound on your speakers/headphones. The volume settings work fine for my setup, but they may be ridiculously loud on yours,
so be careful. 

# Henry's Synthesizer

A simple synthesizer written in C using Portaudio. Right now it's configured to automatically play a 1:2:3:...:21 polyrythm, but it can also be configured to take input from the keyboard.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine. 

### Prerequisites

- Git 
- CMake
- vcpkg

### Installing

Follow these steps to get your development env running:

#### 0. Clone the Repository

First, clone the repository to your local machine.

#### 1. Install CMake

Ensure you have CMake installed. If not, download and install it from [CMake's official website](https://cmake.org/download/).

#### 2. Install vcpkg

Install vcpkg, a C/C++ package manager developed by Microsoft. Follow [instructions](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-cmd) on bootstraping vcpkg.

#### 3. Add vcpkg Root Path to System Variable

Set the `VCPKG_ROOT` environment variable to the path of your vcpkg installation. This is used in CMakeLists.txt to connect vcpkg to cmake.


#### 4. Navigate to Project Repository and Proceed with CMake Build Process

Create a build directory and navigate into it:

```bash
mkdir build && cd build
```


Configure the project with CMake.

```bash
cmake .. 
```

Finally, build the project:

```bash
cmake --build .
```

The executable should be located in the `Debug` folder in `build`.




