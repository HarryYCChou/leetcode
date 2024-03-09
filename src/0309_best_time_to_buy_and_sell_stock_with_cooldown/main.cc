/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::unordered_map;

class Solution {
 public:
  // 2d DP + state machine method
  int maxProfit(const vector<int>& prices) {
    unordered_map<int, int> no_stock;
    unordered_map<int, int> one_stock;

    return dfs(no_stock, one_stock, prices, false, 0, 0);
  }

  int dfs(unordered_map<int, int>& no_stock,
          unordered_map<int, int>& one_stock,
          const vector<int>& prices,
          bool has_stock,
          int day,
          int profit) {
    if (day >= prices.size()) return 0;
    if (has_stock && one_stock.find(day) != one_stock.end()) {
      return one_stock[day];
    }
    if (!has_stock && no_stock.find(day) != no_stock.end()) {
      return no_stock[day];
    }

    if (has_stock) {
      int sell = dfs(no_stock, one_stock, prices,
                    !has_stock, day + 2, profit + prices[day]) + prices[day];
      int hold = dfs(no_stock, one_stock, prices, has_stock, day + 1, profit);
      one_stock[day] = max(sell, hold);
      return one_stock[day];
    } else {
      int buy = dfs(no_stock, one_stock, prices, !has_stock, day + 1,
                    profit - prices[day]) - prices[day];
      int hold = dfs(no_stock, one_stock, prices, has_stock, day + 1, profit);
      no_stock[day] = max(buy, hold);
      return no_stock[day];
    }
  }

  // 2D DP
  int maxProfit2(const vector<int>& prices) {
    int n = prices.size();
    int dp[n + 2][n + 2];
    for (int i = 0; i < n + 2; i++) {
      for (int j = 0; j < n + 2; j++) {
        dp[i][j] = 0;
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j > i; j--) {
        dp[i][j] = max(dp[i][j + 1], prices[j] - prices[i] + dp[j + 2][j + 2]);
      }
      dp[i][i] = max(dp[i + 1][i + 1], dp[i][i + 1]);
    }
    return dp[0][0];
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<int> prices;

  // example 1
  ret = s.maxProfit({1, 2, 3, 0, 2});
  print_ret(ret);

  // example 2
  ret = s.maxProfit({1});
  print_ret(ret);

  return 0;
}
