CC = g++ -std=c++0x -std=gnu++0x -O2 -Wno-deprecated 

tag = -i

ifdef linux
tag = -n
endif

main: Number.o Point2D.o RobustGeometricPrimitives2D.o Region2D.o Region2DImpl.o SpatialDataType.o Line2D.o Line2DImpl.o unarySpatialOperators.o y.tab.o lex.yy.o main.o
	$(CC) -o main Number.o Point2D.o RobustGeometricPrimitives2D.o  Region2D.o Region2DImpl.o SpatialDataType.o  Line2D.o Line2DImpl.o y.tab.o lex.yy.o main.o -lfl
	
Number.o: Number.cpp
	$(CC) -g -c Number.cpp

Point2D.o: Point2D.cpp
	$(CC) -g -c Point2D.cpp

RobustGeometricPrimitives2D.o: RobustGeometricPrimitives2D.cpp
	$(CC) -g -c RobustGeometricPrimitives2D.cpp

Line2D.o: Line2D.cpp
	$(CC) -g -c Line2D.cpp

Line2DImpl.o: Line2DImpl.cpp
	$(CC) -g -c Line2DImpl.cpp
	
Region2D.o: Region2D.cpp
	$(CC) -g -c Region2D.cpp

Region2DImpl.o: Region2DImpl.cpp
	$(CC) -g -c Region2DImpl.cpp

SpatialDataType.o: SpatialDataType.cpp
	$(CC) -g -c SpatialDataType.cpp
	
y.tab.o: Parser.y
	yacc -d Parser.y
	sed $(tag) y.tab.c -e "s/  __attribute__ ((__unused__))$$/# ifndef __cplusplus\n  __attribute__ ((__unused__));\n# endif/" 
	g++ -c y.tab.c

lex.yy.o: Lexer.l
	lex  Lexer.l
	gcc  -c lex.yy.c

clean: 
	rm -f *.o
	rm -f *.out
	rm -f y.tab.c
	rm -f lex.yy.c
	rm -f y.tab.h
