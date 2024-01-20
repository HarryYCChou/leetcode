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
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;

    TreeNode *tmp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = tmp;

    return root;
  }
};

void print_ret(TreeNode* ret) {
  if (ret != nullptr) {
    cout << ret->val << ", ";
    print_ret(ret->left);
    print_ret(ret->right);
  }
}

int main() {
  Solution s;
  TreeNode* head;

  // example 1
  head = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                        new TreeNode(7, new TreeNode(6), new TreeNode(9)));
  head = s.invertTree(head);
  print_ret(head);
  // example 2

  // example 3

  return 0;
}
