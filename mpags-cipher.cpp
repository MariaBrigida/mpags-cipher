/*
Program for encryption and decryption of an input string shifting each character to the right by a user-specified number (in encrypting mode) or to the left (in decrypting mode).

Standard usage:
./mpags-cipher -i inputfilename -o outputfilename -e encryptionVariable(1=encrypt,0=decrypt) -s shift
All characters in the string are converted to uppercase and numbers are written in letters before encryption/decryption.


If no input and output file names are specified, the program asks for user input at runtime, and prints output string on screen.
Default: encryptionVariable = 1 (encrypt), shift = 0.

*/

#include <iostream>
#include <string>
#include "transformChar.hpp"
//#include "substituteChar.hpp"
#include "processCommandLine.hpp"
#include "CaesarCipher.hpp"
#include <fstream>

int main(const int argc, const char*argv[])
{ 
  //check that main function correctly reads all input arguments/////////////
  //std::string infileName = "";
  //std::string outfileName = "";
  //unsigned int shift{0};
  //bool encvar{true};
  
  CommandLineInfo info;
  bool commandlineFlag = processCommandLine(argc, argv, info);
  CaesarCipher myCipher(info.shift,info.cipherMode);
  //myCipher.setCipherMode(info.cipherMode);

  if(commandlineFlag == false)
  {
    std::cout << "INVALID ARGUMENTS!" << "\n";
    return 1;
  }

  if (info.helpFlag == true) return 0;
  myCipher.setCipherMode(info.cipherMode);
  std::cout << "input file name = " << info.inFileName << "\n";
  std::cout << "output file name = " << info.outFileName << "\n";

 ////////////////////////////////////////////////
 
 //Declare and initialize cipher variables and encrypt/decrypt input file/string
  std::string out{""};    
  char in_char{'x'};

  if(info.cipherMode==CipherMode::decrypt) std::cout << "Cipher mode: decrypt\n";
  else if(info.cipherMode==CipherMode::encrypt) std::cout << "Cipher mode: encrypt\n";
  if(info.shift==0) std::cout << "Shift = 0\n";
  
  //loop on input string characters if input file name is not provided
  if(info.inFileName==""){
  std::cout << "insert a string\n";
    while (std::cin >> in_char){
      std::cout << "in_char = " << in_char << "\n";
      //converts the input character is the right format for the cipher
      out += transformChar(in_char);
      std::cout << " ";
    }
  }
  //read from file if input file name is provided
  else {
    std::ifstream in_file(info.inFileName);
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
  //Moving CaesarCipher to a class
  /*
  for (unsigned int i = 0; i < out.size(); i++){
    //Performs the encryption/decryption according to parameters specified by user
    out[i] = substituteChar(out[i], info.shift, info.encvar);
  }
  */
  out = myCipher.callProcessString(out);
  std::cout << "output string = " << out << "\n";
  //print to output file if output file name is provided
  if (info.outFileName!="") {
    std::ofstream out_file(info.outFileName);
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


