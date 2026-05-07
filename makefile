UI : menu.o Engine.o NcManager.o taskpage.o Task.o 
	@echo "Linking the object files..."
	@g++ menu.o Engine.o NcManager.o taskpage.o Task.o -o ui.out -lncurses 
	@echo "RESULT: ui.out"

menu.o : src/UI/menu/menu.cpp
	@echo "Compiling the menu..."
	@g++ -c src/UI/menu/menu.cpp -o menu.o 

Engine.o : src/UI/Engine.cpp 
	@echo "Compiling the Engine..." 
	@g++ -c src/UI/Engine.cpp -o Engine.o 

NcManager.o : src/UI/NcManager/NcManager.cpp
	@g++ -c src/UI/NcManager/NcManager.cpp -o NcManager.o

taskpage.o : src/UI/tasks/taskpage.cpp 
	@g++ -c src/UI/tasks/taskpage.cpp -o taskpage.o 

Task.o : src/models/Task.cpp
	@g++ -c src/models/Task.cpp -o Task.o

clean:
	@echo "Cleaning..."
	@rm *.o 
	@rm ui.out
