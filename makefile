airline_analysis: main.o LinkedList.o
	g++ -Wall -pedantic -g -o airline_analysis main.o LinkedList.o

main.o: main.cpp LinkedList.h FlightRecord.h
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp

LinkedList.o: LinkedList.cpp LinkedList.h FlightRecord.h
	g++ -Wall -pedantic -g -std=c++11 -c LinkedList.cpp

clean:
	rm -f airline_analysis airline_analysis.exe main.o LinkedList.o