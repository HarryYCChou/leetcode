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
using std::stoi;

class Solution {
 public:
  unordered_map<int, int> map;
  int numDecodings(const string& s) {
    if (s[0] == '0') return 0;

    int d0 = 1;
    int d1 = 1;
    int next = 0;

    for (int i = 2; i <= s.size(); i++) {
      if (10 <= stoi(s.substr(i - 2, 2)) && stoi(s.substr(i - 2, 2)) <= 26) {
        next+=d0;
      }
      if (stoi(s.substr(i - 1, 1)) > 0) {
        next+=d1;
      }
      d0 = d1;
      d1 = next;
      next = 0;
    }

    return d1;
  }

  int numDecodings2(const string& s) {
    map.clear();
    return calWay(s, 0);
  }

  int calWay(const string& s, int start) {
    if (start >= s.size()) {
      return 1;
    }
    if (map.find(start) != map.end()) return map[start];

    int sum = 0;
    // select single char case
    if (s[start] > '0') {
      sum += calWay(s, start + 1);
      // select double char case
      if (start + 2 <= s.size()) {
        if (s[start] == '1' ||
            (s[start] == '2' && s[start+1] >= '0' && s[start+1] <= '6')) {
          sum += calWay(s, start + 2);
        }
      }
    }
    map[start] = sum;
    return sum;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;

  // example 1
  ret = s.numDecodings("11106");
  print_ret(ret);

  // example 2
  ret = s.numDecodings("12");
  print_ret(ret);

  // example 3
  ret = s.numDecodings("226");
  print_ret(ret);

  // example 4
  ret = s.numDecodings("06");
  print_ret(ret);

  return 0;
}
