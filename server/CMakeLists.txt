cmake_minimum_required(VERSION 3.1)
project(odavissrv VERSION 0.0.1 DESCRIPTION "OpenDavis server" LANGUAGES CXX  )

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_executable(odavisrv 

src/main.cpp
src/httpsrv.cpp
)

target_compile_features(odavisrv PUBLIC cxx_std_11)
set_target_properties(odavisrv PROPERTIES CXX_EXTENSIONS OFF)



### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

FIND_PACKAGE(Libevent2 REQUIRED)



target_link_libraries(odavisrv event)

