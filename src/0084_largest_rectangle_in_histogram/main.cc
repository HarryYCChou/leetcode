/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::min;

class Solution {
 public:
  int largestRectangleArea(const vector<int>& heights) {
    return find_max_area(0, heights.size()-1, heights);
  }

  int find_max_area(int start, int end, const vector<int>& heights) {
    int max_area = 0;
    if (start == end) {
      return heights[start];
    } else {
      // find the minimum height (bottleneck)
      int min_height = heights[start];  // local minimum
      int index = start;

      for (int i = start; i < end+1; i++) {
        if (heights[i] < min_height) {
          min_height = heights[i];
          index = i;
        }
      }

      max_area = min_height * (end - start + 1);

      // seperate to two group
      // find the index of min_height
      int sub_area1 = 0;
      int sub_area2 = 0;

      if (index == start) {
        // smallest in the begin
        sub_area1 = find_max_area(start+1, end, heights);
      } else if (index == end) {
        // smallest in the end
        sub_area1 = find_max_area(start, end-1, heights);
      } else {
        // left part
        sub_area1 = find_max_area(start, index-1, heights);

        // right part
        sub_area2 = find_max_area(index+1, end, heights);
      }

      if (sub_area1 > max_area) { max_area = sub_area1; }
      if (sub_area2 > max_area) { max_area = sub_area2; }
    }

    return max_area;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  vector<int> heights;
  int ret;

  // example 1
  heights.clear();
  heights = {2, 1, 5, 6, 2, 3};
  ret = s.largestRectangleArea(heights);
  print_ret(ret);

  // example 2
  heights.clear();
  heights = {2, 4};
  ret = s.largestRectangleArea(heights);
  print_ret(ret);

  // example 3
  heights.clear();
  heights = {4, 2};
  ret = s.largestRectangleArea(heights);
  print_ret(ret);

  return 0;
}
