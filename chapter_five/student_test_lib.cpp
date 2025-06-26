#include "student_info.h"
#include <vector>
using std::vector;

vector<student_info> test_student_info() {
  vector<student_info> students = {{"Alice", 85, 90, {80, 85, 90}},
                                   {"Bob", 50, 55, {40, 45, 50}},
                                   {"Charlie", 75, 80, {70, 75, 80}},
                                   {"David", 40, 45, {30, 35, 40}}};

  return students;
}
