project("AsciiAdventure")

include_directories("include")

file(GLOB SOURCES "include/*.h" "src/*.cpp")

add_executable("AsciiAdventure" ${SOURCES})
