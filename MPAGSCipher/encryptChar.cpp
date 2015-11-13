#include <iostream>
#include <vector>

const std::vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


char substituteChar(char c, unsigned int k)
{
   
  // substituteChar replaces an alphabet character with one shifted by K positions rightwards in the alphabet.
    
    //if the shift k is larger than the number of letters in the alphabet, k is overwritten to 
    if (k > alphabet.size()) k = k % alphabet.size();    
    std::cout << "c = " << c << "\n";
    for (unsigned int i = 0; i < alphabet.size() ; i++){
      std::cout << "i = " << i << "alphabet.at(i) = " << alphabet.at(i) << "\n";
      if(c == alphabet.at(i)) {
         std::cout << "i+k = " << (i+k) << "\n";
         if((i+k) < alphabet.size()) c = alphabet.at(i+k);
         else  c = alphabet.at( (i+k) % alphabet.size());
         break;
      }
    }

   

  return c;
}
