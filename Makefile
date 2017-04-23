CXX=clang++
# CXX=g++

all:
	$(MAKE) clean
	$(MAKE) run

run: Main.o
	${CXX} Main.o -o closest-point
	./closest-point

test:
	$(MAKE) test1
	$(MAKE) test2
	$(MAKE) test3
	$(MAKE) test4
	$(MAKE) test5

test1: Main.o
	${CXX} Main.o -o closest-point
	./closest-point < tests/test1 > tests/output1
	diff tests/output1 tests/result1

test2: Main.o
	${CXX} Main.o -o closest-point
	./closest-point < tests/test2 > tests/output2
	diff tests/output2 tests/result2

test3: Main.o
	${CXX} Main.o -o closest-point
	./closest-point < tests/test3 > tests/output3
	diff tests/output3 tests/result3

test4: Main.o
	${CXX} Main.o -o closest-point
	./closest-point < tests/test4 > tests/output4
	diff tests/output4 tests/result4

test5: Main.o
	${CXX} Main.o -o closest-point
	./closest-point < tests/test5 > tests/output5
	diff tests/output5 tests/result5

clean:
	/bin/rm -f *.o closest-point

Main.o: Main.cpp
	${CXX} -c Main.cpp
