/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;

class Solution {
 public:
  int longestCommonSubsequence(const string& text1, const string& text2) {
    int m = text1.size();
    int n = text2.size();

    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
        dp[i][j] = 0;
      }
    }

    for (int i = m - 1; i >= 0 ; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (text1[i] == text2[j]) {
          dp[i][j] = 1 + dp[i + 1][j + 1];
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
      }
    }
    return dp[0][0];
  }

  int longestCommonSubsequence2(const string& text1, const string& text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return check(dp, text1, text2, m, n, 0, 0);
  }

  int check(vector<vector<int>>& dp, const string& t1, const string& t2,
            const int& m, const int& n, int i, int j) {
    if (i >= m || j >=n ) return 0;
    if (dp[i][j] >= 0) return dp[i][j];
    int ret = 0;
    if (t1[i] == t2[j]) {
        ret = 1 + check(dp, t1, t2, m, n, i + 1, j + 1);
    } else {
        ret = max(check(dp, t1, t2, m, n, i + 1, j),
                  check(dp, t1, t2, m, n, i, j + 1));
    }
    dp[i][j] = ret;
    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;

  // example 1
  ret = s.longestCommonSubsequence("abcde", "ace");
  print_ret(ret);

  // example 2
  ret = s.longestCommonSubsequence("abc", "abc");
  print_ret(ret);

  // example 3
  ret = s.longestCommonSubsequence("abc", "def");
  print_ret(ret);

  return 0;
}
