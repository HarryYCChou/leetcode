/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;
using std::unordered_map;

class Solution {
 public:
  bool canFinish(int numCourse, const vector<vector<int>>& prerequisites) {
    unordered_set<int> visited;
    unordered_map<int, vector<int>> pre;

    for (const auto& v : prerequisites) {
      pre[v[0]].push_back(v[1]);
    }

    for (int i = 0; i < numCourse; i++) {
      if (!dfs(i, visited, pre)) return false;
    }
    return true;
  }

  bool dfs(int crs, unordered_set<int>& visited,
            unordered_map<int, vector<int>>& pre) {
    if (pre[crs].empty()) return true;

    if (visited.find(crs) != visited.end()) return false;

    visited.insert(crs);
    for (const auto n : pre[crs]) {
      if (!dfs(n, visited, pre)) {
        return false;
      }
    }
    pre[crs].clear();
    visited.erase(crs);
    return true;
  }
};

void print_ret(const bool& ret) {
  if (ret) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }
}

int main() {
  Solution s;

  bool ret;
  vector<vector<int>> prerequisites;

  // example 1
  prerequisites = {{1, 0}};
  ret = s.canFinish(2, prerequisites);
  print_ret(ret);

  // example 2
  prerequisites = {{1, 0}, {0, 1}};
  ret = s.canFinish(2, prerequisites);
  print_ret(ret);

  return 0;
}
