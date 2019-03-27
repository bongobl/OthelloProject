cmake_minimum_required(VERSION 3.0)

project(Othello)


set(OTHELLO_INCLUDE_DIRECTORY "${CMAKE_SOURCE_DIR}/include/")
set(SFML_INCLUDE_DIRECTORY "${CMAKE_SOURCE_DIR}/external/SFML/include")

set(ALL_INCLUDE_DIRECTORIES 
	"${OTHELLO_INCLUDE_DIRECTORY}"
	"${SFML_INCLUDE_DIRECTORY}"
)

set(SOURCE_DIRECTORY "${CMAKE_SOURCE_DIR}/src/")
set(SOURCE_FILES 
	"${SOURCE_DIRECTORY}/CreditsState.cpp"
	"${SOURCE_DIRECTORY}/JukeBox.cpp"
	"${SOURCE_DIRECTORY}/main.cpp"
	"${SOURCE_DIRECTORY}/MainMenuState.cpp"
	"${SOURCE_DIRECTORY}/PlayState.cpp"
	"${SOURCE_DIRECTORY}/StateManager.cpp"
	"${SOURCE_DIRECTORY}/StatState.cpp"
)



add_executable(Othello "${SOURCE_FILES}")
target_include_directories(Othello PRIVATE "${ALL_INCLUDE_DIRECTORIES}")

link_directories("${CMAKE_BINARY_DIR}/external/SFML/lib")


target_link_libraries(Othello sfml-graphics sfml-audio)


set(RESOURCE_DIRECTORIES
    "Resources/"
)

#copy resources
foreach(RESOURCE_DIRECTORY ${RESOURCE_DIRECTORIES})
    add_custom_command(
        TARGET Othello POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/${RESOURCE_DIRECTORY}"
            "${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE_DIRECTORY}"
    )
endforeach()