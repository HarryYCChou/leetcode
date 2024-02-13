/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  bool validTree(int n, const vector<vector<int>>& edges) {
    vector<int> parents;
    vector<int> ranks;

    if (edges.size() != n - 1) return false;

    for (int i = 0; i < n; i++) {
      parents.push_back(i);
      ranks.push_back(1);
    }

    for (const auto& v : edges) {
      if (!add_union(parents, ranks, v[0], v[1])) return false;
    }

    return true;
  }

  int find_parent(vector<int>& parents, int p) {
    int par = parents[p];

    while (par != parents[par]) {
      parents[par] = parents[parents[par]];
      par = parents[par];
    }
    return par;
  }

  bool add_union(vector<int>& parents, vector<int>& ranks, int n1, int n2) {
    int p1 = find_parent(parents, n1);
    int p2 = find_parent(parents, n2);

    if (p1 == p2) return false;

    if (ranks[p1] > ranks[p2]) {
      ranks[p1] += ranks[p2];
      parents[p2] = p1;
    } else {
      ranks[p2] += ranks[p1];
      parents[p1] = p2;
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

  vector<vector<int>> edges;
  bool ret;

  // example 1
  edges = {{0, 1}, {0, 2}, {0, 3}};
  ret = s.validTree(5, edges);
  print_ret(ret);

  // example 2
  edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
  ret = s.validTree(5, edges);
  print_ret(ret);

  // example 3

  return 0;
}
