// Copyright (c) 2025 Author. All Rights Reserved.
// ask for a person's name, and greet person

#include <iostream>
#include <string>

int main() {
  std::string name;
  std::cout << "Please enter your name: ";
  std::getline(std::cin, name);
  std::cout << "Hello, " << name << "!" << std::endl;
  return 0;
}
