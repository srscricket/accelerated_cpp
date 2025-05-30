// inbclude directives and using declarations for libary functions
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// code for median function from 4.1.1/53
// compute the median of a
// vector<double>
//  calling this function copies the values of the vector
//

// struct for student
typedef struct student_info {
  string name;
  double midterm, final;
  vector<double> homework;
};

double median(std::vector<double> vec) {
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = vec.size();
  if (size == 0) {
    throw std::domain_error("median of an empty vector");
  }
  std::sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (vec[mid - 1] + vec[mid]) / 2 : vec[mid];
}

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
    throw std::domain_error("no homework grades");
  }
  return grade(midterm, final, median(hw));
}

// code for read_hw function from 4.1.3/57
// read homework grades from an input stream
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

istream &read(istream &in, student_info &s) {
  // read the student's name and midterm and final exam grades
  in >> s.name >> s.midterm >> s.final;
  read_hw(in, s.homework); // read and store hw grades
  return in;
}

int main() {
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
  }
  return 0;
}
