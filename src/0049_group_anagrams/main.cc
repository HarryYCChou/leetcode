/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;
using std::unordered_map;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(const vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (const auto& s : strs) {
      map[to_hash_string(s)].push_back(s);
    }

    // return result
    vector<vector<string>> ret;
    for (const auto& pair : map) {
      ret.push_back(pair.second);
    }

    return ret;
  }

 private:
  string to_hash_string(const string& str) {
    int len = str.length();
    vector<int> count(26);

    // calculate times of each character
    for (int i = 0; i < len; i++) {
      count[str[i]-'a'] += 1;
    }

    // count to hash string
    string ret;
    for (int i = 0; i < 26; i++) {
      ret.append(to_string(count[i])+"|");
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
