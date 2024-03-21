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
  vector<int> plusOne(vector<int>& digits) {
    int carry_over = 1;
    int n = digits.size() - 1;
    while (n >= 0 && carry_over > 0) {
      carry_over = (digits[n] + 1 >= 10) ? 1 : 0;
      digits[n] = (digits[n] + 1) % 10;
      n--;
    }
    if (carry_over == 1) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};

void print_ret(const vector<int>& ret) {
  cout << "[";
  for (const auto& n : ret) {
    cout << n << ", ";
  }
  cout << "]" << endl;
}

int main() {
  Solution s;

  vector<int> ret;
  vector<int> digits;

  // example 1
  digits = {1, 2, 3};
  ret = s.plusOne(digits);
  print_ret(ret);

  // example 2
  digits = {4, 3, 2, 1};
  ret = s.plusOne(digits);
  print_ret(ret);

  // example 3
  digits = {9};
  ret = s.plusOne(digits);
  print_ret(ret);

  return 0;
}
