// program to print the product of numbers in the range [1, 10)

#include <iostream>

using namespace std;

int main() {
  int product = 1;
  for (int i = 1; i < 10; ++i) {
    product *= i;
    cout << "Product of numbers from 1 to " << i << " is: " << product << endl;
    cout << endl;
  }
}
