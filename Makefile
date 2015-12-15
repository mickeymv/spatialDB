all:
	g++ spatialDB-Topic1/BigRational.cpp spatialDB-Topic1/BigInteger.cpp spatialDB-Topic1/Number.cpp divideconquer.cpp dataGenerator.cpp -std=c++11 -I ./spatialDB-Topic1/

test: graham.o newalgo.o jarvis.o BigRational.o BigInteger.o Number.o dataGenerator.o divideconquer.o
	g++ graham.o newalgo.o jarvis.o BigRational.o BigInteger.o Number.o dataGenerator.o divideconquer.o -std=c++11 -I ./spatialDB-Topic1/ -o test


divideconquer.o: divideconquer.cpp poi2D.h ./spatialDB-Topic1/Number.h
	g++ -c divideconquer.cpp -I ./spatialDB-Topic1/ -std=c++11

graham.o: graham.cpp poi2D.h ./spatialDB-Topic1/Number.h
	g++ -c graham.cpp -I ./spatialDB-Topic1/ -std=c++11

newalgo.o: newalgo.cpp poi2D.h ./spatialDB-Topic1/Number.h
	g++ -c newalgo.cpp -I ./spatialDB-Topic1/ -std=c++11

jarvis.o: jarvis.cpp poi2D.h ./spatialDB-Topic1/Number.h
	g++ -c jarvis.cpp -I ./spatialDB-Topic1/ -std=c++11

dataGenerator.o: dataGenerator.cpp ConvexHull.h  poi2D.h ./spatialDB-Topic1/Number.h
	g++ -c dataGenerator.cpp -I ./spatialDB-Topic1/ -std=c++11


BigRational.o: ./spatialDB-Topic1/BigRational.cpp ./spatialDB-Topic1/Number.h
	g++ -c ./spatialDB-Topic1/BigRational.cpp -I ./spatialDB-Topic1/ -std=c++11
BigInteger.o: ./spatialDB-Topic1/BigInteger.cpp ./spatialDB-Topic1/Number.h
	g++ -c ./spatialDB-Topic1/BigInteger.cpp -I ./spatialDB-Topic1/ -std=c++11
Number.o: ./spatialDB-Topic1/Number.cpp ./spatialDB-Topic1/Number.h
	g++ -c ./spatialDB-Topic1/Number.cpp -I ./spatialDB-Topic1/ -std=c++11




clean:
	rm *.o test test_in test_out

