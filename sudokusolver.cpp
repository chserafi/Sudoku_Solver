#include <iostream>
#include <stdio>
#include <string.h>
#include <string>

/*
* This function will take in INPUT_FILE, printing its contents to the terminal one char at a time.
*/
//TODO Make sure this works correctly.
void print_input_file(std::ifstream &input_file) {
 
std::cout << std::endl << "The function (print_input_file) has been called." << std::endl;  
  
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
      std::string answer;
      std::cout << "Please ensure that the previously printed file is the intended file." << std::endl
        << "Also ensure that the printed file is correctly formatted for this program." << std::endl
        << "The expected formatting can be found within README.md" << std::endl << std::endl
        << "Is this file ready for execution? (Yes / No):";
      std::getline(cin, answer);
      if (strcmp(answer, "Yes") == 0 || strcmp(answer, "Y") == 0) {
       
        //Continue executing
        
      } else {
       
        std::cout << "Please run this command with a different file." << std::endl
          << "Program closing..." << std::endl;
        
      }
      
    }
    
  }

}
