#include <algorithm>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

double calc_grade(double midterm, double final, double median) {
  return 0.2 * midterm + 0.4 * final + 0.4 * median;
}

void test_calc_grade() {
  auto median = calc_grade(.90, .80, .85);
  assert(median == .85);
  cout << "median test passed" << endl;
}
// compute the median of a vector<double>
// calling this function copies the values of the vector
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

void test_median() {
  vector<double> vec1 = {1, 2, 3, 4, 5};
  vector<double> vec2 = {1, 2, 3, 4, 5, 6};

  assert(median(vec1) == 3);
  assert(median(vec2) == (3.0 + 4.0) / 2.0);

  cout << "median test passed" << endl;
}

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

bool test_read_hw() {
  vector<double> hw;
  string input = "1 2 3 4 5";
  istringstream iss(input);
  read_hw(iss, hw);
  assert(hw.size() == 5);
  assert(hw[0] == 1);
  assert(hw[1] == 2);
  assert(hw[2] == 3);
  assert(hw[3] == 4);
  assert(hw[4] == 5);
  cout << "read_hw test passed" << endl;
}
int main() {
  cout << "testing functions" << endl;
  test_median();
  test_calc_grade();
  return 0;
}
