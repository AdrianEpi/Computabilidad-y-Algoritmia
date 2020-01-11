prueba: main.o element.o unComment.o state.o transition.o
	g++  main.o element.o unComment.o state.o transition.o -o prueba

main.o : ./src/main.cpp
	g++ -c ./src/main.cpp

element.o: ./src/element.cpp ./class/element.hpp
	g++ -c ./src/element.cpp

unComment.o: ./src/unComment.cpp ./class/unComment.hpp
	g++ -c ./src/unComment.cpp

state.o: ./src/state.cpp ./class/state.hpp
	g++ -c ./src/state.cpp

transition.o: ./src/transition.cpp ./class/transition.hpp
	g++ -c ./src/transition.cpp

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf prueba
