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
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) return false;
    if (subRoot == nullptr) return false;
    if (root->val == subRoot->val) {
      if (isSameTree(root, subRoot)) return true;
    }
    if (root->left != nullptr && isSubtree(root->left, subRoot)) return true;
    if (root->right != nullptr && isSubtree(root->right, subRoot)) return true;
    return false;
  }

  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
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
  p = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2)),
            new TreeNode(5));
  q = new TreeNode(4, new TreeNode(1), new TreeNode(2));
  ret = s.isSubtree(p, q);
  print_ret(ret);

  // example 2
  p = new TreeNode(3, new TreeNode(4, new TreeNode(1),
          new TreeNode(2, new TreeNode(0), nullptr)), new TreeNode(5));
  q = new TreeNode(4, new TreeNode(1), new TreeNode(2));
  ret = s.isSubtree(p, q);
  print_ret(ret);

  return 0;
}
