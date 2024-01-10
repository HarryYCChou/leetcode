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
  bool searchMatrix(const vector<vector<int>>& matrix, const int& target) {
    int left = 0, right = matrix.size() - 1, mid;
    int row = 0;
    // binary search for row
    while (left <= right) {
      mid = (left + right) / 2;

      if (left == mid) {
        row = (target >= matrix[right][0]) ? right : left;
        break;
      }

      int mid_value = matrix[mid][0];

      if (mid_value == target) return true;
      if (mid_value < target) {
        left = mid;
      }
      if (mid_value > target) right = mid - 1;
    }

    // binary search for col
    left = 0; right = matrix[row].size() - 1;
    while (left <= right) {
      mid = (left + right) / 2;

      int mid_value = matrix[row][mid];
      if (mid_value == target) return true;
      if (mid_value < target) left = mid + 1;
      if (mid_value > target) right = mid - 1;
    }

    return false;
  }
};

void print_ret(const bool& ret) {
  if (ret) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}

int main() {
  Solution s;
  vector<vector<int>> matrix;
  bool ret;

  // example 1
  matrix.clear();
  matrix = {{1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 20, 34, 60}};
  ret = s.searchMatrix(matrix, 3);
  print_ret(ret);

  // example 2
  matrix.clear();
  matrix = {{1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 20, 34, 60}};
  ret = s.searchMatrix(matrix, 13);
  print_ret(ret);

  // example 3
  matrix.clear();
  matrix = {{1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 20, 34, 60}};
  ret = s.searchMatrix(matrix, 11);
  print_ret(ret);

  // example 4
  matrix.clear();
  matrix = {{1},
            {3}};
  ret = s.searchMatrix(matrix, 3);
  print_ret(ret);

  return 0;
}
