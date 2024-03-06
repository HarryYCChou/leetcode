/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::min;

class Solution {
 public:
  string foreignDictionary(const vector<string>& words) {
    unordered_map<char, bool> visited;
    unordered_map<char, vector<char>> graph;

    for (int i = 0; i < words.size() - 1; i++) {
      string w1 = words[i];
      string w2 = words[i + 1];
      int len = min(w1.size(), w2.size());

      // invalid
      if (w1.size() < w2.size() && w1.substr(0, len) == w2.substr(0, len)) {
        return "";
      }

      for (int j = 0; j < len; j++) {
        if (w1[j] != w2[j]) {
          graph[w1[j]].push_back(w2[j]);
          break;
        }
      }
    }

    string ret = "";
    unordered_map<char, vector<char>>::iterator it = graph.begin();

    while (it != graph.end()) {
      if (dfs(visited, graph, ret, it->first)) {
        return "";
      }
      it++;
    }

    return ret;
  }

  bool dfs(unordered_map<char, bool>& visited,
           unordered_map<char, vector<char>>& graph,
           string& ret,
           char c) {
    if (visited.find(c) != visited.end()) {
      return visited[c];
    }
    visited[c] = true;
    for (int i = 0; i < graph[c].size(); i++) {
      char next_c = graph[c][i];
      if (dfs(visited, graph, ret, next_c)) return true;
    }

    visited[c] = false;
    ret = c + ret;
    return false;
  }
};

void print_ret(const string& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  string ret;
  vector<string> words;

  // example 1
  words = {"z", "o"};
  ret = s.foreignDictionary(words);
  print_ret(ret);

  // example 2
  words = {"hrn", "hrf", "er", "enn", "rfnn"};
  ret = s.foreignDictionary(words);
  print_ret(ret);

  return 0;
}
