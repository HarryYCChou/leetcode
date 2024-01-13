/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution {
 public:
  int maxProfit(const vector<int>& prices) {
    int left = 0, right = 0;
    int ret = 0;

    while (right < prices.size()) {
      if (prices[left] < prices[right]) {
        ret = max((prices[right] - prices[left]), ret);
      } else {
        left = right;
      }
      right++;
    }

    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  vector<int> prices;
  int ret;

  // example 1
  prices.clear();
  prices = {7, 1, 5, 3, 6, 4};
  ret = s.maxProfit(prices);
  print_ret(ret);

  // example 2
  prices.clear();
  prices = {7, 6, 4, 3, 1};
  ret = s.maxProfit(prices);
  print_ret(ret);

  return 0;
}
