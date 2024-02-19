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
  bool wordBreak(const string& s, const vector<string>& wordDict) {
    vector<bool> dp(s.size(), true);
    return search(0, s, wordDict, dp);
  }

  bool search(int start, const string& s,
              const vector<string>& wordDict, vector<bool>& dp) {
    if (start == s.size()) return true;

    for (const auto w : wordDict) {
      if (start + w.size() <= s.size()) {
        if (s.substr(start, w.size()) == w) {
          if (dp[start + w.size()] == false) continue;
          if (search(start + w.size(), s, wordDict, dp)) return true;
        }
      }
    }
    dp[start] = false;
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

  vector<string> wordDict;
  bool ret;

  // example 1
  wordDict = {"leet", "code"};
  ret = s.wordBreak("leetcode", wordDict);
  print_ret(ret);

  // example 2
  wordDict = {"apple", "pen"};
  ret = s.wordBreak("applepenapple", wordDict);
  print_ret(ret);

  // example 3
  wordDict = {"cats", "dog", "sand", "and", "cat"};
  ret = s.wordBreak("catsandog", wordDict);
  print_ret(ret);

  return 0;
}
