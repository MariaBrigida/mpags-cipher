//! Main implementation of the mpags-cipher program

// This is one of the two valid signatures for main()
//int main(int /*argc*/, char* /*argv*/[]) {
  // No requirement to return from main, but we do so for clarity and
  // consistency with other functions.
// return 0;
//}

//This program converts makes an input string ready to be encrypted

#include <iostream>
#include <string>
#include "transformChar.hpp"

std::string transformChar(char c);

int main(int argc, char*argv[])
{
  std::string out{""};    
  char in_char{'x'};
  std::cout << "insert a string" << "\n";
  
  //loop on input string characters
  while (std::cin >> in_char){

    std::cout << "in_char = " << in_char << "\n";
    out = transformChar(in_char);
    std::cout << " " << "\n";
  }
  std::cout << "output string = " << out << "\n";

  //check that main function correctly reads all input arguments
  std::string iarg{""};
  
  for(int i{0}; i<argc; ++i){
    std::cout << "argument n. " << i << " = " << argv[i] << "\n";
    iarg=argv[i];
    //check if there is a help flag between the arguments
    if(iarg=="--help" || iarg=="-h") std::cout << "Help?" << "\n";
	if(iarg=="--version") std::cout << "version 0.0.0.0.1\n";
	if(iarg =="-o") {std::cout << "output file name = " << argv[i+1] << "\n";
    ++i;
    continue;
	}
        if(iarg=="-i") {std::cout << "input file name = " << argv[i+1] << "\n";
    ++i;
    continue;
	}
  }
  
  return 0;
}

