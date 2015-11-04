CC = g++ -std=c++0x -std=gnu++0x -O2 -Wno-deprecated 

tag = -i

ifdef linux
tag = -n
endif

main: Number.o Point2D.o RobustGeometricPrimitives2D.o TestPoint2D.o main.o
	$(CC) -o main Number.o Point2D.o RobustGeometricPrimitives2D.o  TestPoint2D.o main.o -lfl
	
Number.o: Number.cpp
	$(CC) -g -c Number.cpp

Point2D.o: Point2D.cpp
	$(CC) -g -c Point2D.cpp

RobustGeometricPrimitives2D.o: RobustGeometricPrimitives2D.cpp
	$(CC) -g -c RobustGeometricPrimitives2D.cpp

TestPoint2D.o: TestPoint2D.cpp
	$(CC) -g -c TestPoint2D.cpp
	

clean: 
	rm -f *.o
	rm -f *.out
	
