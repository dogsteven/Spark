cmake_minimum_required(VERSION 4.3)
project(Spark)

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-Xclang -fretain-comments-from-system-headers)
endif ()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-fexceptions)
enable_testing()

add_subdirectory(Sandbox)
add_subdirectory(Engine)
add_subdirectory(Tests)
