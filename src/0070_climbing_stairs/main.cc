/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

class Solution {
 public:
  unordered_map<int, int> map;

  int climbStairs(const int& n) {
    return countWay(n);
  }

  int countWay(int n) {
    if (n < 0) {
      return 0;
    } else if (n == 0) {
      return 1;
    }
    if (map.find(n) != map.end()) return map[n];

    int ret = countWay(n - 1) + countWay(n - 2);
    map[n] = ret;
    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;

  // example 1
  ret = s.climbStairs(2);
  print_ret(ret);

  // example 2
  ret = s.climbStairs(3);
  print_ret(ret);

  return 0;
}
