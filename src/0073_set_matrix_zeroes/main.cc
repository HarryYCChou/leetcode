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
  void setZeroes(vector<vector<int>>& matrix) {
    bool first_col = false;
    for (int i = 0; i < matrix.size(); i++) {
      if (matrix[i][0] == 0) {
        first_col = true;
        break;
      }
    }

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 1; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    for (int i = 1; i < matrix.size(); i++) {
      if (matrix[i][0] == 0) {
        for (int j = 1; j < matrix[0].size(); j++) {
          matrix[i][j] = 0;
        }
      }
    }

    for (int j = 1; j < matrix[0].size(); j++) {
      if (matrix[0][j] == 0) {
        for (int i = 1; i < matrix.size(); i++) {
          matrix[i][j] = 0;
        }
      }
    }

    if (matrix[0][0] == 0) {
      for (int j = 1; j < matrix[0].size(); j++) {
        matrix[0][j] = 0;
      }
    }

    if (first_col) {
      for (int i = 0; i < matrix.size(); i++) {
        matrix[i][0] = 0;
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

  vector<vector<int>> matrix;

  // example 1
  matrix = {{1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}};
  s.setZeroes(matrix);
  print_ret(matrix);

  // example 2
  matrix = {{0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5}};
  s.setZeroes(matrix);
  print_ret(matrix);

  return 0;
}
