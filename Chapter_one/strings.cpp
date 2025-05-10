// Copyright (c) 2025 Author. All Rights Reserved.
// ask for a person's name, and greet person

#include <iostream>
#include <string>

int main() {
  std::cout << "Please enter your name: ";
  std::string name;
  std::cin >> name;

  // build string
  const std::string greeting = "Hello, " + name + "!";

  // build the other lines
  const std::string spaces(greeting.size(), ' ');
  const std::string second = "* " + spaces + " *";

  // build yet more lines
  const std::string first(second.size(), '*');

  // write it
  std::cout << first << '\n'
            << second << '\n'
            << "* " << greeting << " *\n"
            << second << '\n'
            << first << '\n';
  return 0;
}
