cmake_minimum_required(VERSION 3.10.2)

project(Snake)

option(BUILD_DOC "Build Documentation" ON)

find_package(Doxygen
             REQUIRED dot
             OPTIONAL_COMPONENTS mscgen dia)
if (DOXYGEN_FOUND)
	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
	set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

	configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
	message("Doxygen build started")

	add_custom_target( doc_doxygen ALL
		COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating API documentation with Doxygen"
		VERBATIM )
else (DOXYGEN_FOUND)
  message("Install Doxygen to generate documentation")
endif (DOXYGEN_FOUND)

if (MSVC)
	add_compile_options(/W4)
else ()
	add_compile_options(-Wall)
endif()

include_directories(include)

add_executable(snake src/main.cpp src/Food.cpp src/Game.cpp src/Snake.cpp)

target_link_libraries(snake -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio)

set_property(TARGET snake PROPERTY CXX_STANDARD 11)
