CPP=g++ -g

all: submission

submission: Program2.o Driver.o Node.o
	$(CPP) Program2.o Driver.o Node.o -o submission

Node.o: Node.cpp
	$(CPP) -c Node.cpp

Program2.o: Program2.cpp
	$(CPP) -c Program2.cpp

Driver.o: Driver.cpp
	$(CPP) -c Driver.cpp

clean:
	rm -f *.o submission
