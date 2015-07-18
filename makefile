all: 
	if [ ! -d "./bin" ];\
		then mkdir bin;\
	fi
	g++ -std=c++11 src/insults.cpp -o bin/insults.o
	g++ -std=c++11 src/game.cpp -o bin/game.o

game:
	if [ ! -d "./bin" ];\
		then mkdir bin;\
	fi
	g++ -std=c++11 src/game.cpp -o bin/game.o

clean:
	rm -rf bin
