// chapter 4 exercises

#include <algorithm>
#include <iomanip> // for std::setw
#include <iostream>
#include <vector>

using namespace std;

// write a function that reads words from an input stream and returns a vector
// of those words use the above functiopn that counts the number of words in a
// input and to count the number of occurances of each words

struct uniqueWords {
  string word;
  int count;

  bool operator==(const uniqueWords &other) const { return word == other.word; }
  bool operator==(const string &other_word) const { return word == other_word; }
};

vector<string> read_words(istream &in) {
  vector<string> words;
  string word;

  while (in >> word) {
    words.push_back(word);
  }

  return words;
}

int main() {
  // write a program that calculates the squares of int values up to 100
  // 2 columns one of orignal number and one of the square of that number
  // use setw to align the columns
  //
  vector<int> number, square;
  vector<string> words;
  vector<uniqueWords> unique_words;
  int word_count = 0;

  for (int i = 1; i <= 10; ++i) {
    number.push_back(i);
    square.push_back(i * i);
  }

  for (size_t i = 0; i < number.size(); ++i) {
    cout << std::setw(5) << number[i] << " " << std::setw(10) << square[i]
         << endl;
  }
  // write a program that reads words from an input stream and counts the
  // number of
  cout << "Enter words (end with EOF):" << endl;
  words = read_words(cin);
  for (const auto &word : words) {
    ++word_count;
    if (find(unique_words.begin(), unique_words.end(), word) ==
        unique_words.end()) {
      uniqueWords uw;
      uw.word = word;
      uw.count = 1;
      unique_words.push_back(uw);
    } else {
      for (auto &uw : unique_words) {
        if (uw.word == word) {
          ++uw.count;
          break;
        }
      }
    }
  }
  cout << "Total words: " << word_count << endl;
  cout << "There are " << unique_words.size() << " unique words:" << endl;
  for (const auto &uw : unique_words) {
    // use setw to align the numbers
    cout << left << setw(15) << uw.word << ": " << uw.count << endl;
  }

  return 0;
}
