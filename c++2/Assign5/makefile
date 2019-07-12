#
#Program: assign5
#Programmer: Andrew Slade
#Logon ID: z1818810
#Date Due: 03/28/2017
#

#compiler variables
CCFLAGS = -Wall -std=c++11 

#Rule to link object code files to create executables
assign5: assign5.o NIUString.o
	g++ $(CCFLAGS) -o assign5 assign5.o NIUString.o

#Rule to compile assign5 source code
assign5.o: assign5.cpp NIUString.h
	g++ $(CCFLAGS) -c assign5.cpp

#Rule to compile NIUString object file
NIUString.o: NIUString.h NIUString.cpp
	g++ $(CCFLAGS) -c NIUString.cpp

#Psuedo-target for cleaning purposes
clean:
	-rm *.o assign5
