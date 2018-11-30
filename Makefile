SFML-path := ./SFML
Libs := -lsfml-graphics -lsfml-window -lsfml-system -static-libgcc -static-libstdc++
SrcFiles := $(wildcard *.cpp)

compile: $(SrcFiles)
	g++ $(SrcFiles) -c -I$(SFML-path)\Include

link: compile	
	g++ $(wildcard *.o) -o sfml-app -L$(SFML-path)\lib $(Libs)

run: link
	sfml-app.exe