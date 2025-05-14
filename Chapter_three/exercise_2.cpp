#include <algorithm>
#include <iostream>
#include <vector>

int rand_gen() { return std::rand() % 100; }

int main(int argc, char *argv[]) {

  // generate random numbers
  // Create a vector of random numbers
  // const int RAND_MAX = 100;
  std::vector<int> numbers(100);
  std::generate(numbers.begin(), numbers.end(), rand_gen);

  // Sort the vector
  std::sort(numbers.begin(), numbers.end());

  // Print the sorted vector
  for (const auto &num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  // find and print the quartiles
  auto q1 = numbers.begin() + numbers.size() / 4;
  auto q2 = numbers.begin() + numbers.size() / 2;
  auto q3 = numbers.begin() + 3 * numbers.size() / 4;
  auto q4 = numbers.end();
  std::cout << "Q4: " << *q1 << std::endl;
  std::cout << "Q3: " << *q2 << std::endl;
  std::cout << "Q2: " << *q3 << std::endl;
  std::cout << "Q1: " << *q4 << std::endl;
  return 0;
}
