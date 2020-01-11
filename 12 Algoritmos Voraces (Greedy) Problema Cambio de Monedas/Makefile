#Flags de compilacion
CFLAGS = -c -std=c++11

Greedy: Greedy.o MoneyChanger.o
	g++  Greedy.o MoneyChanger.o -o Greedy
	mv *.o ./objects
	mv Greedy ./outputs


Greedy.o: ./src/Greedy.cpp
	g++ $(CFLAGS) ./src/Greedy.cpp

MoneyChanger.o: ./src/MoneyChanger.cpp ./class/MoneyChanger.hpp
	g++ $(CFLAGS) ./src/MoneyChanger.cpp


.PHONY: clean
clean:
	rm -rf ./objects/*.o
	rm -rf ./outputs/Greedy


run:
	./outputs/Greedy 
