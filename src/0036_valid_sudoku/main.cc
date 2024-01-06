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
    //vector<char> line;
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

 private:
  bool isValidOneLine(const vector<char>& line) {
    unordered_set<int> s(9);
    for (const auto& c : line) {
      if (c != '.') {
        if (s.find(c-'0') != s.end()) {
          // debug
          //for (const auto& c : line) {
          //  cout << c << " ";
          //}
          //cout << " <== false" << endl;

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
      {{'5','3','.','.','7','.','.','.','.'}
      ,{'6','.','.','1','9','5','.','.','.'}
      ,{'.','9','8','.','.','.','.','6','.'}
      ,{'8','.','.','.','6','.','.','.','3'}
      ,{'4','.','.','8','.','3','.','.','1'}
      ,{'7','.','.','.','2','.','.','.','6'}
      ,{'.','6','.','.','.','.','2','8','.'}
      ,{'.','.','.','4','1','9','.','.','5'}
      ,{'.','.','.','.','8','.','.','7','9'}};
  ret = s.isValidSudoku(board);
  print_ret(ret);

  // example 2
  board.clear();
  board = 
      {{'8','3','.','.','7','.','.','.','.'}
      ,{'6','.','.','1','9','5','.','.','.'}
      ,{'.','9','8','.','.','.','.','6','.'}
      ,{'8','.','.','.','6','.','.','.','3'}
      ,{'4','.','.','8','.','3','.','.','1'}
      ,{'7','.','.','.','2','.','.','.','6'}
      ,{'.','6','.','.','.','.','2','8','.'}
      ,{'.','.','.','4','1','9','.','.','5'}
      ,{'.','.','.','.','8','.','.','7','9'}};
  ret = s.isValidSudoku(board);
  print_ret(ret);

  board.clear();
  board = 
      {{'.','.','.','.','5','.','.','1','.'}
      ,{'.','4','.','3','.','.','.','.','.'}
      ,{'.','.','.','.','.','3','.','.','1'}
      ,{'8','.','.','.','.','.','.','2','.'}
      ,{'.','.','2','.','7','.','.','.','.'}
      ,{'.','1','5','.','.','.','.','.','.'}
      ,{'.','.','.','.','.','2','.','.','.'}
      ,{'.','2','.','9','.','.','.','.','.'}
      ,{'.','.','4','.','.','.','.','.','.'}};
  ret = s.isValidSudoku(board);
  print_ret(ret);

  return 0;
}
