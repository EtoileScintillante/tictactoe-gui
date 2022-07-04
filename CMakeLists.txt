cmake_minimum_required(VERSION 3.15)
project(TicTacToe LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(COPY ${CMAKE_CURRENT_LIST_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
include_directories(src/include)
add_executable(TicTacToe main.cpp src/helpers.cpp src/ttt.cpp src/point.cpp)
target_link_libraries(TicTacToe PRIVATE sfml-graphics)
target_compile_features(TicTacToe PRIVATE cxx_std_17)

install(TARGETS TicTacToe)