all: MainClass.o SpatialOperations.o;
	g++ MainClass.o SpatialOperations.o -o SpatialOperationsProgram;
MainClass.o: MainClass.cpp SpatialOperations.h;
	g++ -c MainClass.cpp;
SpatialOperations.o: SpatialOperations.cpp SpatialOperations.h;
	g++ -c SpatialOperations.cpp;
clean:
	rm -rf *.o
	rm SpatialOperationsProgram;

