CXX=clang++
# CXX=g++

all:
	$(MAKE) clean
	$(MAKE) run

run: Main.o
	${CXX} Main.o -o closest-point
	./closest-point

clean:
	/bin/rm -f *.o closest-point

Main.o: Main.cpp
	${CXX} -c Main.cpp
