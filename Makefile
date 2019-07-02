CC =g++

LIB = lib
INCLUDE = include
SRC = src
BUILD = build
BIN = bin

BIN_NAME = executavel

TARGET_LIB = petfera.so
FLAGS = -Wall -pedantic -std=c++11 -g -O0

all: $(TARGET_LIB) $(BIN_NAME)

$(TARGET_LIB): $(INCLUDE)/petfera.h
	$(CC) -fPIC -c $(SRC)/animal.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/animal.o
	$(CC) -fPIC -c $(SRC)/animal_silvestre.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/animal_silvestre.o
	$(CC) -fPIC -c $(SRC)/animal_nativo.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/animal_nativo.o
	$(CC) -fPIC -c $(SRC)/animal_exotico.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/animal_exotico.o
	$(CC) -fPIC -c $(SRC)/anfibio.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/anfibio.o
	$(CC) -fPIC -c $(SRC)/anfibio_exotico.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/anfibio_exotico.o
	$(CC) -fPIC -c $(SRC)/anfibio_nativo.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/anfibio_nativo.o
	$(CC) -fPIC -c $(SRC)/ave.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/ave.o
	$(CC) -fPIC -c $(SRC)/ave_exotica.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/ave_exotica.o
	$(CC) -fPIC -c $(SRC)/ave_nativa.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/ave_nativa.o
	$(CC) -fPIC -c $(SRC)/date.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/date.o
	$(CC) -fPIC -c $(SRC)/funcionario.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/funcionario.o
	$(CC) -fPIC -c $(SRC)/mamifero.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/mamifero.o
	$(CC) -fPIC -c $(SRC)/mamifero_nativo.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/mamifero_nativo.o
	$(CC) -fPIC -c $(SRC)/mamifero_exotico.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/mamifero_exotico.o
	$(CC) -fPIC -c $(SRC)/petshop.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/petshop.o
	$(CC) -fPIC -c $(SRC)/reptil.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/reptil.o
	$(CC) -fPIC -c $(SRC)/reptil_nativo.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/reptil_nativo.o
	$(CC) -fPIC -c $(SRC)/reptil_exotico.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/reptil_exotico.o
	$(CC) -fPIC -c $(SRC)/tratador.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/tratador.o
	$(CC) -fPIC -c $(SRC)/veterinario.cpp $(FLAGS) -I$(INCLUDE) -o $(BUILD)/veterinario.o
	$(CC) -shared -fPIC -o $(LIB)/$@ $(BUILD)/*.o
	@echo "+++ [Biblioteca dinâmica criada em $(LIB)/$@] +++" 	

$(BIN_NAME): 
	$(CC) $(SRC)/main.cpp $(FLAGS) -I$(INCLUDE) $(LIB)/$(TARGET_LIB) -o $(BIN)/$@
	./$(BIN)/$@

clean:
	rm $(BIN)/* $(BUILD)/* $(LIB)/*
	@echo "+++[Remoção de binários, objetos e bibliotecas] +++" 	
