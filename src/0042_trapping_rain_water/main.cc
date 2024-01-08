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
using std::max;

class Solution {
 public:
  int trap(const vector<int>& height) {
    int area = 0;
    vector<int> h_stack;  // index
    for (int i = 0; i < height.size()-1; i++) {
      if (height[i] > height[i+1]) {
        // go down
        h_stack.push_back(i);
      } else if (height[i] < height[i+1]) {
        // go up
        if (h_stack.size() == 0) continue;

        // left is heigher
        if (height[h_stack.back()] > height[i+1]) {
          area += (height[i+1] - height[i]) * (i - h_stack.back());
        } else if (height[h_stack.back()] == height[i+1]) {
        // equal
          area += (height[h_stack.back()] - height[i]) * (i - h_stack.back());
          h_stack.pop_back();
        } else {
        // right is heigher
          int h_mid = height[i];
          while (h_stack.size() != 0) {
            if (height[h_stack.back()] > height[i+1]) {
              area += (height[i+1] - h_mid) * (i - h_stack.back());
              break;
            } else {
              area += (height[h_stack.back()] - h_mid) * (i - h_stack.back());
              h_mid = height[h_stack.back()];
              h_stack.pop_back();
            }
          }
        }
      }
    }

    return area;
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
  height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  ret = s.trap(height);
  print_ret(ret);

  // example 2
  height.clear();
  height = {4, 2, 0, 3, 2, 5};
  ret = s.trap(height);
  print_ret(ret);

  return 0;
}
