cmake_minimum_required(VERSION 3.15)
set(project_title Dai-Makai-Mura)
project(${project_title})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static -static-libgcc -static-libstdc++")

add_executable(${project_title} src/main/main.cpp src/main/cpp/App.cpp src/main/header/App.h src/main/cpp/Utils.cpp src/main/header/Utils.h src/main/cpp/screen/SplashScreen.cpp src/main/header/screen/SplashScreen.h src/main/cpp/library/Loader.cpp src/main/header/library/Loader.h src/main/cpp/screen/GameMenuScreen.cpp src/main/header/screen/GameMenuScreen.h)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(SFML 2.4 COMPONENTS system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif ()
