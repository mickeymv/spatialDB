all: MainClass.o spatialoperations.o;
	g++ MainClass.o spatialoperations.o -o spatialOperationsProgram;
MainClass.o: MainClass.cpp spatialoperations.h;
	g++ -c MainClass.cpp;
spatialoperations.o: spatialoperations.cpp spatialoperations.h;
	g++ -c spatialoperations.cpp;
clean:
	rm -rf *.o
	rm spatialOperationsProgram;

