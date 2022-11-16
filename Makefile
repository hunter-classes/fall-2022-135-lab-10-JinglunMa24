main: main.o func.o
	g++ -o main main.o func.o

tests: tests.o func.o
	g++ -o tests tests.o func.o


func.o: func.cpp func.h time.h

main.o: main.cpp func.h time.h

tests.o: tests.cpp doctest.h func.h time.h

clean:
	rm -f main.o func.o tests.o