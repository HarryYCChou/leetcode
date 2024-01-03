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
    unordered_map<string, int> m_s, m_t;

    for (int i = 0; i < s.length(); i++) {
      string s_tmp = s.substr(i,1);
      if (m_s.find(s_tmp) == m_s.end()) {
        // create new element for map
        m_s[s_tmp] = 1;
      } else {
        m_s[s_tmp] += 1;
      }
    }
      
    for (int i = 0; i < t.length(); i++) {
      string s_tmp = t.substr(i,1);
      if (m_t.find(s_tmp) == m_t.end()) {
        // create new element for map
        m_t[s_tmp] = 1;
      } else {
        m_t[s_tmp] += 1;
      }
    }

    return (m_s == m_t);
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
