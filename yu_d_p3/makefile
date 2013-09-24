CPP=g++ -g

all: submission

submission: Program3.o Driver.o
	$(CPP) Program3.o Driver.o -o submission

Program3.o: Program3.cpp
	$(CPP) -c Program3.cpp

Driver.o: Driver.cpp
	$(CPP) -c Driver.cpp

clean:
	rm -f *.o submission
