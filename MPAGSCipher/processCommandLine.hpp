#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
//#include "CaesarCipher.hpp"
#include <string>


enum class CipherMode {
  encrypt,
  decrypt
};


struct CommandLineInfo {
  std::string inFileName{""};
  std::string outFileName{""};
  CipherMode cipherMode{CipherMode::encrypt};
  //CipherMode cipherMode;
  unsigned int shift{0};
  bool helpFlag=false;
};

bool processCommandLine(const int argc, const char* argv[], CommandLineInfo &info);

#endif
