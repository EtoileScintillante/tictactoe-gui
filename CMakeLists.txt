cmake_minimum_required(VERSION 3.15)
project(TicTacToe LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.1)
FetchContent_MakeAvailable(SFML)

include_directories(src/include)
add_executable(TicTacToe main.cpp src/helpers.cpp src/ttt.cpp src/point.cpp)
target_link_libraries(TicTacToe PRIVATE sfml-graphics)
target_compile_features(TicTacToe PRIVATE cxx_std_17)

install(TARGETS TicTacToe)