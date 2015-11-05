#include <iostream>
#include <string>
#include "transformChar.hpp"
#include "substituteChar.hpp"
#include "processCommandLine.hpp"
#include <fstream>

int main(const int argc, const char*argv[])
{ 
  //check that main function correctly reads all input arguments/////////////
  std::string infileName = "";
  std::string outfileName = "";
  unsigned int shift{0};
  bool encvar{true};

  bool commandlineFlag = processCommandLine(argc, argv, infileName, outfileName, encvar, shift);
  
  if(commandlineFlag == false)
  {
    std::cout << "INVALID ARGUMENTS!" << "\n";
    return 1;
  }
  /*
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
  */
  std::cout << "input file name = " << infileName << "\n";
  std::cout << "output file name = " << outfileName << "\n";

 ////////////////////////////////////////////////
 
 //Set cipher variables and encrypt/decrypt input file/string
  std::string out{""};    
  char in_char{'x'};

  if(encvar==0) std::cout << "Cipher mode: decrypt\n";
  else if(encvar==1) std::cout << "Cipher mode: encrypt\n";
  if(shift==0) std::cout << "Shift = 0\n";
  
  //loop on input string characters
  if(infileName==""){
  std::cout << "insert a string\n";
    while (std::cin >> in_char){
      std::cout << "in_char = " << in_char << "\n";
      out += transformChar(in_char);
      std::cout << " ";
    }
  }
  else {
    std::ifstream in_file(infileName);
    bool ok_to_read = in_file.good();
    if(ok_to_read==false)
    {
      std::cout << "Input file not correctly opened\n";
      return 1;
    }
    std::cout << "reading from file\n";
    //loop on input file characters
    while (in_file.get(in_char)){
      std::cout << "in_char = " << in_char << "\n";
      out += transformChar(in_char);
      std::cout << " ";
    }
  }
  std::cout << "\n";
  std::cout << "input string = " << out << "\n";
  for (unsigned int i = 0; i < out.size(); i++){
    out[i] = substituteChar(out[i], shift, encvar);
  }
  std::cout << "output string = " << out << "\n";
  
  if (outfileName!="") {
    std::ofstream out_file(outfileName);
    bool ok_to_write = out_file.good();
    if(ok_to_write==false)
    {
      std::cout << "Output file not correctly opened" << "\n";
      return 1;
    }

  out_file << out;
  }
 
  return 0;
}


