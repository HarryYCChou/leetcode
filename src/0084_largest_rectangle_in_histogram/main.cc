/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;
using std::stack;
using std::max;

class Solution {
 public:
  int largestRectangleArea2(const vector<int>& heights) {
    int max_area = 0;
    // index, height
    stack<pair<int, int>> stk;

    for (int i = 0; i < heights.size(); i++) {
      int start = i;
      while (!stk.empty() && (heights[i] < stk.top().second)) {
        // decrease -> calculate area
        pair<int, int> s = stk.top();
        int area = (i - s.first) * s.second;
        if (area > max_area) max_area = area;
        stk.pop();
        start = s.first;
      }
      stk.push(make_pair(start, heights[i]));
    }

    int end = heights.size();
    while (!stk.empty()) {
      pair<int, int> s = stk.top();
      int area = (end - s.first) * s.second;
      if (area > max_area) max_area = area;
      stk.pop();
    }

    return max_area;
  }

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
      int max_height = heights[start];  // local minimum
      int index = start;

      for (int i = start; i < end+1; i++) {
        if (heights[i] < min_height) {
          min_height = heights[i];
          index = i;
        }

        if (heights[i] > max_height) {
          max_height = heights[i];
        }
      }

      max_area = min_height * (end - start + 1);

      // all elements are the same height
      // dont need to seperate elements
      if (min_height == max_height) return max_area;

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
  ret = s.largestRectangleArea2(heights);
  print_ret(ret);

  // example 2
  heights.clear();
  heights = {2, 4};
  ret = s.largestRectangleArea2(heights);
  print_ret(ret);

  // example 3
  heights.clear();
  heights = {0, 9};
  ret = s.largestRectangleArea2(heights);
  print_ret(ret);

  // example 4
  heights.clear();
  heights = {2, 1, 2};
  ret = s.largestRectangleArea2(heights);
  print_ret(ret);

  // example 5
  heights.clear();
  heights = {3, 6, 5, 7, 4, 8, 1, 0};
  ret = s.largestRectangleArea2(heights);
  print_ret(ret);

  // example 6
  heights.clear();
  heights = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
  ret = s.largestRectangleArea2(heights);
  print_ret(ret);

  return 0;
}
