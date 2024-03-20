/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::swap;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // from outside to inside circle
    for (int i = 0; i < n / 2; i++) {
      for (int j = i; j < n - i - 1; j++) {
        // right column to top row
        swap(matrix[j][n - i - 1], matrix[i][j]);
        // top row to left column
        swap(matrix[i][j], matrix[n - j - 1][i]);
        // left column to bottom row
        swap(matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1]);
      }
    }
  }
};

void print_ret(const vector<vector<int>>& ret) {
  for (const auto& v : ret) {
    cout << "[";
    for (const auto& n : v) {
      cout << n << ", ";
    }
    cout << "]" << endl;
  }
}

int main() {
  Solution s;

  vector<vector<int>> ret;

  // example 1
  ret = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  s.rotate(ret);
  print_ret(ret);

  // example 2
  ret = {{5, 1, 9, 11},
         {2, 4, 8, 10},
         {13, 3, 6, 7},
         {15, 14, 12, 16}};
  s.rotate(ret);
  print_ret(ret);

  // example 3

  return 0;
}
