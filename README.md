# spatialDB
A common repository for sharing the files and interfaces necessary for the Spatial and Temporal Databases Fall '15 class.

Common Info:

We have the five topics
Big Rational Arithmetic and Robust Geometric Primitives (4 students)
Spatial Data Types Point, Line, and Region (4 students)
Spatial Operations for intersection, union, and difference based on plane sweep method (4 students)
Topological Relationships (5 students)
Convex Hull Algorithms (4 students)
that will be implemented by five groups. Group k will handle topic k. Please send me the assignment of students to groups until tomorrow.

General comments:
All data types must be implemented as abstract data types in C++. See here. 
http://www.cise.ufl.edu/~mschneid/Teaching/CIS4930+CIS6930_Fall2015/Literature/Headington.pdf
We will use the Opaque Type approach (Section 4.1).

The C++ code must be sufficiently documented.
Guidelines for writing C++ code are here and have to be followed. Readability is very important!
http://www.cise.ufl.edu/~mschneid/Research/C++%20Programming%20Style%20Guidelines.htm

All implemented data structures and algorithms have to be intensively tested regarding their correctness (special cases).

All C++ code must run on Linux under the gcc/g++ compiler. More precisely, we assume that the compiler supports the C++11 standard.

Development on other platforms is allowed. For example, you can use Visual C++ for Visual Studio or cygwin. But finally the code must run on Linux with the gcc compiler, which is usually not a problem due to the standardization of C++.

A graphical user interface has to be implemented by the whole group in order to be able to graphically test the result of spatial data structures, spatial operations, and topological predicates. It would be great if the user interface(s) would run on a web page so that the software can be tried from everywhere. A discussion will be needed among you and with me.

The tool "make" has to be used in order to compile and link the individual software components with their test/demo program and the whole library.
