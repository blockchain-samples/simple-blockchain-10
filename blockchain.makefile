# Makefile - Blockchain 

run: main.o class-support.o 
	g++ main.o class-support.o -o run

class-support.o: class-support.cpp class-support.h hash_simple.h
	g++ -Wall -std=c++17 -c -g class-support.cpp 

 main.o: main.cpp class-support.h
	g++ -Wall -std=c++17 -c -g main.cpp
