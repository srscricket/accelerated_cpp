#include <iostream>
#include <string>

int main() {
  {
    std::string s = "a string";
    std::string x = s + ", really";
    std::cout << x << '\n';
    std::cout << x << std::endl;
  }
}
