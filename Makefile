CXX=clang++
# CXX=g++

run: Main.o
	${CXX} Main.o -o closest-point
	./closest-point

clean:
	/bin/rm -f *.o closest-point

Main.o: Main.cpp
	${CXX} -c Main.cpp