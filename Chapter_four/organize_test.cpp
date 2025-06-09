// inbclude directives and using declarations for libary functions
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// include directives for the functions in this program
#include "grade.h"
#include "student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

// code for median function from 4.1.1/53
// compute the median of a
// vector<double>
//  calling this function copies the values of the vector
//

int main() {
  vector<student_info> students;
  student_info record;
  string::size_type maxlen = 0;

  // read abd store all the rocrds, and find the lenth of the longest name
  while (read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  // alphabetize the record
  sort(students.begin(), students.end(), compare);

  for (vector<student_info>::size_type i = 0; i < students.size(); ++i) {
    // write the name, padded on the right to maxlen + 1 characters
    cout << students[i].name
         << string(maxlen + 1 - students[i].name.size(), ' ');

    // compute and write the final grade
    try {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec) << endl;

    } catch (domain_error e) {
      cout << e.what();
    }
  }
  return 0;
}

/*
// ask for and read the student's name
cout << "Please enter your name: ";
string name;
cin >> name;
cout << "Hello, " << name << "!" << endl;

// ask for and read the midterm and final exam grades
cout << "Please enter your midterm and final exam grades: ";
double midterm, final;
cin >> midterm >> final;

// ask for homnwork grades
cout << "Enter all your homework grades, followed by end-of-file: ";

vector<double> homework;

// read the homework grades
read_hw(cin, homework);

// compute and generate the final grades, if possible
try {
  double final_grade = grade(midterm, final, homework);
  cout << "Your final grade is " << final_grade << endl;
} catch (domain_error &e) {
  cout << endl << e.what() << endl;
  return 1;
  */
