/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // create root
    TreeNode* node = new TreeNode(preorder[0]);
    if (preorder.size() == 1) return node;

    int mid = 0;
    while (inorder[mid] != preorder[0]) {
      mid++;
    }
    if (mid != 0) {
      vector<int> p(preorder.begin()+1, preorder.begin() + mid + 1);
      vector<int> q(inorder.begin(), inorder.begin()+mid);
      node->left = buildTree(p, q);
    }
    if (mid < preorder.size() - 1) {
      vector<int> p(preorder.begin() + mid + 1, preorder.end());
      vector<int> q(inorder.begin() + mid + 1, inorder.end());
      node->right = buildTree(p, q);
    }
    return node;
  }
};

void print_ret(TreeNode* ret) {
  if (ret != nullptr) {
    cout << ret->val << ",";
    print_ret(ret->left);
    print_ret(ret->right);
  }
}

int main() {
  Solution s;
  vector<int> a, b;
  TreeNode* ret;

  // example 1
  a = {3, 9, 20, 15, 7};
  b = {9, 3, 15, 20, 7};
  ret = s.buildTree(a, b);
  print_ret(ret);

  // example 2
  a = {-1};
  b = {-1};
  ret = s.buildTree(a, b);
  print_ret(ret);

  // example 3
  a = {1, 2};
  b = {1, 2};
  ret = s.buildTree(a, b);
  print_ret(ret);

  return 0;
}
