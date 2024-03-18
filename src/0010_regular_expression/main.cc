/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::pair;
using std::string;

class Solution {
 public:
  bool isMatch(const string& s, const string& p) {
    map<pair<int, int>, bool> dp;
    return dfs(s, p, dp, 0, 0);
  }

  bool dfs(const string& s, const string& p, map<pair<int, int>, bool>& dp,
          int i, int j) {
    if (i >= s.size() && j >= p.size()) return true;
    if (i >= s.size() && j + 1 < p.size() && p[j + 1] == '*') {
      return dfs(s, p, dp, i, j + 2);
    }
    if (i >= s.size() || j >= p.size()) return false;

    if (dp.find({i, j}) != dp.end()) return dp[{i, j}];

    bool ret = false;
    if (p[j] == '.' || s[i] == p[j]) {
      if (j + 1 < p.size() && p[j + 1] == '*') {
        ret = dfs(s, p, dp, i + 1, j) | dfs(s, p, dp, i, j + 2);
      } else {
        ret = dfs(s, p, dp, i + 1, j + 1);
      }
    } else {
      if (j + 1 < p.size() && p[j + 1] == '*') {
        ret = dfs(s, p, dp, i, j + 2);
      }
    }
    dp[{i, j}] = ret;
    return ret;
  }
};

void print_ret(const bool& ret) {
  if (ret) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}

int main() {
  Solution s;

  bool ret;

  // example 1
  ret = s.isMatch("aa", "a");
  print_ret(ret);

  // example 2
  ret = s.isMatch("aa", "a*");
  print_ret(ret);

  // example 3
  ret = s.isMatch("ab", ".*");
  print_ret(ret);

  return 0;
}
