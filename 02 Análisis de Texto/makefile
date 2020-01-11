prueba : main.o analizador.o
	g++  main.o analizador.o -o prueba

main.o : main.cpp
	g++ -c main.cpp

analizador.o: analizador.cpp analizador.hpp
	g++ -c analizador.cpp

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf prueba
