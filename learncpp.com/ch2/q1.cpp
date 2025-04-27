#include <iostream>

int readNumber() {
  int num {};
  std::cin >> num;

  return num;
}

void writeAnswer(int ans) {
  std::cout << ans;
}

int main() {
  std::cout << "Enter an integer: ";

  int num1 { readNumber() };

  std::cout << "Enter another integer: ";
  int num2 { readNumber() };

  writeAnswer(num1 + num2);

  return 0;
}

