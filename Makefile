LIBFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

snake : main.o Game.o Snake.o Food.o
	g++ -std=c++11 main.o Game.o Snake.o Food.o $(LIBFLAGS) -o snake

main.o : src/main.cpp
	g++ -Wall -c -std=c++11 src/main.cpp

Game.o : src/Game.cpp src/Game.h
	g++ -Wall -c -std=c++11 src/Game.cpp

Snake.o : src/Snake.cpp src/Snake.h
	g++ -Wall -c -std=c++11 src/Snake.cpp

Food.o : src/Food.cpp src/Food.h
	g++ -Wall -c -std=c++11 src/Food.cpp

clean :
	rm *.o snake

docs : 
	doxygen doxygen_config
	xdg-open html/index.html
