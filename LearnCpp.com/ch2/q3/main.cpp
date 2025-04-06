#include "io.h"


int main() {

  int num1 { readNumber("Enter a number: ") };
  int num2 { readNumber("Enter another number: ") };

  writeAnswer(num1 + num2);

  return 0;
}
