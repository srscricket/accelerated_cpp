// library include
#include <iostream>
#include <vector>

// local include
#include "grade.h"
#include "student_info.h"
#include "student_test_lib.h"

// namespace declaraitons
using std::vector;

// determine if student fauiled
bool fgrade(const student_info &s) { return grade(s) < 60; }

// separete students into
//    two groups : passing and failing
//  function returns passing students and modifies the
//  original list to contain only failing students
//  commenting out the old function, book has nwe function
vector<student_info> extract_fails(vector<student_info> &students) {
  vector<student_info> pass, fail;
  vector<student_info>::iterator iter = students.begin();

  while (iter != students.end()) {
    std::cout << "Processing student: " << iter->name << std::endl;
    if (fgrade(*iter)) {
      fail.push_back(*iter);
      std::cout << "Failing student: " << iter->name << std::endl;
      // iter = students.erase(iter); // remove from original list
    } else {
      pass.push_back(*iter); // add to passing list
      std::cout << "Passing student: " << iter->name << std::endl;
    }
    ++iter; // move to next student
  }
  students = pass; // modify original list to contain only passing students
  return fail;     // return the failing students
}

/*
// newfunction
vector<student_info> extract_fails(vector<student_info> &students) {
  vector<student_info> fails;
  vector<student_info>::size_type i = 0;

  // invariant: elements [0,i) of students are passing]
  while (i != students.size()) {
    if (fgrade(students[i])) {
      fails.push_back(students[i]);         // add to failing list
      students.erase(students.begin() + i); // remove from original list
    } else {
      ++i; // move to next student
    }
  }
  return fails; // return the failing students
}
*/
// test extract_fails function
bool test_extract_fails() {
  // need student_info list with midterm, final and an array of homework
  // grades
  vector<student_info> students = test_student_info();

  vector<student_info> fails = extract_fails(students);

  // Check if the original list contains only passing students
  if (students.size() != 2 || students[0].name != "Alice" ||
      students[1].name != "Charlie") {
    return false;
  }

  // Check if the failing students are correctly extracted
  if (fails.size() != 2 || fails[0].name != "Bob" || fails[1].name != "David") {
    return false;
  }

  return true;
}

int main() {
  // Run the test for extract_fails
  // test fails skips charlie

  if (test_extract_fails()) {
    std::cout << "Test passed!" << std::endl;
  } else {
    std::cout << "Test failed!" << std::endl;
  }

  return 0;
}
