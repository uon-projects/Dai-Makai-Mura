cmake_minimum_required(VERSION 3.15)
set(project_title Dai-Makai-Mura)
project(${project_title})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static -static-libgcc -static-libstdc++")

set(CMAKE_MODULE_PATH /SFML/cmake/Modules)

set(SFML_DIR "/SFML")
find_package(SFML 2.4 COMPONENTS system window graphics)

add_executable(${project_title} src/main/main.cpp src/main/cpp/App.cpp src/main/header/App.h src/main/cpp/Utils.cpp src/main/header/Utils.h src/main/cpp/screen/SplashScreen.cpp src/main/header/screen/SplashScreen.h src/main/cpp/library/Loader.cpp src/main/header/library/Loader.h)
target_link_libraries(${project_title} sfml-system sfml-window sfml-graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()