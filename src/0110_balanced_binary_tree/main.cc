/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
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
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    int diff = maxDepth(root->left) - maxDepth(root->right);
    if (diff > 1 || diff < -1) return false;

    bool lr_balanced = isBalanced(root->left) && isBalanced(root->right);
    return lr_balanced;
  }

  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return (1 + max(maxDepth(root->left), maxDepth(root->right)));
  }
};

void print_ret(const bool& ret) {
  if (ret) {
    cout << "true";
  } else {
    cout << "false";
  }
  cout << endl;
}

int main() {
  Solution s;
  TreeNode* head;
  bool ret;

  // example 1
  head = new TreeNode(3, new TreeNode(9),
                        new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  ret = s.isBalanced(head);
  print_ret(ret);

  // example 2
  head = new TreeNode(1, new TreeNode(2, new TreeNode(3,
            new TreeNode(4), new TreeNode(4)), new TreeNode(3)),
            new TreeNode(2));
  ret = s.isBalanced(head);
  print_ret(ret);

  // example 3
  head = nullptr;
  ret = s.isBalanced(head);
  print_ret(ret);

  return 0;
}
