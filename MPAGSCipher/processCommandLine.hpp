#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#include <string>


enum class CipherMode {
  encrypt,
  decrypt
};


struct CommandLineInfo {
  std::string cipherName{""};
  std::string inFileName{""};
  std::string outFileName{""};
  CipherMode cipherMode{CipherMode::encrypt};
  //CipherMode cipherMode;
  std::string shift{""};
  bool helpFlag=false;
};

bool processCommandLine(const int argc, const char* argv[], CommandLineInfo &info);

#endif
