#include <ifstream>
#include <stdio>

struct puzzle_elem {

  int number;
  int set[10];
  int possible;

};

//TODO Make sure this works correctly.
int get_number(puzzle_elem element) {
  return element.number;
}

//TODO Make sure this works correctly.
void set_number (puzzle_elem element, int new_number) {
  element.number = new_number;
}

//TODO Make sure this works correctly.
int get_set(puzzle_elem element, int position) {
  return element.set[position];
}

//TODO Make sure this works correctly.
void set_set(puzzle_elem element, int position, int new_set) {
  element.set[position] = new_set;
}

//TODO Make sure this works correctly.
int get_possible(puzzle_elem element) {
  return element.possible;
}

//TODO Make sure this works correctly.
void set_possible(puzzle_elem element, int new_possible) {
  element.possible = new_possible;
}

void print_input_file(std::ifstream &input_file) {
 
std::cout << std::endl << "The function (print_input_file) has been called." << std::endl;  
  
  char temp;
  
  while (input_file.get(temp)) {
   
    std::cout << temp;
    
  }
  
std::cout << "The function (print_input_file) has concluded." << std::endl;
  
}

//TODO Read arguements.
//TODO Ensure the right syntax is used.
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
      
    }
    
  }

}
