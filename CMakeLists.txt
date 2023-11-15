cmake_minimum_required(VERSION 3.0.0)
project(bugs-life VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(bugs-life main.cpp Board.cpp Board.h Bug.cpp Bug.h Cell.cpp Cell.h 
    Constants.h Crawler.cpp Crawler.h Direction.h FileReader.cpp FileReader.h 
    Hopper.cpp Hopper.h LineParser.cpp LineParser.h DirectionToString.cpp 
    DirectionToString.h PrintBug.cpp PrintBug.h Menu.cpp Menu.h PathToString.cpp PathToString.h 
    PrintCell.cpp PrintCell.h Jitter.cpp Jitter.h SuperBug.cpp SuperBug.h FileWriter.cpp FileWriter.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.5.1/include)
target_link_libraries(bugs-life sfml-system sfml-window sfml-graphics sfml-audio)
