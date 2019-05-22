all:robodebug test
robodebug:robodebug.cpp
	g++ robodebug.cpp -o robodebug -std=c++11
test:test.cpp
	g++ test.cpp -o test -std=c++11
.PHONY:
clean:
	-rm robodebug test