/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_map;
using std::min;

class Solution {
 public:
  int minDistance(const string& word1, const string& word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

    for (int i = word2.size(); i >= 0; i--) {
      dp[word1.size()][i] = word2.size() - i;
    }
    for (int i = word1.size(); i >= 0; i--) {
      dp[i][word2.size()] = word1.size() - i;
    }

    for (int i = word1.size() - 1; i >= 0; i--) {
      for (int j = word2.size() - 1; j >= 0; j--) {
        // replace or without replace
        int next = dp[i + 1][j + 1];
        // if character not equal, use replacing method
        if (word1[i] != word2[j]) next += 1;
        dp[i][j] = min(min(dp[i][j + 1] + 1, dp[i + 1][j] + 1), next);
      }
    }

    return dp[0][0];
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;

  // example 1
  ret = s.minDistance("horse", "ros");
  print_ret(ret);

  // example 2
  ret = s.minDistance("intention", "execution");
  print_ret(ret);

  // example 3

  return 0;
}
