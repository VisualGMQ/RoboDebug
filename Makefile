all:robodebug
robodebug:robodebug.cpp
	g++ robodebug.cpp -o robodebug -std=c++11
.PHONY:
clean:
	-rm robodebug