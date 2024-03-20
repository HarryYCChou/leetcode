/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <climits>

using std::cout;
using std::endl;

class Solution {
 public:
  int reverse(int x) {
    int ret = 0;

    while (x != 0) {
      if (x > 0) {
        if (ret > INT_MAX / 10 
          || (ret == INT_MAX / 10 && x % 10 > INT_MAX % 10)) {
          return 0;
        }
      } else {
        if (ret < INT_MIN / 10 
          || (ret == INT_MIN / 10 && x % 10 < INT_MIN % 10)) {
          return 0;
        }
      }

      ret *= 10;
      ret += x % 10;
      x /= 10;
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

  // example 1
  ret = s.reverse(123);
  print_ret(ret);

  // example 2
  ret = s.reverse(-123);
  print_ret(ret);

  // example 3
  ret = s.reverse(120);
  print_ret(ret);

  return 0;
}
