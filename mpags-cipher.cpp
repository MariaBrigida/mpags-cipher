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


std::string transformChar(char c)
{
   /*
   trasformChar converts a character into a string according to the following rules:
   - c is a lowercase letter: it returns the uppercase version of c;
   - c is an uppercase letter: it returns c;
   - c is a number: it returns the name of c as an uppercase string.
   */

    std::string outstring = "";
    //check if it is a letter and convert to uppercase if it is lowercase
    //then add to output string
    if(isalpha(c)){
      c = toupper(c);
      std::cout << "new in_char = " << c << "\n";
      outstring+=c;
    }
    //check if it is a number and convert it into a word (string)
    //then add to output string
    else if(isdigit(c)){
      switch(c){
        case '0':
	  outstring+="ZERO";
	  break;
        case '1':
	  outstring+="ONE";
	  break;
        case '2':
	  outstring+="TWO";
	  break;
        case '3':
	  outstring+="THREE";
	  break;
        case '4':
	  outstring+="FOUR";
	  break;
        case '5':
	  outstring=+"FIVE";
	  break;
        case '6':
	  outstring=+"SIX";
	  break;
        case '7':
	  outstring=+"SEVEN";
	  break;
        case '8':
	  outstring+="EIGHT";
	  break;
        case '9':
	  outstring=+"NINE";
	  break;
      }
    }
  return outstring;
}

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
