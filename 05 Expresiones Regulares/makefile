prueba: main.o infix.o prefix.o postfix.o ER2Tree.o alphabet.o
	g++  main.o infix.o prefix.o postfix.o ER2Tree.o alphabet.o -o prueba

main.o : ./src/main.cpp
	g++ -c ./src/main.cpp

infix.o: ./src/infix.cpp ./class/infix.hpp
	g++ -c ./src/infix.cpp

prefix.o: ./src/prefix.cpp ./class/prefix.hpp
	g++ -c ./src/prefix.cpp

postfix.o: ./src/postfix.cpp ./class/postfix.hpp
	g++ -c ./src/postfix.cpp

ER2Tree.o: ./src/ER2Tree.cpp ./class/ER2Tree.hpp
	g++ -c ./src/ER2Tree.cpp

alphabet.o: ./src/alphabet.cpp ./class/alphabet.hpp
	g++ -c ./src/alphabet.cpp

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf prueba
