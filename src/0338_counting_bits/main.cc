/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  vector<int> countBits(const int& n) {
    vector<int> ret(n + 1);

    for (int i = 0; i <= n; i++) {
      int num = i;
      int count = 0;
      while (num) {
        count++;
        num = (num & (num - 1));
      }
      ret[i] = count;
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

  vector<int> ret;

  // example 1
  ret = s.countBits(2);
  print_ret(ret);

  // example 2
  ret = s.countBits(5);
  print_ret(ret);

  // example 3

  return 0;
}
