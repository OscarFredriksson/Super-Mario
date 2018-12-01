SFML-path := ./SFML
Libs := -lsfml-graphics -lsfml-window -lsfml-system -static-libgcc -static-libstdc++
SrcFiles := $(wildcard *.cpp)

compile: $(SrcFiles)
	g++ $(SrcFiles) -c -std=c++17 -I$(SFML-path)/Include 

link: compile	
	g++ $(wildcard *.o) -o sfml-app -std=c++17 $(Libs) -L$(SFML-path)/lib 

run: link
	./sfml-app