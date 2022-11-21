project("AsciiAdventure")

include_directories("include")

file(GLOB SOURCES "include/*.h" "src/*.cpp")
find_package(SDL2 REQUIRED)

add_executable("AsciiAdventure" ${SOURCES})
target_link_libraries("AsciiAdventure" ${SDL2_LIBRARIES})
include_directories(${SDL2_INCLUDE_DIRS})