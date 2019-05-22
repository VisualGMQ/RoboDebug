all:debug test
debug:debug.cpp debugger.cpp
	g++ debug.cpp debugger.cpp -o loopdebug -std=c++11
test:test.cpp
	g++ test.cpp -o test -std=c++11
.PHONY:
clean:
	-rm loopdebug test