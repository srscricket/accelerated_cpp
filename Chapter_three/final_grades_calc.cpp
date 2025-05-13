#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main() {
  // ask for students name
  cout << "Enter the student's name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // ask for midterm and final grades
  cout << "Enter the midterm and final grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // ask for homework grades
  cout << "Enter all homework grades, followed by end-of-file: ";
  // the number and sum for the homework grades read so for
  int count = 0;
  double sum = 0;

  // variable in which to read
  double x;
  vector<double> homework;

  // invariant:
  // we have read count grades so far, and sum is the sum of those grades
  while (cin >> x) {
    homework.push_back(x);
  }
  // declare the vector size type and save the size of the vector
  typedef vector<double>::size_type vec_sz;
  vec_sz size = homework.size();

  if (size == 0) {
    cout << "You must enter at least one grade." << endl;
    return 1; // indicate failure
  }
  // sort the vector
  sort(homework.begin(), homework.end());

  // find the median
  vec_sz mid = size / 2;
  double median;
  median = size % 2 == 0 ? (homework[mid - 1] + homework[mid]) /
                               2          // even number of elements
                         : homework[mid]; // odd number of elements

  // write the result
  streamsize prec = cout.precision(); // save the original precision
  cout << "The final grade for " << name << " is "
       << setprecision(3) // set the precision to 3
       << 0.2 * midterm + 0.4 * final +
              0.4 * median   // calculate the final grade
       << setprecision(prec) // reset the precision to the original
       << endl;              // end the line

  return 0;
}
