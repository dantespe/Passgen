test:
	g++ --std=c++11 main.cpp Passgen.cpp -o passwords.exe

clean:
	rm -rf *.exe *.out
