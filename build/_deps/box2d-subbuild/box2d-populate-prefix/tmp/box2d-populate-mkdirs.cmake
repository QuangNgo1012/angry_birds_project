# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/box2d-src"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/box2d-build"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/box2d-subbuild/box2d-populate-prefix"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/box2d-subbuild/box2d-populate-prefix/tmp"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/box2d-subbuild/box2d-populate-prefix/src"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
