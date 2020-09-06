cmake_minimum_required(VERSION 3.5)

project(Hiyori LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/plugins/characters/${PROJECT_NAME})

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_library(Hiyori SHARED
  Hiyori_global.h
  Hiyori.cpp
  Hiyori.h
  model.qrc
  hiyori.json
)

target_link_libraries(Hiyori PRIVATE Qt5::Core)
target_link_libraries(Hiyori PRIVATE zPI)


target_compile_definitions(Hiyori PRIVATE HIYORI_LIBRARY)
