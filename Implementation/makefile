CC = g++ -O2 -Wno-deprecated 

tag = -i

ifdef linux
tag = -n
endif

all: Point Line Region  
	
Point: TestPoint2D.o Point2D.o RobustGeometricPrimitives2D.o Number.o BigRational.o BigInteger.o   
	$(CC) -o Point TestPoint2D.o Point2D.o RobustGeometricPrimitives2D.o Number.o BigRational.o BigInteger.o 
	
Line: TestLine2D.o Line2DImpl.o Line2D.o Point2D.o RobustGeometricPrimitives2D.o Number.o BigRational.o BigInteger.o 
	$(CC) -o Line TestLine2D.o Line2DImpl.o Line2D.o Point2D.o RobustGeometricPrimitives2D.o Number.o BigRational.o BigInteger.o 
	
Region: TestRegion2D.o Line2D.o Point2D.o Region2D.o Region2DImpl.o RobustGeometricPrimitives2D.o Number.o BigRational.o BigInteger.o 
	$(CC) -o Region TestRegion2D.o Line2D.o Point2D.o Region2D.o Region2DImpl.o RobustGeometricPrimitives2D.o Number.o BigRational.o BigInteger.o 
	
BigInteger.o: BigInteger.cpp
	$(CC) -g -std=c++0x -c BigInteger.cpp

BigRational.o: BigRational.cpp
	$(CC) -g -std=c++0x -c BigRational.cpp

Number.o: Number.cpp
	$(CC) -g -std=c++0x -c Number.cpp

RobustGeometricPrimitives2D.o: RobustGeometricPrimitives2D.cpp
	$(CC) -g -c -std=c++0x RobustGeometricPrimitives2D.cpp

Point2D.o: Point2D.cpp
	$(CC) -g -c -std=c++0x Point2D.cpp

Line2D.o: Line2D.cpp
	$(CC) -g -c -std=c++0x Line2D.cpp
	
Line2DImpl.o: Line2DImpl.cpp
	$(CC) -g -c -std=c++0x Line2DImpl.cpp

Region2D.o: Region2D.cpp
	$(CC) -g -c -std=c++0x Region2D.cpp

Region2DImpl.o: Region2DImpl.cpp
	$(CC) -g -c -std=c++0x Region2DImpl.cpp

TestPoint2D.o: TestPoint2D.cpp
	$(CC) -g -c -std=c++0x TestPoint2D.cpp
	
TestLine2D.o: TestLine2D.cpp
	$(CC) -g -c -std=c++0x TestLine2D.cpp
	
TestRegion2D.o: TestRegion2D.cpp
	$(CC) -g -c -std=c++0x TestRegion2D.cpp
	
clean: 
	rm -f *.o
	rm -f *.out
	rm -f Point
	rm -f Line
	rm -f Region
