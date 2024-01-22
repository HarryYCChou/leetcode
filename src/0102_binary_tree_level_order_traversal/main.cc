/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) :
                                  val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> ret;
  vector<vector<int>> levelOrder(TreeNode* root) {
    addElement(root, 0);
    return ret;
  }

  void addElement(TreeNode* root, int level) {
    if (root == nullptr) return;
    if (ret.size() <= level) {
      vector<int> tmp;
      ret.push_back(tmp);
    }
    ret[level].push_back(root->val);
    addElement(root->left, level+1);
    addElement(root->right, level+1);
  }
};

void print_ret(const vector<vector<int>>& ret) {
  cout << "[";
  for (const auto& v : ret) {
    cout << "[";
    for (const auto& n : v) {
      cout << n << ", ";
    }
    cout << "], ";
  }
  cout << "]" << endl;
}

int main() {
  Solution s;
  TreeNode *p, *root;
  vector<vector<int>> ret;

  // example 1
  p = new TreeNode(20, new TreeNode(15), new TreeNode(7));
  root = new TreeNode(3, new TreeNode(9), p);
  ret = s.levelOrder(root);
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
