/*******************************************************************
   PROGRAM:    CSCI 241 Assignment 1
   PROGRAMMER: Andrew Slade
   LOGON ID: Z1818810
   Section Number: 0004
   TA's Name: Sandadi
   DUE DATE: 02/07/2017
 
   FUNCTION:   This program tests functions for manipulating C 
               strings.
*********************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

//function prototypes
char* copy(char* destination, const char* source, size_t num);
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num);
char* reverseCopy(char* destination, const char* source, size_t num);
char* caseChangeCopy(char* destination, const char* source, size_t num); 
void read(char* destination, size_t num);
//-------------------

int main()
  {
    const int WORDSIZE = 15;
    char words[][WORDSIZE] = {"cattywampus", "collywobbles", "Lickety Split", "Kerfuffle", "Lollygag", ""};
    char word[WORDSIZE];

    //Test the copy function
    cout << "Copy \"cattywampus\", should see \"cattywampus\".\n";
    copy(word, words[0], sizeof(word) - 1);
    cout << word << endl << endl;
   
    // Test the limit on the copy function
    cout << "Copy \"Supercalifragilisticexpialidocious\", should see \"Super\".\n";
    copy(word, "Supercalifragilisticexpialidocious", 5);
    cout << word << endl << endl;

    // Test the replaceCopy function
    cout << "Replace 'l' in \"collywobbles\" with 'b', should see \"cobbywobbbes\".\n";
    replaceCopy(word, words[1], 'l', 'b', sizeof(word) - 1);
    cout << word << endl << endl;

    // Test the limit on the replaceCopy function
    cout << "Replace 's' in \"Supercalifragilistic\" with 'd', should see \"duper\".\n";
    replaceCopy(word, "Supercalifragilistic", 'S', 'd', 5);
    cout << word << endl << endl;

    // Test the caseChangeCopy function
    cout << "Case change \"Lickety Split\", should see \"lICKETY sPLIT\".\n";
    caseChangeCopy(word, words[2], sizeof(word) - 1);
    cout << word << endl << endl;

    // Test the limit on the caseChangeCopy function
    cout << "Case change \"Supercalifragilistic\", should see \"sUPER\".\n";
    caseChangeCopy(word, "Supercalifragilistic", 5);
    cout << word << endl << endl;  
   
    // Test the reverseCopy function
    cout << "Reverse \"Kerfuffle\", should see \"elffufreK\".\n";
    reverseCopy(word, words[3], sizeof(word) - 1);
    cout << word << endl << endl;

    // Test the limit on the reverseCopy function
    cout << "Reverse \"triskaidekaphobia\", should see \"ohpakediaksirt\".\n";
    reverseCopy(word, "triskaidekaphobia", sizeof(word) - 1);;
    cout << word << endl << endl;

    cout << "Reverse \"Lollygag\", change case, and replace 'G' with 'Z', should see \"ZAZYLLOl\".\n";
    replaceCopy(caseChangeCopy(reverseCopy(word, words[4], sizeof(word) - 1), word, sizeof(word) - 1), word, 'G', 'Z', sizeof(word) - 1);
    cout << word << endl << endl;  

    cout << "Enter your entire name: ";
    read(words[5], sizeof(words[5]));
    cout << words[5] << endl << endl;  
   
    cout << "Reverse your name and change case.\n";
    cout << caseChangeCopy(reverseCopy(word, words[5], sizeof(word) - 1), word, sizeof(word) - 1) << endl;
  
   return 0;
  }

// Add your function definitions here

/*****************************************************************
Function: copy

Use: copies the array.

Parameters: a character array, a constant character array, and a size.

Returns: A copied character array.

Notes: Uses strcpy().
*******************************************************************/
char* copy(char* destination, const char* source, size_t num)
  { 
  
    strncpy(destination,source, num);
    destination[num] = '\0'; 

   return destination;
  }
 

/********************************************************************
Function: replaceCopy

Use: Replaces characters in the array with designated characters.

Parameters: a character array, a constant character array, a character, a character, and a size.

Returns: An array with replaced values.

Notes: Uses strcpy and an iteration loop.
**********************************************************************/
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num)
  {
    strcpy(destination, source);
      for(int c = 0; destination[c] != '\0'; c++)
        {
          if(destination[c] == target)
            {
              destination[c] = replace; 
            }
        }
    destination[num] = '\0';

   return destination;
  }


/********************************************************************
Function: caseChangeCopy

Use: Changes the case of the letters in the copied array.

Parameters: a character array, a constant character array, and a size.

Returns: A character array with case changes present.

Notes: If and else if are used in order to check each value for type.
**********************************************************************/
char* caseChangeCopy(char* destination, const char* source, size_t num)
  {

    strncpy(destination, source, num);
    destination[num] = '\0';
 
    for(int i = 0; destination[i] != '\0'; i++)
      {
        if(isupper(destination[i]))
          { 
            destination[i]=(tolower(destination[i]));
          }
        else if(islower(destination[i]))
          {
            destination[i]=(toupper(destination[i]));
          }
        else if(isblank(destination[i]))
          {
            destination[i]=(destination[i]);
          }
      }

   return destination;
  } 


/********************************************************************
Function: reverseCopy

Use: reverses the characters in an array.

Parameters: a character array, a constant character array, and a size.

Returns: A character array that is reversed.

Notes: Passed value for num is not the word size. Need to use strlen - 1.
**********************************************************************/ 
char* reverseCopy(char* destination, const char* source, size_t num)
  {
    char holder[num - 1];
    int  newNum = 0 ;

    strncpy(destination, source, num);
    newNum = strlen(destination) - 1;
    holder[num] = '\0';
    strncpy(holder, destination, num);
 
    for(int j = 0; holder[j] != '\0'; j++)
      {
        destination[newNum - j] = holder[j];
      }

    destination[num] = '\0';
 
   return destination;
  }


/********************************************************************
Function: read

Use: Grabs user input.

Parameters: A char array pointer and the size of destination.

Returns: Nothing(void). However, destination is modified.

Notes: Uses getline() function to make sure accepts spaces and tabs and
 .c_str to make sur destination accepts value.
**********************************************************************/ 
void read(char* destination, size_t num)
  {
    string name= "default value";

    getline(cin, name);
    strcpy(destination, name.c_str());

   return; 
  }
