#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>

//Setup the puzzles for later manipulation.
//The first entry ios the column, second is the row,
//and the third is used to remember the possible numbers
//that the cell can be. puzzle[x][y][0] is the current number
//that is used within the cell at locaiton (x, y).
int original_puzzle[9][9][10];
int output_puzzle[9][9][10];
int test_puzzle[9][9][10];

//Remove the NUMBER from the list off possible numbers that the cell can be
//at the location passed in.
//Only called at puzzle creation, and when a number is SURE to be the only possible answer.
void remove_number(int puzzle[9][9][10], int column, int row, int number) {
 
std::cout << "The function (remove_number) has been called." << std::endl;
 
 for (int temp = 1; temp < 10; temp = temp + 1) {
   
  if (temp != number && number != 0) {
   
   puzzle[column][row][temp] = 0;
   
  } else {
    
   puzzle[column][row][temp] = 1;
  
  }
   
 }
 
std::cout << "The function (remove_number) has concluded." << std::endl;
 
}

//Replace the cell's number with NUMBER, then removes all other 
//possible numbers for that cell.
//Only called at puzzle creation, and when a number is SURE to be the only possible answer.
void replace_number(int puzzle[9][9][10], int column, int row, int number) {
  
std::cout << "The function (replace_number) has been called." << std::endl;
 
 puzzle[column][row][0] = number;
 remove_number(puzzle, column, row, number);
 
std::cout << "The function (replace_number) has concluded." << std::endl;
 
}

//Check the column of the location passed in to ensure that the row is correct.
void check_column(int puzzle[9][9][10], int column, int row) {
 
std::cout << "The function (check_column) has been called." << std::endl;
 
std::cout << "The function (check_column) has concluded." << std::endl;
 
}

//Check the row of the location passed in to ensure that the row is correct.
void check_row(int puzzle[9][9][10], int column, int row) {

std::cout << "The function (check_row) has been called." << std::endl;

std::cout << "The function (check_row) has concluded." << std::endl;
 
}

//Check the box of the location passed in to ensure that the box is correct.
void check_box(int puzzle[9][9][10], int column, int row) {
 
std::cout << "The function (check_box) has been called." << std::endl;

std::cout << "The function (check_box) has concluded." << std::endl;
 
}

//Scan through the entire puzzle, making sure that all cells are correct.
void check_puzzle(int puzzle[9][9][10]) {
 
std::cout << "The function (check_puzzle) has been called." << std::endl;

std::cout << "The function (check_puzzle) has concluded." << std::endl;
 
}

//Print PUZZLE to terminal.
void print_puzzle(int puzzle[9][9][10]) {
 
std::cout << std::endl << "The function (print_puzzle) has been called." << std::endl;
 
 int row = 0;
 int column = 0;
 
 while (row < 9) {
  
  while (column < 9) {
   
   std::cout << puzzle[column][row][0];
   column = column + 1;
   
  }
  
  std::cout << std::endl;
  row = row + 1;
  column = 0;
 
 }
  
std::cout << "The function (print_puzzle) has concluded." << std::endl;
 
}

//Changes the puzzle PASTETO to match exactly the puzzle COPYFROM.
void copy_puzzle(int copyfrom[9][9][10], int pasteto[9][9][10]) {
 
std::cout << "The function (copy_puzzle) has been called." << std::endl;
 
 for (int column = 0; column < 9; column = column + 1) {
  
  for (int row = 0; row < 9; row = row + 1) {
   
   for (int number = 0; number < 10; number = number + 1) {
    
    pasteto[column][row][number] = copyfrom[column][row][number];
   
   }
    
  }
  
 } 
 
std::cout << "The function (copy_puzzle) has concluded." << std::endl;
 
}

//Turns the output puzzle into a copy of the original puzzle.
void copy_original_to_output() {
 
std::cout << "The function (copy_original_to_output) has been called." << std::endl;

 copy_puzzle(original_puzzle, output_puzzle);
 
std::cout << "The function (copy_original_to_output) has concluded." << std::endl;
 
}

