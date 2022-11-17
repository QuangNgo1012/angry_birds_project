message(STATUS "Fetching SFML...")

# No need to build  network modules
set(SFML_BUILD_NETWORK FALSE)

FetchContent_MakeAvailable(sfml)