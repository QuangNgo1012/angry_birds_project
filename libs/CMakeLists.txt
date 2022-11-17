include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY "https://github.com/SFML/SFML"
  GIT_TAG 2f11710abc5aa478503a7ff3f9e654bd2078ebab # 2.5.1
)

add_subdirectory(sfml)

include(FetchContent)

FetchContent_Declare(
  box2d
  GIT_REPOSITORY "https://github.com/erincatto/box2d"
  GIT_TAG 9ebbbcd960ad424e03e5de6e66a40764c16f51bc # 2.4.1
)

add_subdirectory(box2d)