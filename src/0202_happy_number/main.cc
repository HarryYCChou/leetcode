/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> s;

    while (s.find(n) == s.end()) {
      if (n == 1) return true;
      s.insert(n);
      int sum = 0;
      while (n > 0) {
        sum += (n % 10) * (n % 10);
        n /= 10;
      }
      n = sum;
    }

    return false;
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

  bool ret;

  // example 1
  ret = s.isHappy(19);
  print_ret(ret);

  // example 2
  ret = s.isHappy(2);
  print_ret(ret);

  // example 3

  return 0;
}
