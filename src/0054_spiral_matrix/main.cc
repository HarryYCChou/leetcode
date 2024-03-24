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
  vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    vector<int> ret;

    // m1 row minimun
    // m2 row maximun
    // n1 col minimun
    // n2 col maximun
    int m1 = 0;
    int n1 = 0;
    int m2 = matrix.size() - 1;
    int n2 = matrix[0].size() - 1;

    while (m1 <= m2 && n1 <= n2) {
      for (int i = n1; i <= n2; i++) {
        ret.push_back(matrix[m1][i]);
      }
      m1++;

      for (int i = m1; i <= m2; i++) {
        ret.push_back(matrix[i][n2]);
      }
      n2--;

      if (m1 > m2) break;
      for (int i = n2; i >= n1; i--) {
        ret.push_back(matrix[m2][i]);
      }
      m2--;

      if (n1 > n2) break;
      for (int i = m2; i >= m1; i--) {
        ret.push_back(matrix[i][n1]);
      }
      n1++;
    }
    return ret;
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

  // example 1
  ret = s.spiralOrder({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  print_ret(ret);

  // example 2
  ret = s.spiralOrder({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}});
  print_ret(ret);

  // example 3

  return 0;
}
