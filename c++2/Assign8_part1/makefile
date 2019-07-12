#
#Program: assign7
#Programmer: Andrew Slade
#Logon ID: z1818810
#Date Due: 04/25/2017
#

#compiler variables
CCFLAGS = -Wall -std=c++11 

#Rule to link object code files to create executables
assign8: assign8.o 
	g++ $(CCFLAGS) -o assign8 assign8.o 

#Rule to compile assign8 source code
assign8.o: assign8.cpp sorts.h
	g++ $(CCFLAGS) -c assign8.cpp

#Psuedo-target for cleaning purposes
clean:
	-rm *.o assign8

