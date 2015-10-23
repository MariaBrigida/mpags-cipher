//! Main implementation of the mpags-cipher program

// This is one of the two valid signatures for main()
//int main(int /*argc*/, char* /*argv*/[]) {
  // No requirement to return from main, but we do so for clarity and
  // consistency with other functions.
// return 0;
//}

#include <iostream>
#include <string>
int main()
{
  std::cout << "Hello World!\n";
  int a{3};
  std::cout << "a = " << a << "\n";
  a = 5;
  std:: cout << "a = " << a << "\n";
  const double b{2.17};
  std::cout << "b = " << b << "\n";
  std::cout << "a*b = " << a*b << "\n";
  int c{a*b};
  std::cout << "int c = a*b = " << c << "\n";
  auto d{true};
  std::cout << "a/b = " << a/b << "\n";
  int e{4};
  std::cout << "e = " << e << "\n";
  std::cout << "a/e = " << a/e << "\n";
  std::string estr{"milkshake"};
  char s{estr[4]};
  std::cout << "s = " << s << "\n";
  
}
