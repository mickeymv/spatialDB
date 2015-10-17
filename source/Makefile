all: MainClass.o Group3SpatialOperations.o;
	g++ MainClass.o Group3SpatialOperations.o -o Group3SpatialOperationsProgram;
MainClass.o: MainClass.cpp Group3SpatialOperations.h;
	g++ -c MainClass.cpp;
Group3SpatialOperations.o: Group3SpatialOperations.cpp Group3SpatialOperations.h;
	g++ -c Group3SpatialOperations.cpp;
clean:
	rm -rf *.o
	rm Group3SpatialOperationsProgram;

