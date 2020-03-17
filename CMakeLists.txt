cmake_minimum_required(VERSION 3.15)
project(sfml-test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static -static-libgcc -static-libstdc++")

set(CMAKE_MODULE_PATH /SFML/cmake/Modules)

set(SFML_DIR "/SFML")
find_package(SFML 2.4 COMPONENTS system window graphics)

add_executable(sfml-test src/game/main.cpp)
target_link_libraries(sfml-test sfml-system sfml-window sfml-graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()