#include <iostream>
#include <string>

int main() {
  // ask user to enter full name and age
  printf("Enter your full name: ");
  std::string fullName{};
  std::getline(std::cin, fullName);

  printf("Enter your age: ");
  int age{};
  std::cin >> age;

  // tell user sum of age and num of chars in their name
  printf("Your age + length of name is: %d\n",
         age + static_cast<int>(fullName.length()));

  return 0;
}
