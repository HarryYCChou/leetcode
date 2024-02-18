/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
 public:
  string longestPalindrome(string s) {
    int longest = 0;
    int start = 0;
    int end = 0;
    int start_ret = 0;
    for (int i = 0; i < s.size(); i++) {
      start = i;
      end = i;
      while (start >= 0 && end < s.size() && s[start] == s[end]) {
        if (end - start + 1 > longest) {
          longest = end - start + 1;
          start_ret = start;
        }
        start--;
        end++;
      }
      start = i;
      end = i + 1;
      while (start >= 0 && end < s.size() && s[start] == s[end]) {
        if (end - start + 1 > longest) {
          longest = end - start + 1;
          start_ret = start;
        }
        start--;
        end++;
      }
    }
    return s.substr(start_ret, longest);
  }

  // expand window size
  string longestPalindrome2(string s) {
    string ret = s.substr(0, 1);
    int w = 1;
    for (int i = 0; i < s.size(); i++) {
      int end = s.size() - 1;
      while ((end - i + 1) > w) {
        if (s[end] == s[i]) {
          if (isPalindromic(s.substr(i, end - i + 1))) {
            w = end - i + 1;
            ret = s.substr(i, end - i + 1);
            break;
          }
        }
        end--;
      }
    }
    return ret;
  }

  // from maximum window size
  string longestPalindrome3(string s) {
    int wins = s.size();
    for (int w = s.size(); w > 0; w--) {
      for (int i = 0; i < s.size() - 1; i++) {
        if (i + w - 1 > s.size()) break;
        if (isPalindromic(s.substr(i, w))) return s.substr(i, w);
      }
    }
    return s.substr(0, 1);
  }

  bool isPalindromic(string s) {
    int start = 0;
    int end = s.size() - 1;

    while (start <= end) {
      if (s[start] != s[end]) return false;
      start++;
      end--;
    }
    return true;
  }
};

void print_ret(const string& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  string ret;

  // example 1
  ret = s.longestPalindrome("babad");
  print_ret(ret);

  // example 2
  ret = s.longestPalindrome("cbbd");
  print_ret(ret);

  // example 3

  return 0;
}