//Turns the test puzzle into a copy of the output puzzle.
void copy_output_to_test() {

std::cout << "The function (copy_output_to_test) has been called." << std::endl;

 copy_puzzle(output_puzzle, test_puzzle);
 
std::cout << "The function (copy_output_to_test) has concluded." << std::endl;
 
}

//Turns the output puzzle into a copy of the test puzzle.
void copy_test_to_output() {
 
std::cout << "The function (copy_test_to_output) has been called." << std::endl;
 
 copy_puzzle(test_puzzle, output_puzzle);
 
std::cout << "The function (copy_test_to_output) has concluded." << std::endl;
 
}

//Adds numbers to the original puzzle, which shouldn't be altered after this in any way.
void create_original_puzzle(std::ifstream &input_file) {
 
std::cout << "The function (create_original_puzzle) has been called." << std::endl;  
 
 input_file.clear();
 input_file.seekg(0, input_file.beg);
 
 char temp;
 int column = 0;
 int row = 0;  
  while (input_file.get(temp)) {
   
    switch (temp) {
      
     case '0':
//std::cout << "Case 0." << std::endl;
      replace_number(original_puzzle, column, row, 0);
      column = column + 1;
      break;
      
     case '1':
//std::cout << "Case 1." << std::endl;
      replace_number(original_puzzle, column, row, 1);
      column = column + 1;  
      break;
       
     case '2':
//std::cout << "Case 2." << std::endl;
      replace_number(original_puzzle, column, row, 2);
      column = column + 1;
      break;

     case '3':
//std::cout << "Case 3." << std::endl;
      replace_number(original_puzzle, column, row, 3);
      column = column + 1;
      break;
      
     case '4':
//std::cout << "Case 4." << std::endl;
      replace_number(original_puzzle, column, row, 4);
      column = column + 1;
      break;
      
     case '5':
//std::cout << "Case 5." << std::endl;
      replace_number(original_puzzle, column, row, 5);
      column = column + 1;
      break;
      
     case '6':
//std::cout << "Case 6." << std::endl;
      replace_number(original_puzzle, column, row, 6);
      column = column + 1;
      break;
      
     case '7':
//std::cout << "Case 7." << std::endl;
      replace_number(original_puzzle, column, row, 7);
      column = column + 1;
      break;
      
     case '8':
//std::cout << "Case 8." << std::endl;
      replace_number(original_puzzle, column, row, 8);
      column = column + 1;
      break;
      
     case '9':
//std::cout << "Case 9." << std::endl;
      replace_number(original_puzzle, column, row, 9);
      column = column + 1;
      break;
      
     case '\n':
//std::cout << "Case endline." << std::endl;
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
  
 copy_original_to_output();
 copy_output_to_test();
 
}


//This function will take in INPUT_FILE, printing its contents to the terminal one char at a time.
void print_input_file(std::ifstream &input_file) {
 
std::cout << std::endl << "The function (print_input_file) has been called." << std::endl;  
  
 input_file.clear();
 input_file.seekg(0, input_file.beg);
 
  char temp;
  
  while (input_file.get(temp)) {
   
    std::cout << temp;
    
  }
  
std::cout << std::endl << "The function (print_input_file) has concluded." << std::endl;
  
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
        << "The expected formatting can be found within README" << std::endl << std::endl
        << "Is this file ready for execution? (Y / N):";
      std::cin >> answer;
      if (answer == 'Y') {
       
       create_original_puzzle(input_file);
print_puzzle(original_puzzle);
//       check_puzzle(output_puzzle);
print_puzzle(output_puzzle);
        
      } else {
       
        std::cout << "Please run this command with a different file." << std::endl
          << "Program closing..." << std::endl;
        
      }
      
    }
    
  }

}
