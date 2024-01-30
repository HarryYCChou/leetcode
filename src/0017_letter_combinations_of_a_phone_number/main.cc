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
  vector<vector<char>> dic ={
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
  };

  vector<string> letterCombinations(const string& digits) {
    vector<string> ret;
    for (int i = 0; i < digits.size(); i++) {
      int n = digits[i] - '2';
      if (ret.empty()) {
        for (int j = 0; j < dic[n].size(); j++) {
          ret.push_back(string(1, dic[n][j]));
        }
      } else {
        int len = ret.size();
        vector<string> new_ret;
        for (int j = 0; j < len; j++) {
          for (int k = 0; k < dic[n].size(); k++) {
            new_ret.push_back(ret[j] + dic[n][k]);
          }
        }
        ret = new_ret;
      }
    }
    return ret;
  }
};

void print_ret(const vector<string>& ret) {
  cout << "[";
  for (const auto& s : ret) {
    cout << s << ",";
  }
  cout << "]" << endl;
}

int main() {
  Solution s;

  vector<string> ret;

  // example 1
  ret = s.letterCombinations("23");
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
