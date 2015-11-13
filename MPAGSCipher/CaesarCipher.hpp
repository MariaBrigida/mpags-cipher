#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP
#include <iostream>
#include <vector>
#include "processCommandLine.hpp"

class CaesarCipher{
 public:
  CaesarCipher(const int &cipherKey, CipherMode cipherMode);
  //CaesarCipher();
  void setCipherMode(CipherMode cipherMode);
  int getKey() {return key_;};
  std::string callProcessString(std::string inputstring);
 private:
  int key_{0};
  CipherMode cipherMode_;
  std::string processString(std::string inputstring);
  const std::vector<char> alphabet {'A','B','C','D','E','F','G','H','I',\
'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
};

#endif
