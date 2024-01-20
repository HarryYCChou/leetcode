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
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return (1 + max(maxDepth(root->left), maxDepth(root->right)));
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  TreeNode* head;
  int ret;

  // example 1
  head = new TreeNode(3, new TreeNode(9),
                        new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  ret = s.maxDepth(head);
  print_ret(ret);

  // example 2
  head = new TreeNode(1, nullptr, new TreeNode(2));
  ret = s.maxDepth(head);
  print_ret(ret);

  // example 3

  return 0;
}
