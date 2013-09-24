CPP=g++ -g

all: submission

submission: Program1.o Driver.o
	$(CPP) Program1.o Driver.o -o submission

Program1.o: Program1.cpp
	$(CPP) -c Program1.cpp

Driver.o: Driver.cpp
	$(CPP) -c Driver.cpp

clean:
	rm -f *.o submission
