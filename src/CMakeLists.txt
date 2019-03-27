cmake_minimum_required(VERSION 3.0)

project(Othello)



find_package(SFML 2 COMPONENTS graphics window audio system) 

set(INCLUDE_DIRECTORY "${CMAKE_SOURCE_DIR}/include/")
set(INCLUDE_FILES
	"${INCLUDE_DIRECTORY}/Board.hpp"
	"${INCLUDE_DIRECTORY}/CreditsState.hpp"
	"${INCLUDE_DIRECTORY}/JukeBox.hpp"
	"${INCLUDE_DIRECTORY}/MainMenuState.hpp"
	"${INCLUDE_DIRECTORY}/Piece.hpp"
	"${INCLUDE_DIRECTORY}/PlayState.hpp"
	"${INCLUDE_DIRECTORY}/Slot.hpp"
	"${INCLUDE_DIRECTORY}/State.hpp"
	"${INCLUDE_DIRECTORY}/StateManager.hpp"
	"${INCLUDE_DIRECTORY}/StatState.hpp"
)

set(SOURCE_DIRECTORY "${CMAKE_SOURCE_DIR}/src/" )
set(SOURCE_FILES 
	"${SOURCE_DIRECTORY}/CreditsState.cpp"
	"${SOURCE_DIRECTORY}/JukeBox.cpp"
	"${SOURCE_DIRECTORY}/main.cpp"
	"${SOURCE_DIRECTORY}/MainMenuState.cpp"
	"${SOURCE_DIRECTORY}/PlayState.cpp"
	"${SOURCE_DIRECTORY}/StateManager.cpp"
	"${SOURCE_DIRECTORY}/StatState.cpp"
)

set(RESOURCE_DIRECTORIES
    "Resources/"
)

add_executable(Othello "${INCLUDE_FILES}" "${SOURCE_FILES}")
target_include_directories(Othello PRIVATE "${INCLUDE_DIRECTORY}")
target_link_libraries(Othello sfml-graphics sfml-audio)

foreach(RESOURCE_DIRECTORY ${RESOURCE_DIRECTORIES})
    add_custom_command(
        TARGET Othello POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/${RESOURCE_DIRECTORY}"
            "${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE_DIRECTORY}"
    )
endforeach()