# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/sfml-src"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/sfml-build"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/sfml-subbuild/sfml-populate-prefix"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/Programming 2/Angry Birds/angry-birds-2/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
