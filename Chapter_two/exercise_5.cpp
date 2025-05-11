// program to make triangle, sqaure, rectangle
//
#include <iostream>
#include <string>

using namespace std;

int main() {
  int rows;
  cout << "Please enter the number of rows: ";
  cin >> rows;

  // Loop to print triangle
  cout << "Triangle:" << endl;
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= i; ++j) {
      cout << "*";
    }
    cout << endl;
  }

  // Loop to print square
  cout << "Square:" << endl;
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= rows; ++j) {
      cout << "*";
    }
    cout << endl;
  }

  // Loop to print rectangle
  int cols;
  cout << "Please enter the number of columns: ";
  cin >> cols;

  cout << "Rectangle:" << endl;
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= cols; ++j) {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}
