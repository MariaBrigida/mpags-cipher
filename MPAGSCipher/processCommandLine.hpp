#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>

bool processCommandLine(const int argc, const char *argv[], std::string &inFile, std::string &outFile, bool &encvar, unsigned int &shift);

#endif
