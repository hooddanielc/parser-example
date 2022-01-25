#pragma once

#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

class Tokenizer {

public:

  std::stringstream ss;

  Tokenizer(const std::string &str);

  Tokenizer() = default;

  void clear();

  void setString(const std::string &str);

  std::vector<std::string> tokenize();

};
