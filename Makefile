Libs := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SrcFiles := $(wildcard SourceFiles/*.cpp)

compile: $(SrcFiles)
	g++ $(SrcFiles) -c -std=c++17 

link: compile	
	g++ $(wildcard *.o) -o main -std=c++17 $(Libs)

run: link
	./main

clean:
	rm $(wildcard *.o)
	rm main