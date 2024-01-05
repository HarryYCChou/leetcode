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
  vector<int> productExceptSelf(const vector<int>& nums) {
    int len = nums.size();
    vector<int> ret(len);

    int prefix = 1;
    for (int i = 0; i < len; i++) {
      ret[i] = prefix;
      prefix *= nums[i];
    }

    prefix = 1;
    for (int i = len-1; i >= 0 ; i--) {
      ret[i] *= prefix;
      prefix *= nums[i];
    }

    return ret;
  }
};

void print_ret(const vector<int>& ret) {
  for (const auto& e : ret) {
    cout << e << " ";
  }
  cout << endl;
}

int main() {
  Solution s;
  vector<int> v, ret;

  // example 1
  v.clear();
  v = {1, 2, 3, 4};
  ret = s.productExceptSelf(v);
  print_ret(ret);

  // example 2
  v.clear();
  v = {-1, -1, 0, -3, 3};
  ret = s.productExceptSelf(v);
  print_ret(ret);

  return 0;
}
