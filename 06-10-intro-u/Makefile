all: first.cpp second.cpp third.cpp fourth.cpp fift.cpp
	g++ -o first.o first.cpp 
	g++ -o second.o second.cpp
	g++ -o third.o third.cpp
	g++ -o fourth.o fourth.cpp
	g++ -o fift.o fift.cpp
	./first.o
	./second.o
	./third.o
	./fourth.o
	./fift.o

1: first.cpp
	g++ -o first.o first.cpp 
	./first.o
2: second.cpp
	g++ -o second.o second.cpp
	./second.o
3: third.cpp
	g++ -o third.o third.cpp
	./third.o
4: fourth.cpp
	g++ -o fourth.o fourth.cpp
	./fourth.o
5: fift.cpp
	g++ -o fift.o fift.cpp
	./fift.o

clean:
	rm *.o