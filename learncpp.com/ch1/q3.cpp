#include <iostream>
/*
  Write a program that asks the user to enter a number, and then enter a second number. The program should tell the user what the result of adding and subtracting the two numbers is.
  The output of the program should match the following (assuming inputs of 6 and 4):
    Enter an integer: 6
    Enter another integer: 4
    6 + 4 is 10.
    6 - 4 is 2.
  Hint: To print a period and a newline, use ".\n", not '.\n'.
*/

int main() {
  int num1 {};
  int num2 {};

  std::cout << "Enter a integer: ";
  std::cin >> num1;

  std::cout << "Enter another integer: ";
  std::cin >> num2;

  std::cout << num1 << " + " << num2 << " is " << num1 + num2 << ".\n";
  std::cout << num1 << " - " << num2 << " is " << num1 - num2 << ".\n";
  
  return 0;
}
