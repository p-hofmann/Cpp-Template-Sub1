# Cpp-Template-Sub1
[![TraviCI](https://api.travis-ci.com/p-hofmann/Cpp-Template-Sub1.svg?branch=master)](https://travis-ci.com/p-hofmann/Cpp-Template-Sub1)
[![CircleCI](https://circleci.com/gh/p-hofmann/Cpp-Template-Sub1/tree/master.svg?style=svg)](https://circleci.com/gh/p-hofmann/Cpp-Template-Sub1/tree/master)  
A C++ submodule of 'Cpp-Template'  
This is part of the [C++ template](https://github.com/p-hofmann/Cpp-Template) that deals with the issue of organizing a big project.
In addition to that it also includes ways to deal with different operation systems or even architecture.  
It includes unittests using [Catch2](https://github.com/catchorg/Catch2).
The [Catch2](https://github.com/catchorg/Catch2) source is not included in this repository as expected, but is cloned from the remote repository when the project is build.  
Continuous integration using [Travis CI](https://travis-ci.com/) is supported. The Code is there tested on Linux, Darwin and Windows OS.
[Circle CI](https://circleci.com/) is supported, but the Code is tested on Linux only. for now.

## Project Layout

├── CMakeLists.txt  
├── .travis.yml  
├── .circleci  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── config.yml  
├── include  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── project.h  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── Cpp-Template-Sub1-Sub  
├── libs  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── library.a  
├── src  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── project.cpp  
├── external  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── CMakeLists.txt  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── catch2  
│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── catch.hpp  
└── tests  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── CMakeLists.txt  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── test_project.cpp  

* .travis.yml
  - Configuration file for [Travis CI](https://travis-ci.com/) support.
* .circleci/config.yml
  - Configuration file for [Circle CI](https://circleci.com/) support.
* include
  - Header of current module
* include/Cpp-Template-Sub1-Sub
  - Submodule of this module
  - It is not a third party project and considered part of this build.
    Because of that it is included in the 'include' folder, not the 'external' folder.
* libs
  - Build library
* src
  - Source files of current module
* external
  - External projects that are not developed as part of this project.
  - Projects here are loaded by the CMakeLists.txt file in this folder.
* tests
  - Unittest files of current module
* catch2
  - [Catch2](https://github.com/catchorg/Catch2) will be downloaded as part of cmake when run on unittests
