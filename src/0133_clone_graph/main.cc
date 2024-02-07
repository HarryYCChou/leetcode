/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  explicit Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  unordered_map<Node*, Node*> map;
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    return dfs(node);
  }

  Node* dfs(Node* ori) {
    if (map.find(ori) != map.end()) {
      // connect
      return map[ori];
    }
    Node* n = new Node(ori->val);
    map[ori]= n;
    for (int i = 0; i < ori->neighbors.size(); i++) {
      n->neighbors.push_back(dfs(ori->neighbors[i]));
    }
    return n;
  }
};

void print_ret(Node* node) {
}

int main() {
  return 0;
}
