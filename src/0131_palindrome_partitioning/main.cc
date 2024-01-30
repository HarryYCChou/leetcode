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
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ret;
    vector<string> curr;
    buildSet(s, 0, curr, ret);
    return ret;
  }

 private:
  bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
      if (s[start] != s[end]) return false;
      start++;
      end--;
    }
    return true;
  }

  void buildSet(const string& s, int start,
            vector<string>& curr, vector<vector<string>>& ret) {
    if (start >= s.size()) {
      ret.push_back(curr);
      return;
    }

    int i = start;
    for (int j = i; j < s.size(); j++) {
      if (isPalindrome(s, i, j)) {
        curr.push_back(s.substr(i, j - i + 1));
        buildSet(s, j + 1, curr, ret);
        curr.pop_back();
      }
    }
  }
};

void print_ret(const vector<vector<string>>& ret) {
  cout << "[";
  for (const auto& v : ret) {
    cout << "[";
    for (const auto& c : v) {
      cout << c << ",";
    }
    cout << "],";
  }
  cout << "]" << endl;
}

int main() {
  Solution s;

  vector<vector<string>> ret;

  // example 1
  ret = s.partition("aab");
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
