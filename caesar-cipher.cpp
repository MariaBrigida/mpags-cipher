//! Main implementation of the mpags-cipher program

// This is one of the two valid signatures for main()
//int main(int /*argc*/, char* /*argv*/[]) {
  // No requirement to return from main, but we do so for clarity and
  // consistency with other functions.
// return 0;
//}const

//This program makes an input string ready to be encrypted

#include <iostream>
#include <string>
#include "transformChar.hpp"
#include "substituteChar.hpp"
#include "processCommandLine.hpp"
#include <fstream>

int main(const int argc, const char*argv[])
{
  std::string out{""};    
  char in_char{'x'};
  std::cout << "insert a string" << "\n";
  //loop on input string characters
  while (std::cin >> in_char){

    std::cout << "in_char = " << in_char << "\n";
    out = transformChar(in_char);
    std::cout << " ";
  }
  std::cout << "\n";
  std::cout << "input string = " << out << "\n";
  std::cout << "insert cipher shift" << "\n";
  for (int i = 0; i < out.size(); i++){

    out[i] = substituteChar(out[i], shift);
  }

std::cout << "ciphered string = " << out << "\n";




  /*
  //check that main function correctly reads all input arguments
  std::string infileName = "";
  std::string outfileName = "";
  bool commandlineFlag = processCommandLine(argc, argv, infileName, outfileName);
  if(commandlineFlag == false)
  {
    std::cout << "INVALID ARGUMENTS!" << "\n";
    return 1;
  }
  if (infileName == "")
  {
    std::cout << "Input file name absent" << "\n";
    return 1;
  }
  if (outfileName == "")
  {
    std::cout << "Output file name absent" << "\n";
    return 1;
  }
  std::cout << "input file name = " << infileName << "\n";
  std::cout << "output file name = " << outfileName << "\n";

  std::ifstream in_file{infileName};
  std::ofstream out_file{outfileName};
  bool ok_to_write = out_file.good();
  bool ok_to_read = in_file.good();

  if(ok_to_read==false)
  {
    std::cout << "Input file not correctly opened" << "\n";
    return 1;
  }

  if(ok_to_write==false)
  {
    std::cout << "Output file not correctly opened" << "\n";
    return 1;
  }
  out_file << "Test print\n";
  
  return 0;
}
*/

