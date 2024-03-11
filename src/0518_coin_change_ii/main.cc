/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::pair;

class Solution {
 public:
  int change(const int& amount, const vector<int>& coins) {
    // pair<amount, coin_index> combination
    map<pair<int, int>, int> dp;
    return dfs(dp, amount, coins, 0);
  }

  int dfs(map<pair<int, int>, int>& dp, int amount,
          const vector<int>& coins, int index) {
    if (amount < 0 || index >= coins.size()) return 0;
    if (amount == 0) return 1;

    if (dp.find({index, amount}) != dp.end()) return dp[{index, amount}];
    int ret = 0;
    ret += dfs(dp, amount - coins[index], coins, index);
    ret += dfs(dp, amount, coins, index + 1);
    dp[{index, amount}] = ret;
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
  ret = s.change(5, {1, 2, 5});
  print_ret(ret);

  // example 2
  ret = s.change(3, {2});
  print_ret(ret);

  // example 3
  ret = s.change(10, {10});
  print_ret(ret);

  return 0;
}
