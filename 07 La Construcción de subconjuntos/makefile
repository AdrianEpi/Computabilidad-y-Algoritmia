#Variable objetos
OBJECTS = main.o DFA.o state.o transition.o alphabet.o reader.o NFA.o

#Flags de compilacion
CFLAGS = -c -std=c++17 #-Wall

##Si no se pasa parámetro creará prueba por defecto	
all: prueba

#Programa principal, cuando finaliza envia los ".o" a la carpeta "objects" y la salida a "outputs"
prueba: $(OBJECTS)
	g++ -std=c++17 $(OBJECTS) -o prueba
	mv *.o ./objects
	mv prueba ./outputs

#Objetos de compilacion
main.o : ./src/main.cpp
	g++ $(CFLAGS) ./src/main.cpp

DFA.o: ./src/DFA.cpp ./class/DFA.hpp
	g++ $(CFLAGS) ./src/DFA.cpp

state.o: ./src/state.cpp ./class/state.hpp
	g++ $(CFLAGS) ./src/state.cpp

transition.o: ./src/transition.cpp ./class/transition.hpp
	g++ $(CFLAGS) ./src/transition.cpp

alphabet.o: ./src/alphabet.cpp ./class/alphabet.hpp
	g++ $(CFLAGS) ./src/alphabet.cpp

reader.o: ./src/reader.cpp ./class/reader.hpp
	g++ $(CFLAGS) ./src/reader.cpp

NFA.o: ./src/NFA.cpp ./class/NFA.hpp
	g++ $(CFLAGS) ./src/NFA.cpp

#Funcion para borrar objetos
.PHONY: clean
clean:
	rm -rf ./objects/*.o
	rm -rf ./Outputs/prueba

#Funcion para crear archivo DOT
.PHONY: DOT
DOT:
	dot -Tsvg < ./Outputs/Output.gv > ./Outputs/DFA.svg
