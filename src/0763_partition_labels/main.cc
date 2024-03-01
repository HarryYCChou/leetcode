/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;

class Solution {
 public:
  vector<int> partitionLabels(const string& s) {
    vector<int> ret;
    int longest_pos[26]{0};

    for (int i = 0; i < s.size(); i++) {
      longest_pos[s[i] - 'a'] = i;
    }

    int start = 0;
    int end = 0;
    int i = 0;
    while (i < s.size()) {
      end = max(end, longest_pos[s[i] - 'a']);
      if (i == end) {
        ret.push_back(end - start + 1);
        start = i + 1;
      }
      i++;
    }

    return ret;
  }
};

void print_ret(const vector<int>& ret) {
  cout << "[";
  for (const auto& n : ret) {
    cout << n << ", ";
  }
  cout << "]" << endl;
}

int main() {
  Solution s;

  string str;
  vector<int> ret;

  // example 1
  str = "ababcbacadefegdehijhklij";
  ret = s.partitionLabels(str);
  print_ret(ret);

  // example 2
  str = "eccbbbbdec";
  ret = s.partitionLabels(str);
  print_ret(ret);

  return 0;
}
