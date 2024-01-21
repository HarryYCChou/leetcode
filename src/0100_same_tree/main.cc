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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr) return false;
    if (q == nullptr) return false;
    if (!((p->val) == (q->val))) return false;
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
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
  TreeNode *p, *q;
  int ret;

  // example 1
  p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  ret = s.isSameTree(p, q);
  print_ret(ret);

  // example 2
  p = new TreeNode(1, new TreeNode(2), nullptr);
  q = new TreeNode(1, nullptr, new TreeNode(2));
  ret = s.isSameTree(p, q);
  print_ret(ret);

  // example 3
  p = new TreeNode(1, new TreeNode(2), new TreeNode(1));
  q = new TreeNode(1, new TreeNode(1), new TreeNode(2));
  ret = s.isSameTree(p, q);
  print_ret(ret);

  return 0;
}
