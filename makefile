main : main.o Fight.o Ability.o Character.o Map.o Config.o Inventory.o Game.o
	g++ -o main main.o Fight.o Ability.o Character.o Map.o Config.o Inventory.o Game.o

/main.o : main.cpp
	g++ -o main.o -c main.cpp

/Fight.o : Fight.cpp
	g++ -o Fight.o -c Fight.cpp

/Ability.o : Ability.cpp
	g++ -o Ability.o -c Ability.cpp

/Character.o : Character.cpp
	g++ -o Character.o -c Character.cpp

/Map.o : Map.cpp
	g++ -std=c++11 Map.o -c Map.cpp

/Config.o : Config.cpp
	g++ -o Config.o -c Config.cpp

/Inventory.o : Inventory.cpp
	g++ -o Inventory.o -c Inventory.cpp

/Game.o : Game.cpp
	g++ -o Game.o -c Game.cpp

clean:
	rm -rf *.o

mrproper: clean
	rm -rf main
