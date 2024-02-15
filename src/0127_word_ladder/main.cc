/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stack;
using std::unordered_map;
using std::unordered_set;

class Solution {
 public:
  int ladderLength(const string& beginWord, const string& endWord,
                  const vector<string>& wordList) {
    int ret = 1;
    stack<string> stk;
    stack<string> tmp;
    unordered_set<string> dict;

    stk.push(beginWord);
    for (const auto& s : wordList) {
      dict.insert(s);
    }

    if (dict.find(endWord) == dict.end()) return 0;

    while (!stk.empty()) {
      while (!stk.empty()) {
        tmp.push(stk.top());
        stk.pop();
      }
      while (!tmp.empty()) {
        string s = tmp.top();
        if (s == endWord) return ret;
        for (int i = 0; i < s.size(); i++) {
          char ori = s[i];
          for (int j = 0; j < 26; j++) {
            s[i] = j + 'a';
            if (dict.find(s) != dict.end()) {
              stk.push(s);
              dict.erase(s);
            }
          }
          s[i] = ori;
        }
        tmp.pop();
      }
      ret++;
    }

    return 0;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  vector<string> wordList;

  int ret;
  // example 1
  wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  ret = s.ladderLength("hit", "cog", wordList);
  print_ret(ret);

  // example 2
  wordList = {"hot", "dot", "dog", "lot", "log"};
  ret = s.ladderLength("hit", "cog", wordList);
  print_ret(ret);

  return 0;
}
