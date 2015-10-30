#include <string>
#include <iostream>

std::string transformChar(char c)
{
   
  // trasformChar converts a character into a string according to the following rules:
  // - c is a lowercase letter: it returns the uppercase version of c;
  // - c is an uppercase letter: it returns c;
  // - c is a number: it returns the name of c as an uppercase string.
  
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
