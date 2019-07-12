#
#Program: assign4
#Programmer: Andrew Slade
#Logon ID: z1818810
#Date Due: 03/09/2017
#

#compiler variables
CCFLAGS = -Wall -std=c++11 

#Rule to link object code files to create executables
assign4: assign4.o Matrix.o
	g++ $(CCFLAGS) -o assign4 assign4.o Matrix.o

#Rule to compile assign4 source code
assign4.o: assign4.cpp Matrix.h
	g++ $(CCFLAGS) -c assign4.cpp

#Rule to compile Matrix object file
Matrix.o: Matrix.h Matrix.cpp
	g++ $(CCFLAGS) -c Matrix.cpp

#Psuedo-target for cleaning purposes
clean:
	-rm *.o assign4
