mydate.exe: main.o mydate.o
	g++ --std=c++11 -o main.o mydate.o
main.o: main.cpp mydate.o
	g++ --std=c++11 -c main.cpp
mydate.o: mydate.cpp mydate.h
	g++ --std=c++11 -c mydate.cpp
clean:
	rm *.o
	