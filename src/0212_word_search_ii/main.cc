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
  Node* child[26];
  bool isEnd = false;

  Node() {
    for (int i = 0; i < 26; i++) {
      child[i] = nullptr;
    }
  }

  void insert(const string& word, int index) {
    if (index == word.size()) {
      isEnd = true;
      return;
    }
    if (child[word[index] - 'a'] == nullptr) {
      child[word[index] - 'a'] = new Node();
    }
    child[word[index] - 'a']->insert(word, index + 1);
  }
};

class Solution {
 public:
  Node* root = new Node();
  int m, n;
  vector<string> findWords(vector<vector<char>>& board,
                            const vector<string>& words) {
    vector<string> ret;

    // insert all words
    for (const auto word : words) {
      root->insert(word, 0);
    }
    cout << "search" << endl;

    // search m*n
    m = board.size();
    n = board[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        string word = "";
        searchByPoint(board, i, j, root, word, ret);
      }
    }
    return ret;
  }

  void searchByPoint(vector<vector<char>>& board, int r, int c, Node* &node,
                    string word, vector<string>& ret) {
    if (r < 0 || r >= m || c < 0 || c >=n || board[r][c] == '-') {
      return;
    }

    // check
    char ch = board[r][c];
    if (node->child[ch - 'a'] == nullptr) {
      return;
    } else {
      word += ch;
      if (node->child[ch - 'a']->isEnd) {
        ret.push_back(word);
        node->child[ch - 'a']->isEnd = false;
      }
    }

    board[r][c] = '-';
    // travel to four directions
    searchByPoint(board, r - 1, c, node->child[ch - 'a'], word, ret);
    searchByPoint(board, r + 1, c, node->child[ch - 'a'], word, ret);
    searchByPoint(board, r, c - 1, node->child[ch - 'a'], word, ret);
    searchByPoint(board, r, c + 1, node->child[ch - 'a'], word, ret);
    board[r][c] = ch;
  }
};

void print_ret(const vector<string>& ret) {
  for (const auto& s : ret) {
    cout << s << ",";
  }
  cout << endl;
}

int main() {
  Solution s;
  vector<vector<char>> board;
  vector<string> words;
  vector<string> ret;

  // example 1
  board = {{'o', 'a', 'a', 'n'},
           {'e', 't', 'a', 'e'},
           {'i', 'h', 'k', 'r'},
           {'i', 'f', 'l', 'v'}};
  words = {"oath", "pea", "eat", "rain"};
  ret = s.findWords(board, words);
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
