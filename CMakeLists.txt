cmake_minimum_required(VERSION 3.0)

set(BUILD_SHARED_LIBS		OFF CACHE BOOL "")
set(SFML_BUILD_AUDIO 		ON CACHE BOOL "")
set(SFML_BUILD_DOC  		OFF CACHE BOOL "")
set(SFML_BUILD_EXAMPLES 	OFF CACHE BOOL "")
set(SFML_BUILD_GRAPHICS 	ON CACHE BOOL "")
set(SFML_BUILD_NETWORK 		OFF CACHE BOOL "")
set(SFML_BUILD_TEST_SUITE 	OFF CACHE BOOL "")
set(SFML_BUILD_TEST_WINDOW 	ON CACHE BOOL "")
add_subdirectory(external/SFML)

add_subdirectory(src Othello)
