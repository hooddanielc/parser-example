#include "Tokenizer.h"

Tokenizer::Tokenizer(const std::string &str): ss(str) {}

void Tokenizer::clear() {
  ss.str("");
  ss.clear();
}

void Tokenizer::setString(const std::string &str) {
  ss.str(str);
}

std::vector<std::string> Tokenizer::tokenize() {
  enum state_t {
    start,
    word,
    space
  };

  state_t state(start);

  std::vector<std::string> result;
  std::stringstream current_token;
  bool go = true;

  do {
    const char c = ss.peek();
    // std::cout << "char: " << c << std::endl;

    switch (state) {
      // first iteration
      case start: {
        // std::cout << "# start " << c << std::endl;
        if (ss.eof()) {
          go = false;
          break;
        }
        if (isspace(c)) {
          state = space;
        } else {
          state = word;
        }
        break;
      }
      // currrent parsing after one or more characters
      case word: {
        // std::cout << "# word " << c << std::endl;
        if (ss.eof()) {
          go = false;
          // std::cout << "GOT EOF, " << current_token.str() << std::endl;
          result.push_back(current_token.str());
          current_token.str("");
          current_token.clear();
          ss.get();
          break;
        }
        if (isspace(c)) {
          // std::cout << "Got a space, " << current_token.str() << std::endl;
          result.push_back(current_token.str());
          current_token.str("");
          current_token.clear();
          ss.get();
        } else {
          current_token << c;
          ss.get();
        }
        break;
      }
      // current parsing after one or more spaces
      case space: {
        std::cout << "# space " << c << std::endl;
        if (ss.eof()) {
          go = false;
          break;
        }
        if (isspace(c)) {
          ss.get();
        } else {
          state = word;
          current_token << c;
          ss.get();
        }
        break;
      }
    }
  } while (go == true);

  return result;
}