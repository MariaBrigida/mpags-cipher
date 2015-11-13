#include "CaesarCipher.hpp"
#include <iostream>
#include <vector>
#include "processCommandLine.hpp"

CaesarCipher::CaesarCipher(const int &cipherKey, CipherMode cipherMode): key_{0}, cipherMode_{CipherMode::encrypt} {
key_ = cipherKey;
cipherMode_ = cipherMode;
}

void CaesarCipher::setCipherMode(CipherMode cipherMode){cipherMode_ = cipherMode;}

std::string CaesarCipher::processString(std::string inputString){

  for (unsigned int i = 0; i < inputString.size(); i++){
    //Performs the encryption/decryption according to parameters specified by user

    if ((unsigned int)key_ > alphabet.size()) key_ = key_ % alphabet.size();    
    int ii{0}; //new character position index

    //loop over the alphabet to find input character position
    for (unsigned int j = 0; j < alphabet.size() ; j++){
      if (cipherMode_==CipherMode::encrypt) ii = (j + key_);
      else ii = (j - key_); 
      if(  inputString[i] == alphabet.at(j)) {
         //shift character (wrap around if new character position is out of alphabet range) 
         if(ii < 0)   inputString[i] = alphabet.at( ii + alphabet.size());     
         else if((unsigned int)ii > alphabet.size())   inputString[i] = alphabet.at( ii - alphabet.size());
         else   inputString[i] = alphabet.at(ii);
         break;
      }

    }

  }
  return inputString;
}

  std::string CaesarCipher::callProcessString(std::string inputstring){

  return processString(inputstring);  

}
