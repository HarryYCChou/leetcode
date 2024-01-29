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
  vector<vector<int>> combinationSum(const vector<int>& candidates,
                                      const int& target) {
    vector<vector<int>> ret;
    vector<int> curr;
    int sum = 0;
    dfs(candidates, 0, sum, target, curr, ret);
    return ret;
  }

 private:
  void dfs(const vector<int>& candidates, int num, int& sum, const int& target,
      vector<int>&curr, vector<vector<int>>& ret) {
    if (num == candidates.size()) return;

    for (int i = num; i < candidates.size(); i++) {
      curr.push_back(candidates[i]);
      sum += candidates[i];
      if (sum == target) {
        ret.push_back(curr);
      } else if (sum > target) {
        curr.pop_back();
        sum -= candidates[i];
        continue;
      } else {
        dfs(candidates, i, sum, target, curr, ret);
      }
      curr.pop_back();
      sum -= candidates[i];
    }
  }
};

void print_ret(const vector<vector<int>>& ret) {
  cout << "[";
  for (const auto& v : ret) {
    cout << "[";
    for (const auto& n : v) {
      cout << n << ",";
    }
    cout << "],";
  }
  cout << "]," << endl;
}

int main() {
  Solution s;

  std::vector<vector<int>> ret;
  std::vector<int> candidates;

  // example 1
  candidates = {2, 3, 6, 7};
  ret = s.combinationSum(candidates, 7);
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
