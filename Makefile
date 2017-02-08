test:
	g++ --std=c++11 main.cpp Passgen.cpp -o Passgen

clean:
	rm -rf *.exe *.out *.dSYM Passgen
