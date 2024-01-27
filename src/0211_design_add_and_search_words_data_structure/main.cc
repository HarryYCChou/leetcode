/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>

using std::cout;
using std::endl;
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
};

class WordDictionary {
 public:
  Node* root;

  WordDictionary() {
    root = new Node();
  }

  void addWord(const string& word) {
    Node* cur = root;
    for (const auto& c : word) {
      if (cur->child[c - 'a'] == nullptr) cur->child[c - 'a'] = new Node();
      cur = cur->child[c - 'a'];
    }
    cur->isEnd = true;
  }

  bool search(const string& word) {
    int index = 0;
    return searchByIndex(word, index, root);
  }

  bool searchByIndex(const string word, int& index, Node* root) {
    if (root == nullptr) {
      cout << "null at : " << index << endl;
      return false;
    }
    if (index == word.size()) {
      return root->isEnd;
    }
    int cn = word[index] - 'a';
    if (word[index] == '.') {
      for (int i = 0; i < 26; i++) {
        if (searchByIndex(word, index + 1, root->child[i])) {
          return true;
        }
      }
      return false;
    }
    return searchByIndex(word, index + 1, root->child[cn]);
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
  WordDictionary wd;

  // example 1
  wd.addWord("bad");
  wd.addWord("dad");
  wd.addWord("mad");
  print_ret(wd.search("pad"));
  print_ret(wd.search("bad"));
  print_ret(wd.search(".ad"));
  print_ret(wd.search("b.."));

  return 0;
}
