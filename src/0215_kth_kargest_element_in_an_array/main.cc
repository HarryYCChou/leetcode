/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::greater;

class Solution {
 public:
  int findKthLargest(const vector<int>& nums, int k) {
    this->k = k;
    for (const auto& n : nums) {
      add(n);
    }
    return pq.top();
  }

 private:
  int k;
  // default top is the greatest
  priority_queue<int, vector<int>, greater<int>> pq;

  void add(const int& val) {
    pq.push(val);
    if (pq.size() > k) pq.pop();
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  vector<int> nums;
  int ret;

  // example 1
  nums = {3, 2, 1, 5, 6, 4};
  ret = s.findKthLargest(nums, 2);
  print_ret(ret);

  // example 2
  nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  ret = s.findKthLargest(nums, 4);
  print_ret(ret);

  // example 3

  return 0;
}
