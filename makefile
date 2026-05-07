
UI : src/UI/menu/menu.cpp src/UI/Engine.cpp
	g++ -c src/UI/menu/menu.cpp menu.o
	g++ -c src/UI/Engine.cpp Engine.o
	g++ Engine.o menu.o -lncurses -o test.out


clean: 
	rm *.o 
	rm test.out
