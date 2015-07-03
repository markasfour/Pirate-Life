all: 
	if [ ! -d "./bin" ];\
		then mkdir bin;\
	fi
	g++ -std=c++11 src/insults.cpp -o bin/insults.o

clean:
	rm -rf bin
