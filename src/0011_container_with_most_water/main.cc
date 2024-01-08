/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::min;

class Solution {
 public:
  int maxArea(const vector<int>& height) {
    int most_water = 0;
    int start = 0, end = height.size()-1;

    int tmp_area = 0;
    while (start < end) {
      tmp_area = area(height[start], height[end], end-start);
      if (tmp_area > most_water) most_water = tmp_area;

      if (height[start] < height[end]) {
        start++;
      } else {
        end--;
      }
    }

    return most_water;
  }

  int area(const int& h1, const int& h2, const int& d) {
    return (min(h1, h2) * d);
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  vector<int> height;
  int ret;

  // example 1
  height.clear();
  height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  ret = s.maxArea(height);
  print_ret(ret);

  // example 2
  height.clear();
  height = {1, 1};
  ret = s.maxArea(height);
  print_ret(ret);

  return 0;
}
