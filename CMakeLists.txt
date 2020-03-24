cmake_minimum_required(VERSION 3.15)
set(project_title Dai-Makai-Mura)
project(${project_title})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static -static-libgcc -static-libstdc++")

add_executable(${project_title} app/src/main/main.cpp app/src/main/cpp/App.cpp app/src/main/header/App.h app/src/main/cpp/Utils.cpp app/src/main/header/Utils.h app/src/main/cpp/screen/SplashScreen.cpp app/src/main/header/screen/SplashScreen.h library/src/main/cpp/Loader.cpp library/src/main/header/Loader.h app/src/main/cpp/screen/GameMenuScreen.cpp app/src/main/header/screen/GameMenuScreen.h library/src/main/cpp/RoundedRectangleShape.cpp library/src/main/header/RoundedRectangleShape.h library/src/main/cpp/MaterialButton.cpp library/src/main/header/MaterialButton.h library/src/main/cpp/LoadFont.cpp library/src/main/header/LoadFont.h)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(SFML 2.4 COMPONENTS system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif ()
