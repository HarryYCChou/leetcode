/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::max;
using std::min;

class Solution {
 public:
  int characterReplacement(const string &s, const int& k) {
    int i = 0, j = 0;
    vector<int> count(26);
    int ret = 0;
    int m = 0;

    while (j < s.size()) {
      count[s[j] - 'A'] += 1;
      m = max(m, count[s[j] - 'A']);
      if ((j - i + 1 - m) > k) {
        // failed
        count[s[i++] - 'A']--;
      }
      ret = max(ret, j - i + 1);
      j++;
    }

    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  string str;
  int ret;

  // example 1
  str = "ABAB";
  ret = s.characterReplacement(str, 2);
  print_ret(ret);

  // example 2
  str = "AABABBA";
  ret = s.characterReplacement(str, 1);
  print_ret(ret);

  // example 3
  str = "ABBB";
  ret = s.characterReplacement(str, 2);
  print_ret(ret);

  return 0;
}
