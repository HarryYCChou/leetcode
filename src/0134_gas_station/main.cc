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
  int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
    int balance = 0;
    int ret = 0;
    for (int i = 0; i < gas.size(); i++) {
      balance += gas[i] - cost[i];
    }
    if (balance < 0) return -1;

    balance = 0;
    for (int i = 0; i < gas.size(); i++) {
      balance += gas[i] - cost[i];
      if (balance < 0) {
        ret = i + 1;
        balance = 0;
      }
    }
    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<int> gas, cost;

  // example 1
  gas = {1, 2, 3, 4, 5};
  cost = {3, 4, 5, 1, 2};
  ret = s.canCompleteCircuit(gas, cost);
  print_ret(ret);

  // example 2
  gas = {2, 3, 4};
  cost = {3, 4, 3};
  ret = s.canCompleteCircuit(gas, cost);
  print_ret(ret);

  // example 3

  return 0;
}
