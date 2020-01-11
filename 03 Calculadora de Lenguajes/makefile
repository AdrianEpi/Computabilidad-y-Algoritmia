prueba : main.o calculator.o language.o reader.o
	g++  main.o calculator.o language.o reader.o -o prueba

main.o : main.cpp
	g++ -c main.cpp

calculator.o: calculator.cpp calculator.hpp
	g++ -c calculator.cpp

language.o: language.cpp language.hpp
	g++ -c language.cpp

reader.o: reader.cpp reader.hpp
	g++ -c reader.cpp

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf prueba
