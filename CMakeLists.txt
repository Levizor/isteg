cmake_minimum_required(VERSION 3.28)
project(isteg)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG 2.6.1
)
set(SFML_BUILD_AUDIO OFF)
set(SFML_BUILD_NETWORK OFF)

FetchContent_MakeAvailable(fmt SFML)

add_executable(isteg main.cpp Args.h Args.cpp Format.h Format.cpp Exceptions.h Exceptions.cpp)
target_link_libraries(isteg fmt sfml-graphics)
