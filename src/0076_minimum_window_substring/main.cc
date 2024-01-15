/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
 public:
  string minWindow(const string s, const string t) {
    int i = 0, j = 0, count = t.size(), minCount = INT_MAX;
    // use another string will increase the memory use.
    // string ret = "";
    int start = 0;
    unordered_map<char, int> map;

    for (const auto& c : t) {
      map[c] += 1;
    }

    while (j < s.size()) {
      if (map[s[j]] > 0) {
        count--;
      }

      map[s[j]]--;
      j++;

      while (count == 0) {
        if ((j - i) < minCount) {
          minCount = j - i;
          // ret = s.substr(i, minCount);
          start = i;
        }

        map[s[i]]++;
        if (map[s[i]] > 0) count++;
        i++;
      }
    }

    if (minCount < INT_MAX) {
      return s.substr(start, minCount);
    }

    return "";
  }
};

void print_ret(const string& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  string str_s, str_t;
  string ret;

  // example 1
  str_s = "ADOBECODEBANC";
  str_t = "ABC";
  ret = s.minWindow(str_s, str_t);
  print_ret(ret);

  // example 2
  str_s = "a";
  str_t = "a";
  ret = s.minWindow(str_s, str_t);
  print_ret(ret);

  // example 3
  str_s = "a";
  str_t = "aa";
  ret = s.minWindow(str_s, str_t);
  print_ret(ret);

  return 0;
}
