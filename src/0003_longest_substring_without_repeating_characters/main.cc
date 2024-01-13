/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::max;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int left = 0;
    int ret = 0;
    int len = s.size();
    for (int i = 0; i < s.size(); i++) {
      if (map[s[i]] > 0) {
        ret = max(ret, i - left);
        for (int j = left; j < map[s[i]] - 1; j++) {
          map[s[j]] = 0;
        }
        left = map[s[i]];
      }
      map[s[i]] = i + 1;
    }

    return max(ret, len - left);
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
  str = "abcabcbb";
  ret = s.lengthOfLongestSubstring(str);
  print_ret(ret);

  // example 2
  str = "bbbbb";
  ret = s.lengthOfLongestSubstring(str);
  print_ret(ret);

  // example 3
  str = "pwwkew";
  ret = s.lengthOfLongestSubstring(str);
  print_ret(ret);

  // example 4
  str = " ";
  ret = s.lengthOfLongestSubstring(str);
  print_ret(ret);

  return 0;
}
