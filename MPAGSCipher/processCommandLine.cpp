#include <string>
#include <iostream>
#include "processCommandLine.hpp"

//Reads and interprets a list of arguments. Used by main function mpags-cipher.cpp

bool processCommandLine(const int argc, const char* argv[], std::string &inFile, std::string &outFile, bool &encvar, unsigned int &shift)
{
  //Initialization
  inFile="";
  outFile="";
  encvar=1;
  shift=0;

  std::string iarg{""};
  std::string iargnext{""};

  for(int i{0}; i<argc; ++i){
    iarg=argv[i];
    //check if there is a help flag between the arguments
    if(iarg=="--help" || iarg=="-h") 
    {
      std::cout << "Available options:\n-i inputfilename -o outputfilename -e encryptionVariable(1=encrypt,0=decrypt) -s shift\nDefault options: user input/output, encryptionVariable = 1 (encrypt), shift = 0\n";
      ++i;
      continue;
    }
    //prints version if required by one of the arguments
    if(iarg=="--version")
    {
      std::cout << "version 0.0.0.0.1\n";
      ++i;
      continue;
    }
    if(i!=(argc-1)) //if there are at least two arguments left, checks for input and output file names, and sets encryption or decryption mode (encvar)
    {
      iargnext=argv[i+1];
      if(iarg=="-i")
        {
        if(i==argc) return false;
        else {
          inFile = iargnext;
          ++i;
          continue;
         }
        }
      if(iarg=="-o")
        {
        std::cout << "inFile = " << inFile << "\n";
        if(i==argc) return false;
        else {
          outFile = iargnext;
          ++i;
          continue;
         }
        }
      if(iarg=="-e")
        {
        if(i==argc) return false;
        else {
          encvar = std::stoi(iargnext);
          continue;
         }
        }
      if(iarg=="-s")
        {
        if(i==argc) return false;
        else {
          shift = std::stoi(iargnext);
          shift = (unsigned int)shift;
          continue;
         }
        }
      }
  }
return true;
}

