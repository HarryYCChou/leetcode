/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
 public:
  int countSubstrings(string s) {
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
      check(i, i, ret, s);
      check(i, i + 1, ret, s);
    }
    return ret;
  }

  void check(int start, int end, int& ret, const string& s) {
    while (start >= 0 && end < s.size() && s[start] == s[end]) {
      ret++;
      start--;
      end++;
    }
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;

  // example 1
  ret = s.countSubstrings("abc");
  print_ret(ret);

  // example 2
  ret = s.countSubstrings("aaa");
  print_ret(ret);

  return 0;
}
