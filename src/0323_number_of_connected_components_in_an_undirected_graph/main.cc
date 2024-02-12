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
  int countComponents(int n, const vector<vector<int>>& edges) {
    int ret = n;
    vector<int> parents;
    vector<int> ranks;

    for (int i = 0; i < n; i++) {
      parents.push_back(i);
      ranks.push_back(1);
    }

    for (const auto& v : edges) {
      ret += add_union(parents, ranks, v[0], v[1]);
    }

    return ret;
  }

  int find_parent(vector<int>& parents, int n) {
    int p = parents[n];
    while (p != parents[p]) {
      parents[p] = parents[parents[p]];
      p = parents[p];
    }
    return p;
  }

  int add_union(vector<int>& parents, vector<int>& ranks, int n1, int n2) {
    int p1 = find_parent(parents, n1);
    int p2 = find_parent(parents, n2);

    if (ranks[p1] > ranks[p2]) {
      ranks[p1] += ranks[p2];
      parents[p2] = p1;
    } else {
      ranks[p2] += ranks[p1];
      parents[p1] = p2;
    }

    // can not reduce a components
    if (p1 == p2) return 0;
    return -1;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  vector<vector<int>> edges;
  int ret;

  // example 1
  edges = {{0, 1}, {0, 2}};
  ret = s.countComponents(3, edges);
  print_ret(ret);

  // example 2
  edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
  ret = s.countComponents(6, edges);
  print_ret(ret);

  return 0;
}
