#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>

int original_puzzle[9][9];
int output_puzzle[9][9];
int test_puzzle[9][9];

void print_puzzle(int puzzle[9][9]) {
 
std::cout << std::endl << "The function (print_puzzle) has been called." << std::endl;
 
 int column = 0;
 int row = 0;
 
 while (row < 9) {
  
  while (column < 9) {
   
   std::cout << puzzle[column][row];
   column = column + 1;
   
  }
  
  std::cout << std::endl;
  row = row + 1;
  column = 0;
    
  }
  
 }
  
std::cout << "The function (print_puzzle) has concluded." << std::endl;
 
}

//Adds numbers to the original puzzle, which shouldn't be altered after this in any way.
void create_original_puzzle(std::ifstream &input_file) {
 
std::cout << std::endl << "The function (create_original_puzzle) has been called." << std::endl;  
 
 input_file.clear();
 input_file.seekg(0, input_file.beg);
 
 char temp;
 int column = 0;
 int row = 0;  
  while (input_file.get(temp)) {
   
std::cout << "Hey look I'm in the loop!" << std::endl;
   
    switch (temp) {
      
     case '0':
std::cout << "Case 0." << std::endl;
      original_puzzle[column][row] = 0;
      column = column + 1;
      break;
      
     case '1':
std::cout << "Case 1." << std::endl;
      original_puzzle[column][row] = 1;    
      column = column + 1;  
      break;
       
     case '2':
std::cout << "Case 2." << std::endl;
      original_puzzle[column][row] = 2;
      column = column + 1;
      break;

     case '3':
std::cout << "Case 3." << std::endl;
      original_puzzle[column][row] = 3;
      column = column + 1;
      break;
      
     case '4':
std::cout << "Case 4." << std::endl;
      original_puzzle[column][row] = 4;
      column = column + 1;
      break;
      
     case '5':
std::cout << "Case 5." << std::endl;
      original_puzzle[column][row] = 5;
      column = column + 1;
      break;
      
     case '6':
std::cout << "Case 6." << std::endl;
      original_puzzle[column][row] = 6;
      column = column + 1;
      break;
      
     case '7':
std::cout << "Case 7." << std::endl;
      original_puzzle[column][row] = 7;
      column = column + 1;
      break;
      
     case '8':
std::cout << "Case 8." << std::endl;
      original_puzzle[column][row] = 8;
      column = column + 1;
      break;
      
     case '9':
std::cout << "Case 9." << std::endl;
      original_puzzle[column][row] = 9;
      column = column + 1;
      break;
      
     case '\n':
std::cout << "Case endline." << std::endl;
     row = row + 1;
     column = 0;
     break;
      
     default:
      std::cout << "The original_puzzle could not be created. It appears that an odd character was found in the input file." 
       << std::endl << "Program closing..." << std::endl;
      exit(1);
      break;
      
    }
    
  }
  
std::cout << "The function (create_original_puzzle) has concluded." << std::endl;
  
}




/*
* This function will take in INPUT_FILE, printing its contents to the terminal one char at a time.
*/
void print_input_file(std::ifstream &input_file) {
 
std::cout << std::endl << "The function (print_input_file) has been called." << std::endl;  
  
 input_file.clear();
 input_file.seekg(0, input_file.beg);
 
  char temp;
  
  while (input_file.get(temp)) {
   
    std::cout << temp;
    
  }
  
std::cout << "The function (print_input_file) has concluded." << std::endl;
  
}

/*
* First, checks to make sure that only two arguments were used during the command call.
*   If not, print out expected syntax and stop executing.
* Second, attempts to open the input file (second argument).
*   If opening the expected file fails, than output error and stop executing.
* Third, print the input file to terminal to ensure correct formatting.
* Fourth, wait for user to ensure that the input file is correct.
* TODO...
*/
//TODO Make sure this works correctly.
int main (int argc, char *argv[]) {

  if (argc != 2) {
   
    std::cout << "Incorrect syntax. Please use the following syntax:" << std::endl
      << "<command> <location of input file>" << std::endl << std::endl << "Program closing..." << std::endl;
    
  } else {
    
    std::ifstream input_file (argv[1]);
    
    if (!input_file.is_open()) {
      
      std::cout << "The input file (" << argv[1] << ") failed to open." << std::endl
        << "Program closing..." << std::endl;
            
    } else {
     
      print_input_file(input_file);
      char answer;
      std::cout << "Please ensure that the previously printed file is the intended file." << std::endl
        << "Also ensure that the printed file is correctly formatted for this program." << std::endl
        << "The expected formatting can be found within README.md" << std::endl << std::endl
        << "Is this file ready for execution? (Y / N):";
      std::cin >> answer;
      if (answer == 'Y') {
       
        create_original_puzzle(input_file);
       print_puzzle(original_puzzle);
        
      } else {
       
        std::cout << "Please run this command with a different file." << std::endl
          << "Program closing..." << std::endl;
        
      }
      
    }
    
  }

}
