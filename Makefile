all:debug test
debug:debug.cpp debugger.cpp guiInterface.cpp
	g++ debugger.cpp -c -std=c++11
	g++ guiInterface.cpp -c `wx-config --libs all --cxxflags` -std=c++11
	g++ debug.cpp debugger.o guiInterface.o -o loopdebug `wx-config --libs all --cxxflags` -std=c++11
test:test.cpp
	g++ test.cpp -o test -std=c++11
.PHONY:
clean:
	-rm loopdebug test