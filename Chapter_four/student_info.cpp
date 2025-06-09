// source file for the student_info -related functions
#include "student_info.h"
#include <iostream>

using std::istream;
using std::vector;

bool compare(const student_info &x, const student_info &y) {
  return x.name < y.name;
}

istream &read_hw(istream &in, vector<double> &hw) {
  if (in) {
    hw.clear();
    double x;
    while (in >> x) {
      hw.push_back(x);
    }
    in.clear(); // clear the eof flag
  }
  return in;
}

istream &read(istream &is, student_info &s) {
  // read the student's name and midterm and final exam grades
  is >> s.name >> s.midterm >> s.final;
  read_hw(is, s.homework); // read and store hw grades
  return is;
}
