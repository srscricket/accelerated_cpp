#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  int pad = 1;
  cout << "Please enter the number of padding rows: ";
  cin >> pad;
  int rows = pad * 2 + 3;
  // ask the person's name
  cout << "Please enter your first name: ";
  // read the name
  string name;
  cin >> name;
  // build message
  string greeting = "Hello, " + name + "!";
  const string::size_type cols = greeting.size() + pad * 2 + 2;
  cout << endl;
  for (int r = 0; r != rows; ++r) {
    string::size_type c = 0;
    while (c != cols) {
      if (r == pad + 1 && c == pad + 1) {
        cout << greeting;
        c += greeting.size();
      } else {
        // border check
        if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
          cout << "*";
        } else {
          cout << " ";
        }
        ++c;
      }
    }
    cout << endl;
  }
  return 0;
}

/*  if (r == 0 || r == rows - 1) {
        if (c == 0 || c == cols - 1) {
          cout << "+";
        } else {
          cout << "-";
        }
      } else {
        if (c == 0 || c == cols - 1) {
          cout << "|";
        } else if (r == pad + 1 && c == pad + 1) {
          cout << greeting;
        } else {
          cout << " ";
        }
      }
      //AI suggestion that might look cool.
      */

/* copying here for reference book is moving to for statment
  while (r != rows) {
    string::size_type c = 0;
    while (c != cols) {
      if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
        cout << "*";
      } else {
        if (r == pad + 1 && c == pad + 1) {
          cout << greeting;
          c += greeting.size();
        } else {
          co ut << " ";
        }
      }
      ++c;
    }
    ++r;
  }
*/
