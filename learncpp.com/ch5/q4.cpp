#include <iostream>
#include <stdio.h>
#include <string>
// Write a program that asks for the name and age of two people, then prints
// which person is older.
//  Here is the sample output from one run of the program:
//  Enter the name of person #1: John Bacon
//  Enter the age of John Bacon: 37
//  Enter the name of person #2: David Jenkins
//  Enter the age of David Jenkins: 44
//  David Jenkins (age 44) is older than John Bacon (age 37).
//
int main() {
  std::string name1{};
  printf("Enter the name of person #1: ");
  std::getline(std::cin, name1);

  std::string age1{};
  printf("Enter the age of %s: ", name1.c_str());
  std::getline(std::cin, age1);

  std::string name2{};
  printf("Enter the name of person #2: ");
  std::getline(std::cin, name2);

  std::string age2{};
  printf("Enter the age of %s: ", name2.c_str());
  std::getline(std::cin, age2);

  if (std::stoi(age1) >= std::stoi(age2)) {
    printf("%s (age %s) is older than %s (age %s).", name1.c_str(),
           age1.c_str(), name2.c_str(), age2.c_str());
  } else {
    printf("%s (age %s) is older than %s (age %s).", name2.c_str(),
           age2.c_str(), name1.c_str(), age1.c_str());
  }

  return 0;
}
