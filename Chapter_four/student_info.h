#ifndef GUARD_Student_info
#define GUARD_Student_info

// student_info.h header file
#include <string>
#include <vector>

struct student_info {
  std::string name;
  double midterm, final;
  std::vector<double> homework;
};

bool compare(const student_info &, const student_info &);
std::istream &read(std::istream &, student_info &);
std::istream &read_hw(std::istream &, std::vector<double> &);

#endif // GUARD_Student_info
