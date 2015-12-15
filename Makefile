all:
	g++ spatialDB-Topic1/BigRational.cpp spatialDB-Topic1/BigInteger.cpp spatialDB-Topic1/Number.cpp divide_n_con.cpp dataGenerator.cpp -std=c++11 -I ./spatialDB-Topic1/

test: BigRational.o BigInteger.o Number.o dataGenerator.o divide_n_con.o
	g++ BigRational.o BigInteger.o Number.o dataGenerator.o divide_n_con.o -std=c++11 -I ./spatialDB-Topic1/ -o test


divide_n_con.o: divide_n_con.cpp
	g++ -c divide_n_con.cpp -I ./spatialDB-Topic1/ -std=c++11

dataGenerator.o: dataGenerator.cpp
	g++ -c dataGenerator.cpp -I ./spatialDB-Topic1/ -std=c++11


BigRational.o: ./spatialDB-Topic1/BigRational.cpp
	g++ -c ./spatialDB-Topic1/BigRational.cpp -I ./spatialDB-Topic1/ -std=c++11
BigInteger.o: ./spatialDB-Topic1/BigInteger.cpp
	g++ -c ./spatialDB-Topic1/BigInteger.cpp -I ./spatialDB-Topic1/ -std=c++11
Number.o: ./spatialDB-Topic1/Number.cpp
	g++ -c ./spatialDB-Topic1/Number.cpp -I ./spatialDB-Topic1/ -std=c++11




clean:
	rm *.o test test_in test_out

