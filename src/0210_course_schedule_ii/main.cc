/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::unordered_set;

class Solution {
 public:
  vector<int> findOrder(int numCourses,
          const vector<vector<int>>& prerequisites) {
    vector<int> ret;
    unordered_set<int> visited;
    unordered_set<int> selected;
    unordered_map<int , vector<int>> pre;

    for (const auto& v : prerequisites) {
      pre[v[0]].push_back(v[1]);
    }

    for (int i = 0; i < numCourses; i++) {
      if (!dfs(i, visited, selected, pre, ret)) {
        return {};
      }
    }
    return ret;
  }

  bool dfs(int crs, unordered_set<int>& visited, unordered_set<int>& selected,
        unordered_map<int, vector<int>>& pre, vector<int>& ret) {
    if (visited.find(crs) != visited.end()) return false;

    if (pre[crs].empty()) {
      if (selected.find(crs) == selected.end()) {
        selected.insert(crs);
        ret.push_back(crs);
      }
      return true;
    }

    visited.insert(crs);
    for (const auto& n : pre[crs]) {
      if (!dfs(n, visited, selected, pre, ret)) {
        return false;
      }
    }
    pre[crs].clear();
    if (selected.find(crs) == selected.end()) {
      selected.insert(crs);
      ret.push_back(crs);
    }
    visited.erase(crs);
    return true;
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
  vector<vector<int>> prerequisites;

  // example 1
  prerequisites = {{1, 0}};
  ret = s.findOrder(2, prerequisites);
  print_ret(ret);

  // example 2
  prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  ret = s.findOrder(4, prerequisites);
  print_ret(ret);

  // example 3
  prerequisites = {};
  ret = s.findOrder(1, prerequisites);
  print_ret(ret);

  return 0;
}
