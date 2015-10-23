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
int main()
{
  std::string out{""};
  char in_char{'x'};
  std::cout << "insert a string" << "\n";
  
  //loop on input string characters
  while (std::cin >> in_char){

    std::cout << "in_char = " << in_char << "\n";
    
    //check if it is a letter and convert to uppercase if it is lowercase
    //then add to output string
    if(isalpha(in_char)){
      in_char = toupper(in_char);
      std::cout << "new in_char = " << in_char << "\n";
      out+=in_char;
    }
    //check if it is a number and convert it into a word (string)
    //then add to output string
    else if(isdigit(in_char)){
      switch(in_char){
        case '0':
	  out+="ZERO";
	  break;
        case '1':
	  out+="ONE";
	  break;
        case '2':
	  out+="TWO";
	  break;
        case '3':
	  out+="THREE";
	  break;
        case '4':
	  out+="FOUR";
	  break;
        case '5':
	  out=+"FIVE";
	  break;
        case '6':
	  out=+"SIX";
	  break;
        case '7':
	  out=+"SEVEN";
	  break;
        case '8':
	  out+="EIGHT";
	  break;
        case '9':
	  out=+"NINE";
	  break;
      }
    }
    std::cout << " " << "\n";
  }
  std::cout << "output string = " << out << "\n";
  return 0;
}
