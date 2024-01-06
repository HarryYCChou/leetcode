/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

class Solution {
 public:
  bool isValidSudoku(const vector<vector<char>>& board) {
    // check each row
    for (const vector<char>& line : board) {
      if (!isValidOneLine(line)) return false;
    }

    vector<char> line;
    // check each column
    for (int i = 0; i < 9; i++) {
      line.clear();
      // create a temp line
      for (int j = 0; j < 9; j++) {
        // i = row
        // j = column
        line.push_back(board[j][i]);
      }
      if (!isValidOneLine(line)) return false;
    }

    // check each 3x3 sub-box
    for (int i = 0; i < 9; i+=3) {
      // create a temp line
      for (int j = 0; j < 9; j+=3) {
        line.clear();
        // i = row
        // j = column

        // for sub-box
        line.insert(line.end(), board[i].begin()+j, board[i].begin()+j+3);
        line.insert(line.end(), board[i+1].begin()+j, board[i+1].begin()+j+3);
        line.insert(line.end(), board[i+2].begin()+j, board[i+2].begin()+j+3);
        if (!isValidOneLine(line)) return false;
      }
    }

    return true;
  }

  bool isValidSudoku2(const vector<vector<char>>& board) {
    // valid array[index][num]
    bool v_row[9][9] = {false};
    bool v_col[9][9] = {false};
    bool v_box[9][9] = {false};
    /* sub-box
     * -------------
     * | 0 | 1 | 2 |
     * -------------
     * | 3 | 4 | 5 |
     * -------------
     * | 6 | 7 | 8 |
     * -------------
     */

    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        if (board[r][c] != '.') {
          int num = board[r][c] - '1';
          int box_n = r/3 * 3 + c/3;
          if (v_row[r][num] || v_col[c][num] || v_box[box_n][num]) return false;

          v_row[r][num] = v_col[c][num] = v_box[box_n][num] = true;
        }
      }
    }

    return true;
  }

 private:
  bool isValidOneLine(const vector<char>& line) {
    unordered_set<int> s(9);
    for (const auto& c : line) {
      if (c != '.') {
        if (s.find(c-'0') != s.end()) {
          return false;
        }
        s.insert(c-'0');
      }
    }

    return true;
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
  vector<vector<char>> board;
  bool ret;

  // example 1
  board.clear();
  board =
      {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}
      , {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
      , {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
      , {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
      , {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
      , {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
      , {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
      , {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
      , {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  ret = s.isValidSudoku(board);
  // ret = s.isValidSudoku2(board);
  print_ret(ret);

  // example 2
  board.clear();
  board =
      {{'8', '3', '.', '.', '7', '.', '.', '.', '.'}
      , {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
      , {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
      , {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
      , {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
      , {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
      , {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
      , {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
      , {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  ret = s.isValidSudoku(board);
  // ret = s.isValidSudoku2(board);
  print_ret(ret);

  // example 3
  board.clear();
  board =
      {{'.', '.', '.', '.', '5', '.', '.', '1', '.'}
      , {'.', '4', '.', '3', '.', '.', '.', '.', '.'}
      , {'.', '.', '.', '.', '.', '3', '.', '.', '1'}
      , {'8', '.', '.', '.', '.', '.', '.', '2', '.'}
      , {'.', '.', '2', '.', '7', '.', '.', '.', '.'}
      , {'.', '1', '5', '.', '.', '.', '.', '.', '.'}
      , {'.', '.', '.', '.', '.', '2', '.', '.', '.'}
      , {'.', '2', '.', '9', '.', '.', '.', '.', '.'}
      , {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};
  ret = s.isValidSudoku(board);
  // ret = s.isValidSudoku2(board);
  print_ret(ret);

  return 0;
}
