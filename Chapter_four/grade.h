#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h header while
#include "student_info.h"
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double> &);
double grade(const student_info &);

#endif // GUARD_grade_h
