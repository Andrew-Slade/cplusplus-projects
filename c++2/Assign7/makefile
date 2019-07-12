#
#Program: assign7
#Programmer: Andrew Slade
#Logon ID: z1818810
#Date Due: 04/18/2017
#

#compiler variables
CCFLAGS = -Wall -std=c++11 

#Rule to link object code files to create executables
assign7: assign7.o 
	g++ $(CCFLAGS) -o assign7 assign7.o 

#Rule to compile assign7 source code
assign7.o: assign7.cpp Stack.h
	g++ $(CCFLAGS) -c assign7.cpp

#Psuedo-target for cleaning purposes
clean:
	-rm *.o assign7

