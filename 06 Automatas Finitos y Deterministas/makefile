prueba: main.o DFA.o state.o transition.o alphabet.o reader.o
	g++ -std=c++17 main.o DFA.o state.o transition.o alphabet.o reader.o -o prueba

main.o : ./src/main.cpp
	g++ -c -std=c++17 ./src/main.cpp

DFA.o: ./src/DFA.cpp ./class/DFA.hpp
	g++ -c -std=c++17 ./src/DFA.cpp

state.o: ./src/state.cpp ./class/state.hpp
	g++ -c -std=c++17 ./src/state.cpp

transition.o: ./src/transition.cpp ./class/transition.hpp
	g++ -c -std=c++17 ./src/transition.cpp

alphabet.o: ./src/alphabet.cpp ./class/alphabet.hpp
	g++ -c -std=c++17 ./src/alphabet.cpp

reader.o: ./src/reader.cpp ./class/reader.hpp
	g++ -c -std=c++17 ./src/reader.cpp

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf prueba
