cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES
    src/Cell.cpp
    src/AliveCell.cpp
    src/DeadCell.cpp
    src/ConwayRule.cpp
    src/Grid.cpp
    src/Game.cpp
    src/ConsoleView.cpp
    src/View.cpp
)

add_executable(game_of_life
    ${SOURCES}
    src/main.cpp
)

add_executable(tests
    ${SOURCES}
    tests/tests.cpp
)

if(MSVC)
    target_compile_options(game_of_life PRIVATE /W4)
    target_compile_options(tests PRIVATE /W4)
else()
    target_compile_options(game_of_life PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(tests PRIVATE -Wall -Wextra -pedantic)
endif()

if(NOT MSVC)
    target_link_libraries(game_of_life stdc++fs)
    target_link_libraries(tests stdc++fs)
endif()