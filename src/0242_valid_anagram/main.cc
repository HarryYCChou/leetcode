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
  bool isAnagram(string s, string t) {
    unordered_map<char, int> map_s, map_t;

    if (s.length() != t.length()) return false;

    int len = s.length();
    for (int i = 0; i < len; i++) {
      map_s[s[i]] += 1;
      map_t[t[i]] += 1;
    }

    return (map_s == map_t);
  }
};

void print_ret(bool ret) {
  if (ret)
    cout << "true" << endl;
  else
    cout << "false" << endl;
}

int main() {
  Solution s;
  bool ret;

  // example 1
  ret = s.isAnagram("anagram", "nagaram");
  print_ret(ret);

  // example 2
  ret = s.isAnagram("rat", "car");
  print_ret(ret);

  return 0;
}
