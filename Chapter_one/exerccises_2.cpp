#include <iostream>
#include <string>

int main() {
  std::cout << "Please enter your name: ";
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name << "!" << std::endl
            << "And what is your name? ";
  std::cin >> name;
  std::cout << "hello" << name << "; nice to meet you too!" << std::endl;
  return 0;
}
