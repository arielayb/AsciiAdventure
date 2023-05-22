project("AsciiAdventure")

include_directories("include" "tmx")

link_directories("AsciiAdventure/images/")

file(GLOB SOURCES "include/*.h" "src/*.cpp")
include(FindZLIB)
include(FindLibXml2)
find_package(LibXml2 REQUIRED)
find_package(ZLIB REQUIRED)
find_package(SDL2 REQUIRED)

add_executable("AsciiAdventure" ${SOURCES})
target_link_libraries("AsciiAdventure" ${SDL2_LIBRARIES} -lpthread -lSDL2-2.0 -lSDL2_image -lSDL2_mixer -lSDL2_ttf LibXml2::LibXml2 -ltmx)
include_directories(${SDL2_INCLUDE_DIRS})