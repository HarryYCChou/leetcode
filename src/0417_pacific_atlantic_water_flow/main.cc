/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  int m;
  int n;

  vector<vector<int>> pacificAtlantic(const vector<vector<int>>& heights) {
    vector<vector<int>> ret;
    m = heights.size();
    n = heights[0].size();
    int *p_table = new int[m*n];
    int *a_table = new int[m*n];
    bool p, a;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        p_table[i * n + j] = false;
        a_table[i * n + j] = false;
      }
    }

    for (int col = 0; col < n; col++) {
      dfs(heights, INT_MIN, 0, col, p_table);
      dfs(heights, INT_MIN, m-1, col, a_table);
    }
    for (int row = 0; row < m; row++) {
      dfs(heights, INT_MIN, row, 0, p_table);
      dfs(heights, INT_MIN, row, n - 1, a_table);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (p_table[i * n + j] && a_table[i * n + j]) ret.push_back({i, j});
      }
    }

    return ret;
  }

  void dfs(const vector<vector<int>>& heights, int h,
                        int row, int col, int*& table) {
    if (row < 0 || col < 0 || row >= m || col >= n) return;
    if (heights[row][col] == -1 || heights[row][col] < h) return;
    if (table[row * n + col] == true) return;

    table[row * n + col] = true;
    int ori_height = heights[row][col];
    heights[row][col] = -1;
    dfs(heights, ori_height, row - 1, col, table);
    dfs(heights, ori_height, row + 1, col, table);
    dfs(heights, ori_height, row, col - 1, table);
    dfs(heights, ori_height, row, col + 1, table);
    heights[row][col] = ori_height;
  }
};

void print_ret(const vector<vector<int>>& ret) {
  cout << "[";
  for (const auto v : ret) {
    cout << "[" << v[0] << "," << v[1] << "]";
  }
  cout << "]" << endl;
}

int main() {
  Solution s;

  vector<vector<int>> heights;
  vector<vector<int>> ret;

  // example 1
  heights = {{1, 2, 2, 3, 5},
             {3, 2, 3, 4, 4},
             {2, 4, 5, 3, 1},
             {6, 7, 1, 4, 5},
             {5, 1, 1, 2, 4}};
  ret = s.pacificAtlantic(heights);
  print_ret(ret);

  // example 2
  heights = {{1}};
  ret = s.pacificAtlantic(heights);
  print_ret(ret);

  heights = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
             {52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 15},
             {51, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 65, 16},
             {50, 95, 132, 133, 134, 135, 136, 137, 138, 139, 140, 107, 66, 17},
             {49, 94, 131, 160, 161, 162, 163, 164, 165, 166, 141, 108, 67, 18},
             {48, 93, 130, 159, 180, 181, 182, 183, 184, 167, 142, 109, 68, 19},
             {47, 92, 129, 158, 179, 192, 193, 194, 185, 168, 143, 110, 69, 20},
             {46, 91, 128, 157, 178, 191, 196, 195, 186, 169, 144, 111, 70, 21},
             {45, 90, 127, 156, 177, 190, 189, 188, 187, 170, 145, 112, 71, 22},
             {44, 89, 126, 155, 176, 175, 174, 173, 172, 171, 146, 113, 72, 23},
             {43, 88, 125, 154, 153, 152, 151, 150, 149, 148, 147, 114, 73, 24},
             {42, 87, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 74, 25},
             {41, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 26},
             {40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27}};
  ret = s.pacificAtlantic(heights);
  print_ret(ret);

  return 0;
}
