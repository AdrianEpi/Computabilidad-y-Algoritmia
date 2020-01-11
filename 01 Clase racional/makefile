prueba : main.o rational.o
	g++  main.o rational.o -o prueba

main.o : main.cpp
	g++ -c main.cpp

rational.o: rational.cpp rational.hpp
	g++ -c rational.cpp

.PHONY: clean
clean:
	rm -rf *.o
