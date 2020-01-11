#Flags de compilacion
CFLAGS = -c -std=c++11

G2NFA: G2CNF.o Grammar.o NFA.o DFA.o State.o Transition.o Alphabet.o
	g++  G2CNF.o Grammar.o NFA.o DFA.o State.o Transition.o Alphabet.o -o G2CNF

G2CNF.o: G2CNF.cpp
	g++ $(CFLAGS) G2CNF.cpp

Grammar.o: Grammar.cpp Grammar.hpp
	g++ $(CFLAGS) Grammar.cpp

NFA.o: NFA.cpp NFA.hpp
	g++ $(CFLAGS) NFA.cpp

DFA.o: DFA.cpp DFA.hpp
	g++ $(CFLAGS) DFA.cpp

State.o: State.cpp State.hpp
	g++ $(CFLAGS) State.cpp

Transition.o: Transition.cpp Transition.hpp
	g++ $(CFLAGS) Transition.cpp

Alphabet.o: Alphabet.cpp Alphabet.hpp
	g++ $(CFLAGS) Alphabet.cpp

.PHONY: clean
clean:
	rm -rf *.o out_file.gra *.nfa *.dfa *.gv *.svg G2CNF