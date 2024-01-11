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
using std::max_element;

class Solution {
 public:
  int minEatingSpeed(const vector<int>& piles, int h) {
    // mininum hour 1 <= min_h <= max(piles)
    int speed_l = 1;
    int speed_r = piles[0];
    int speed_mid;

    // find the maximum by max_element
    auto e = max_element(piles.begin(), piles.end());
    speed_r = *e;

    while (speed_l<speed_r) {
      speed_mid = (speed_l+speed_r)/2;
      
      int hours = 0;
      for (auto const& n : piles) {
        hours += (n-1)/speed_mid + 1;
      }

      // accepted speed
      if (hours <= h) {
        speed_r = speed_mid;
      } else {
        speed_l = speed_mid + 1;
      }
    }

    return speed_l;
  }  
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  int ret;
  vector<int> piles;

  // example 1
  piles.clear();
  piles = {3, 6, 7, 11};
  ret = s.minEatingSpeed(piles, 8);
  print_ret(ret);

  // example 2
  piles.clear();
  piles = {30, 11, 23, 4, 20};
  ret = s.minEatingSpeed(piles, 5);
  print_ret(ret);

  // example 3
  piles.clear();
  piles = {30, 11, 23, 4, 20};
  ret = s.minEatingSpeed(piles, 6);
  print_ret(ret);

  return 0;
}
