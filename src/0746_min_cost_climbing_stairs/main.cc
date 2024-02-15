/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::min;

class Solution {
 public:
  int minCostClimbingStairs(const vector<int>& cost) {
    int result = 0;

    int first = cost[0];
    int second = cost[1];

    for (int i = 2; i < cost.size(); i++) {
      result = min(first, second);

      first = second;
      second = result + cost[i];
    }

    return min(first, second);
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  vector<int> cost;
  int ret;

  // example 1
  cost = {10, 15, 20};
  ret = s.minCostClimbingStairs(cost);
  print_ret(ret);

  // example 2

  return 0;
}
