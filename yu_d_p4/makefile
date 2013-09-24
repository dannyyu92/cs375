CPP=g++ -g

all: submission

submission: Program4.o Driver.o
	$(CPP) Program4.o Driver.o -o submission

Program4.o: Program4.cpp
	$(CPP) -c Program4.cpp

Driver.o: Driver.cpp
	$(CPP) -c Driver.cpp

clean:
	rm -f *.o submission
