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
  int goodNodes(TreeNode* root) {
    return check(root, INT_MIN);
  }

  int check(TreeNode* root, int maximum) {
    if (root == nullptr) return 0;

    int cur_maximum;
    int ret = 0;

    if (root->val >= maximum) {
      ret += 1;
      cur_maximum = root->val;
    } else {
      cur_maximum = maximum;
    }

    ret += check(root->left, cur_maximum);
    ret += check(root->right, cur_maximum);
    return ret;
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
  p = new TreeNode(1, new TreeNode(3), nullptr);
  q = new TreeNode(4, new TreeNode(1), new TreeNode(5));
  root = new TreeNode(3, p, q);
  ret = s.goodNodes(root);
  print_ret(ret);

  // example 2
  p = new TreeNode(3, new TreeNode(4), new TreeNode(2));
  q = new TreeNode(4, new TreeNode(1), new TreeNode(5));
  root = new TreeNode(3, p, nullptr);
  ret = s.goodNodes(root);
  print_ret(ret);

  // example 3
  root = new TreeNode(1);
  ret = s.goodNodes(root);
  print_ret(ret);

  return 0;
}
