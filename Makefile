#SFML-path := ./SFML
Libs := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SrcFiles := $(wildcard SourceFiles/*.cpp)

compile: $(SrcFiles)
	g++ $(SrcFiles) -c -g -std=c++17 -I$(SFML-path)/Include 

link: compile	
	g++ $(wildcard *.o) -o main -std=c++17 -L$(SFML-path)/lib $(Libs)

run: link
	./main

clean:
	rm $(wildcard *.o)
	rm main