#
#PROGRAM: assign3
#PROGRAMMER: Andrew Slade
#LOGON ID: z1818810
#DATE DUE: 02/28/2017
#

#Compiler variables
CCFLAGS = -Wall -std=c++11

#Rule to link object code files to create executable file
assign3: assign3.o Monkey.o
	g++ $(CCFLAGS) -o assign3 assign3.o Monkey.o

#Rules to compile source code files to object code
assign3.o: assign3.cpp Monkey.h
	g++ $(CCFLAGS) -c assign3.cpp

Monkey.o: Monkey.cpp Monkey.h
	g++ $(CCFLAGS) -c Monkey.cpp

#Psuedo-target to remove object code and executable files
clean:
	-rm *.o assign3
