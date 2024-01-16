/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

class Solution {
 public:
  bool checkInclusion(const string& s1, const string& s2) {
    bool ret = false;
    int i = 0, j = 0, count = s1.size();
    unordered_map<char, int> map;

    for (const auto& c : s1) {
      map[c] += 1;
    }

    while (j < s2.size()) {
      // check new char
      if (map[s2[j]] > 0) {
        count--;
      }
      map[s2[j]]--;
      j++;

      if (count == 0) {
        return true;
      }

      // check moving window
      if ((j - i) == s1.size()) {
        map[s2[i]]++;
        if (map[s2[i]] > 0) count++;
        i++;
      }
    }

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

  string s1, s2;
  bool ret;

  // example 1
  s1 = "ab";
  s2 = "eidbaooo";
  ret = s.checkInclusion(s1, s2);
  print_ret(ret);

  // example 2
  s1 = "ab";
  s2 = "eidboaoo";
  ret = s.checkInclusion(s1, s2);
  print_ret(ret);

  // example 3

  return 0;
}
