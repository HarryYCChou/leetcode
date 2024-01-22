/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <climits>

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
  int isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    return check_node(root->left, INT64_MIN, root->val)
          && check_node(root->right, root->val, INT64_MAX);
  }

  bool check_node(TreeNode* root, int64_t min, int64_t max) {
    if (root == nullptr) return true;
    if (root->val <= min || root->val >= max) {
      return false;
    }
    return check_node(root->left, min, root->val)
          && check_node(root->right, root->val, max);
  }
};

void print_ret(const int& ret) {
  if (ret) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}

int main() {
  Solution s;
  TreeNode *root, *p, *q;
  int ret;

  // example 1
  root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
  ret = s.isValidBST(root);
  print_ret(ret);

  // example 2
  p = new TreeNode(4, new TreeNode(3), new TreeNode(6));
  root = new TreeNode(5, new TreeNode(1), p);
  ret = s.isValidBST(root);
  print_ret(ret);

  // example 3
  p = new TreeNode(6, new TreeNode(3), new TreeNode(7));
  root = new TreeNode(5, new TreeNode(4), p);
  ret = s.isValidBST(root);
  print_ret(ret);

  // example 4
  p = new TreeNode(19, nullptr, new TreeNode(27));
  q = new TreeNode(26, p, nullptr);
  p = new TreeNode(47, nullptr, new TreeNode(56));
  root = new TreeNode(32, q, p);
  ret = s.isValidBST(root);
  print_ret(ret);

  // example 5
  p = new TreeNode(1, new TreeNode(0), new TreeNode(2));
  q = new TreeNode(5, new TreeNode(4), new TreeNode(6));
  root = new TreeNode(3, p, q);
  ret = s.isValidBST(root);
  print_ret(ret);

  // example 6
  p = new TreeNode(15, nullptr, new TreeNode(45));
  q = new TreeNode(10, nullptr, p);
  p = new TreeNode(30, q, nullptr);
  root = new TreeNode(3, nullptr, p);
  ret = s.isValidBST(root);
  print_ret(ret);

  return 0;
}
