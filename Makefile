CC=g++

INCLUDE=./include
SRC=./src

FLAGS = -Wall -std=c++11 -g -O0

main:
	$(CC) $(SRC)/*.cpp $(FLAGS) -I$(INCLUDE) -o prog
	./prog

	
