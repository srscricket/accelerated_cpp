#include "grade.h"
#include "median.h"
#include "student_info.h"
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::vector;

// code for grade fuction from 4.1/52
// compute a student's overall grade from midterm and final exam grades and
// homework grade
double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// code for overloaded grade from 4.1.2/54
// compute a student's overall grade from midterm and final exam grades
//  and vector of homework grades
//  this function does not copy its arguments, becasue median does so for using
double grade(double midterm, double final, const std::vector<double> &hw) {
  if (hw.size() == 0) {
    throw domain_error("no homework grades");
  }
  return grade(midterm, final, median(hw));
}

double grade(const student_info &s) {
  return grade(s.midterm, s.final, s.homework);
}
