/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <climits>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

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
  int ret = INT_MIN;
  int maxPathSum(TreeNode* root) {
    calcNodeVal(root);
    return ret;
  }

  int calcNodeVal(TreeNode* root) {
    if (root == nullptr) return 0;
    int lValue = calcNodeVal(root->left);
    int rValue = calcNodeVal(root->right);
    ret = max(ret, root->val);
    ret = max(ret, root->val + lValue);
    ret = max(ret, root->val + rValue);
    ret = max(ret, lValue + root->val + rValue);
    return max(max(lValue, rValue) + root->val, root->val);
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  TreeNode *root, *p, *q;
  int ret;

  // example 1
  root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  ret = s.maxPathSum(root);
  print_ret(ret);

  // example 2
  p = new TreeNode(20, new TreeNode(15), new TreeNode(7));
  root = new TreeNode(-10, new TreeNode(9), p);
  ret = s.maxPathSum(root);
  print_ret(ret);

  return 0;
}
