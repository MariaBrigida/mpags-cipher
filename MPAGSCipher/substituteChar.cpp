#include <iostream>
#include <vector>

const std::vector<char> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


char substituteChar(char c, unsigned int k, bool b /*b=1:encrypt, b=0:decrypt*/)
{
  // Function for encryption/decription according to a constant rule (Caesar cipher)
  // replaces an input alphabet character c with one shifted by k positions left (if b = 0) or right (if b = 1) in the alphabet.
    
    //if the shift k is larger than the number of letters in the alphabet, k is overwritten to 
    if (k > alphabet.size()) k = k % alphabet.size();    
    int ii{0}; //new character position index

    //loop over the alphabet to find input character position
    for (unsigned int i = 0; i < alphabet.size() ; i++){
      if (b) ii = (i + k);
      else ii = (i - k);
      if(c == alphabet.at(i)) {
         //shift character (wrap around if new character position is out of alphabet range) 
         if(ii < 0) c = alphabet.at( ii + alphabet.size());     
         else if((unsigned int)ii > alphabet.size()) c = alphabet.at( ii - alphabet.size());
         else c = alphabet.at(ii);
         break;
      }

    }

  return c;
}
