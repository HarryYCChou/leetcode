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
using std::sort;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (const auto& s : strs) {
      string sorted_str = s;
      sort(sorted_str.begin(), sorted_str.end());
      map[sorted_str].push_back(s);
    }

    // return result
    vector<vector<string>> ret;
    for (const auto& pair : map) {
      ret.push_back(pair.second);
    }

    return ret;
  }
};

void print_ret(const vector<vector<string>>& ret) {
  for (const auto& v : ret) {
    for (const auto& s : v) {
      cout << s << ",";
    }
    cout << endl;
  }
}

int main() {
  Solution s;
  vector<string> str;
  vector<vector<string>> ret;


  // example 1
  str.clear();
  str = {"eat", "tea", "tan", "ate", "nat", "bat"};
  ret = s.groupAnagrams(str);
  print_ret(ret);

  // example 2
  str.clear();
  str = {""};
  ret = s.groupAnagrams(str);
  print_ret(ret);

  // example 3
  str.clear();
  str = {"a"};
  ret = s.groupAnagrams(str);
  print_ret(ret);

  return 0;
}
