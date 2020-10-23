Contacts.exe: main.o ContactNode.o LL.o
	g++ --std=c++11 main.o ContactNode.o LL.o -o Contacts.exe
main.o: main.cpp ContactNode.o LL.o
	g++ --std=c++11 -c main.cpp
ContactNode.o: ContactNode.cpp ContactNode.h
	g++ --std=c++11 -c ContactNode.cpp
LL.o: LL.cpp LL.h ContactNode.o
	g++ --std=c++11 -c LL.cpp
clean:
	rm *.o Contacts.exe
	