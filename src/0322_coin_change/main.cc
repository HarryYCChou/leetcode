/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::max;
using std::min;

class Solution {
 public:
  // DP - bottom up
  int coinChange(const vector<int>& coins, int amount) {
    vector<int> dp;
    for (int i = 0; i <= amount; i++) {
      dp.push_back(amount + 1);
    }
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      for (const auto& coin : coins) {
        if (coin > i) continue;
        if (dp[i - coin] == amount + 1) continue;
        dp[i] =  min(dp[i], 1 + dp[i - coin]);
      }
    }

    return (dp[amount] == amount + 1) ? -1 : dp[amount];
  }

  // DFS
  int coinChange2(const vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    int ret = -1;
    dfs(0, coins, amount, 0, 0, ret);
    return ret;
  }

  void dfs(int index, const vector<int>& coins, int amount,
            int sum, int use, int& ret) {
    if (index == coins.size()) {
      if (sum == amount) {
        if (ret == -1) {
          ret = use;
        } else {
          ret = min(ret, use);
        }
      }
      return;
    }

    int i = 0;
    while (coins[index] <= amount && (sum + i * coins[index] <= amount)) {
      dfs(index + 1, coins, amount, sum + i * coins[index], use + i, ret);
      i++;
    }
    return;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<int> coins;

  // example 1
  coins = {1, 2, 5};
  ret = s.coinChange(coins, 11);
  print_ret(ret);

  // example 2
  coins = {2};
  ret = s.coinChange(coins, 3);
  print_ret(ret);

  // example 3
  coins = {1};
  ret = s.coinChange(coins, 0);
  print_ret(ret);

  // example 4
  coins = {1, 2147483647};
  ret = s.coinChange(coins, 2);
  print_ret(ret);
  return 0;
}
