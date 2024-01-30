/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Node {
 public:
  Node *child[52];
  Node() {
    for (int i = 0; i < 52; i++) {
      child[i] = nullptr;
    }
  }

  void insert(const string& str, int index, Node* cur) {
    if (index >= str.size()) {
      return;
    }
    int n = 0;
    if (str[index] <= 'Z') {
      // uppercase
      n = str[index] - 'A';
    } else {
      // lowercase
      n = str[index] - 'a' + 26;
    }
    if (cur->child[n] == nullptr) {
      cur->child[n] = new Node();
    }
    insert(str, index + 1, cur->child[n]);
  }
};

class Solution {
 public:
  Node* root;
  int m;
  int n;
  int len;

  bool exist(vector<vector<char>>& board, const string& word) {
    root = new Node();
    root->insert(word, 0, root);
    m = board.size();
    n = board[0].size();
    len = word.size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (search(board, i, j, 0, root)) return true;
      }
    }

    return false;
  }

  bool search(vector<vector<char>>& board, int r, int c,
               int index, Node* cur) {
    if (index >= len) {
      return true;
    }
    if (r >=m || r < 0 || c >= n || c < 0) return false;

    char ch = board[r][c];
    int n = 0;
    if (ch <= 'Z') {
      // uppercase
      n = ch - 'A';
    } else {
      // lowercase
      n = ch - 'a' + 26;
    }

    if (ch == '-' || cur->child[n] == nullptr) return false;
    board[r][c] = '-';
    if (search(board, r - 1, c, index + 1, cur->child[n])) return true;
    if (search(board, r + 1, c, index + 1, cur->child[n])) return true;
    if (search(board, r, c - 1, index + 1, cur->child[n])) return true;
    if (search(board, r, c + 1, index + 1, cur->child[n])) return true;
    board[r][c] = ch;

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

  bool ret;
  vector<vector<char>> board;

  // example 1
  board = {{'A', 'B', 'C', 'E'},
          {'S', 'F', 'C', 'S'},
          {'A', 'D', 'E', 'E'}};
  ret = s.exist(board, "ABCCED");
  print_ret(ret);

  // example 2
  ret = s.exist(board, "SEE");
  print_ret(ret);

  // example 3
  ret = s.exist(board, "ABCB");
  print_ret(ret);

  return 0;
}
