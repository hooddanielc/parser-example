#include <sstream>
#include <string>
#include <iostream>
#include <cctype>

#include "Tokenizer.h"

int main(int, char **) {
  Tokenizer tokenizer("Hello World");
  std::cout << tokenizer.ss.str() << std::endl;
  const auto tokens = tokenizer.tokenize();

  for(auto token : tokens) {
    std::cout << "> got a token: " << token << std::endl;
  }

  return 0;
}
