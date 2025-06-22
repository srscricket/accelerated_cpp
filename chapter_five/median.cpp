// source for the median function
#include "median.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

using std::domain_error;
using std::sort;
using std::vector;

double median(vector<double> vec) {
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = vec.size();
  if (size == 0) {
    throw std::domain_error("median of an empty vector");
  }
  std::sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (vec[mid - 1] + vec[mid]) / 2 : vec[mid];
}
