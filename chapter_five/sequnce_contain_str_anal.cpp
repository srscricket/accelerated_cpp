// library include
#include <vector>

// local include
#include "grade.h"
#include "student_info.h"

// namespace declaraitons
using std::vector;

// determine if student fauiled
bool fgrade(const student_info &s) { return grade(s) < 60; }

// separete students into two groups: passing and failing
vector<student_info> extract_fails(vector<student_info> &students) {
  vector<student_info> pass, fail;
  vector<student_info>::iterator iter = students.begin();

  while (iter != students.end()) {
    if (fgrade(*iter)) {
      fail.push_back(*iter);
      iter = students.erase(iter); // remove from original list
    } else {
      ++iter; // move to next student
    }
  }

  return fail; // return the failing students
}
