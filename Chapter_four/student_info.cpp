// source file for the student_info -related functions
#include "student_info.h"

using std::istream;
using std::vector;

bool compare(const student_info &x, const student_info &y) {
  return x.name < y.name;
}

istream &read(istream &in, student_info &s) {
  // read the student's name and midterm and final exam grades
  in >> s.name >> s.midterm >> s.final;
  read_hw(in, s.homework); // read and store hw grades
  return in;
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
