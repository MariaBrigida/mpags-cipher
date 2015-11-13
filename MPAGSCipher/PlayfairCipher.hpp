#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#include <iostream>
#include <vector>
#include "processCommandLine.hpp"

class PlayfairCipher{
 public:
  //PlayfairCipher(const int &cipherKey, CipherMode cipherMode);
  PlayfairCipher(std::string &cipherKey);
  //CaesarCipher();
  //void setCipherMode(CipherMode cipherMode);
  //int getKey() {return key_;};
  void setKey(std::string key);
  void encrypt() {std::cout << "hello!!\n";}
  //std::string callProcessString(std::string inputstring);
 private:
  std::string key_{0};
 // CipherMode cipherMode_;
//  std::string processString(std::string inputstring);
//  const std::vector<char> alphabet {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
};

#endif
