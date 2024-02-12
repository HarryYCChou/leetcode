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
  vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
    vector<int> parent;
    vector<int> ranks;
    vector<int> ret;

    for (int i = 0; i < edges.size(); i++) {
      parent.push_back(i);
      ranks.push_back(1);
    }

    for (const auto& e : edges) {
      if (!add_union(parent, ranks, e[0] - 1, e[1] - 1)) {
        ret = {e[0], e[1]};
      }
    }
    return ret;
  }

  int find_parent(vector<int>& parent, int node) {
    int par = parent[node];

    while (par != parent[par]) {
      par = parent[par];
    }

    return par;
  }

  bool add_union(vector<int>& parent, vector<int>& ranks, int n1, int n2) {
    int p1 = find_parent(parent, n1);
    int p2 = find_parent(parent, n2);

    if (p1 == p2) return false;

    if (ranks[p1] > ranks[p2]) {
      ranks[p1] += ranks[p2];
      parent[p2] = p1;
    } else {
      ranks[p2] += ranks[p1];
      parent[p1] = p2;
    }
    return true;
  }
};

void print_ret(const vector<int>& ret) {
  cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;
}

int main() {
  Solution s;

  vector<int> ret;
  vector<vector<int>> edges;

  // example 1
  edges = {{1, 2}, {1, 3}, {2, 3}};
  ret = s.findRedundantConnection(edges);
  print_ret(ret);

  // example 2
  edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
  ret = s.findRedundantConnection(edges);
  print_ret(ret);

  // example 3

  return 0;
}
