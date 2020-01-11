#Flags de compilacion
CFLAGS = -c -std=c++11

G2NFA: G2NFA.o Grammar.o NFA.o DFA.o State.o Transition.o Alphabet.o
	g++  G2NFA.o Grammar.o NFA.o DFA.o State.o Transition.o Alphabet.o -o G2NFA
	mv *.o ./objects
	mv G2NFA ./outputs


G2NFA.o: ./src/G2NFA.cpp
	g++ $(CFLAGS) ./src/G2NFA.cpp

Grammar.o: ./src/Grammar.cpp ./class/Grammar.hpp
	g++ $(CFLAGS) ./src/Grammar.cpp

NFA.o: ./src/NFA.cpp ./class/NFA.hpp
	g++ $(CFLAGS) ./src/NFA.cpp

DFA.o: ./src/DFA.cpp ./class/DFA.hpp
	g++ $(CFLAGS) ./src/DFA.cpp

State.o: ./src/State.cpp ./class/State.hpp
	g++ $(CFLAGS) ./src/State.cpp

Transition.o: ./src/Transition.cpp ./class/Transition.hpp
	g++ $(CFLAGS) ./src/Transition.cpp

Alphabet.o: ./src/Alphabet.cpp ./class/Alphabet.hpp
	g++ $(CFLAGS) ./src/Alphabet.cpp




.PHONY: clean
clean:
	rm -rf ./objects/*.o
	rm -rf ./objects/*.nfa
	rm -rf ./objects/*.dfa
	rm -rf ./objects/*.gv
	rm -rf ./objects/*.svg
	rm -rf ./outputs/G2NFA

SVG: 
	./NFA2DFA ./outputs/*.nfa DFA.dfa
	./DFA2dot DFA.dfa DFA.gv
	dot -Tsvg <DFA.gv> DFA.svg
	mv *.gv ./objects
	mv *.dfa ./objects
	mv *.svg ./outputs

run:
	./outputs/G2NFA ./inputs/input.gra ./outputs/output.nfa
	./NFA2DFA ./outputs/*.nfa DFA.dfa
	./DFA2dot DFA.dfa DFA.gv
	dot -Tsvg <DFA.gv> DFA.svg
	mv *.gv ./objects
	mv *.dfa ./objects
	mv *.svg ./outputs