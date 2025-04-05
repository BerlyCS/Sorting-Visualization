libs=-lncurses
cflags=-ggdb3 -Wall -Wdeprecated -O0
CC=g++
main: main.cpp renderer.cpp renderer.hpp sort_array.cpp sort_array.hpp
	g++ main.o renderer.o sort_array.o -o main $(cflags) $(libs)


main.o:
	g++ main.cpp -c -o main.o

renderer.o:
	g++ renderer.cpp -c -o renderer.o

sort_array.o:
	g++ sort_array.cpp -c -o sort_array.o
