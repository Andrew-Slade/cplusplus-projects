#
#Program: assign6
#Programmer: Andrew Slade
#Logon ID: z1818810
#Date Due: 04/11/2017
#

#compiler variables
CCFLAGS = -Wall -std=c++11 

#Rule to link object code files to create executables
assign6: assign6.o Queue.o
	g++ $(CCFLAGS) -o assign6 assign6.o Queue.o

#Rule to compile assign6 source code
assign6.o: assign6.cpp Queue.h
	g++ $(CCFLAGS) -c assign6.cpp

#Rule to compile Queue object file
Queue.o: Queue.h Queue.cpp
	g++ $(CCFLAGS) -c Queue.cpp

#Psuedo-target for cleaning purposes
clean:
	-rm *.o assign6

