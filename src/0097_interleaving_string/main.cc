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
  bool isInterleave(const string s1, const string s2, const string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));

    return backtrack(dp, 0, 0, s1, s2, s3);
  }

  bool backtrack(vector<vector<bool>>& dp, int i, int j,
                const string& s1, const string& s2, const string& s3) {
    if (dp[i][j] == true) return false;
    if (i + j == s3.size()) return true;

    if (i < s1.size() && s3[i + j] == s1[i]) {
      if (backtrack(dp, i + 1, j, s1, s2, s3)) return true;
    }
    if (j < s2.size() && s3[i + j] == s2[j]) {
      if (backtrack(dp, i, j + 1, s1, s2, s3)) return true;
    }
    dp[i][j] = true;
    return false;
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
  ret = s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
  print_ret(ret);

  // example 2
  ret = s.isInterleave("aabcc", "dbbca", "aadbbbaccc");
  print_ret(ret);

  // example 3
  ret = s.isInterleave("", "", "");
  print_ret(ret);

  return 0;
}
