/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>

using std::cout;
using std::endl;

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
  int th = 0;
  int kthSmallest(TreeNode* root, int k) {
    if (root == nullptr) return 0;
    // left
    int ret = kthSmallest(root->left, k);
    if (th >= k) return ret;

    // root
    th += 1;
    if (th == k) return root->val;

    // right
    ret = kthSmallest(root->right, k);
    if (th >= k) return ret;
    return 0;
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
  p = new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr),
      new TreeNode(4));
  root = new TreeNode(5, p, new TreeNode(6));
  ret = s.kthSmallest(root, 3);
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
