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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    if (root->val == p->val || root->val == q->val) {
      return root;
    }
    TreeNode *l, *r;
    l = lowestCommonAncestor(root->left, p, q);
    r = lowestCommonAncestor(root->right, p, q);
    if (l !=nullptr && r != nullptr) return root;
    if (l !=nullptr) return l;
    return r;
  }
};

void print_ret(TreeNode* ret) {
  cout << ret->val << endl;
}

int main() {
  Solution s;
  TreeNode *root, *p, *q;
  TreeNode *ret;

  // example 1
  p = new TreeNode(4, new TreeNode(3), new TreeNode(5));
  q = new TreeNode(2, new TreeNode(0), p);
  p = new TreeNode(8, new TreeNode(7), new TreeNode(9));
  root = new TreeNode(6, q, p);
  p = new TreeNode(2);
  q = new TreeNode(8);
  ret = s.lowestCommonAncestor(root, p, q);
  print_ret(ret);

  // example 2
  p = new TreeNode(2);
  q = new TreeNode(4);
  ret = s.lowestCommonAncestor(root, p, q);
  print_ret(ret);

  // example 3
  root = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)),
        new TreeNode(4));
  p = new TreeNode(2);
  q = new TreeNode(3);
  ret = s.lowestCommonAncestor(root, p, q);
  print_ret(ret);

  return 0;
}
