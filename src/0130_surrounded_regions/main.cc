/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::stack;

class Solution {
 public:
  int m;
  int n;
  stack<vector<int>> stk;

  void solve(vector<vector<char>>&board) {
    m = board.size();
    n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O') {
          bool suc = false;
          suc = dfs(board, i, j, stk);
          while (!stk.empty()) {
            if (!suc) board[stk.top()[0]][stk.top()[1]] = 'O';
            stk.pop();
          }
        }
      }
    }
  }

  bool dfs(vector<vector<char>>& board, int row, int col,
           stack<vector<int>>& stk) {
    if (row < 0 || col < 0 || row >= m || col >= n) {
      return false;
    }

    if (board[row][col] == 'X') return true;
    board[row][col] = 'X';
    stk.push({row, col});
    if (dfs(board, row - 1, col, stk) &&
        dfs(board, row + 1, col, stk) &&
        dfs(board, row, col - 1, stk) &&
        dfs(board, row, col + 1, stk)) {
      return true;
    }
    return false;
  }
};

void print_ret(const vector<vector<char>>& board) {
  for (const auto& v : board) {
    for (const auto& c : v) {
      cout << c;
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution s;

  vector<vector<char>> board;

  // example 1
  board = {{'X', 'X', 'X', 'X'},
           {'X', 'O', 'O', 'X'},
           {'X', 'X', 'O', 'X'},
           {'X', 'O', 'X', 'X'}};
  s.solve(board);
  print_ret(board);

  // example 2
  board = {{'X'}};
  s.solve(board);
  print_ret(board);

  // example 3
  board = {{'O', 'X', 'X', 'O', 'X'},
           {'X', 'O', 'O', 'X', 'O'},
           {'X', 'O', 'X', 'O', 'X'},
           {'O', 'X', 'O', 'O', 'O'},
           {'X', 'X', 'O', 'X', 'O'}};
  s.solve(board);
  print_ret(board);

  return 0;
}
