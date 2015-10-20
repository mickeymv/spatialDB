all: SpatialOperationsMainClass.o SpatialOperations.o;
	g++ SpatialOperationsMainClass.o SpatialOperations.o -o SpatialOperationsProgram;
SpatialOperationsMainClass.o: SpatialOperationsMainClass.cpp SpatialOperations.h;
	g++ -c SpatialOperationsMainClass.cpp;
SpatialOperations.o: SpatialOperations.cpp SpatialOperations.h;
	g++ -c SpatialOperations.cpp;
clean:
	rm -rf *.o
	rm SpatialOperationsProgram;

