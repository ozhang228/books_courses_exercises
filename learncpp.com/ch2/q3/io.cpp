#include "io.h" 

#include <iostream>

int readNumber(const char* message) {
  std::cout << message;
  int num {};
  std::cin >> num;

  return num;
}

void writeAnswer(int ans) {
  std::cout << ans;
}
