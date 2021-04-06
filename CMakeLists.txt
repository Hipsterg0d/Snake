cmake_minimum_required(VERSION 3.10.2)
project(Snake)

if (MSVC)
	add_compile_options(/W4)
else ()
	add_compile_options(-Wall)
endif()

include_directories(include)
add_executable(snake src/main.cpp src/Food.cpp src/Game.cpp src/Snake.cpp)
target_link_libraries(snake -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio)
set_property(TARGET snake PROPERTY CXX_STANDARD 11)
