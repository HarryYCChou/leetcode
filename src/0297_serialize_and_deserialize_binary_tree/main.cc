/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::stoi;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) :
                                  val(x), left(left), right(right) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr) return "||";
    string ret = "|" + to_string(root->val) + "|";
    ret += serialize(root->left);
    ret += serialize(root->right);
    return ret;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    string s = data;
    return getOneNode(s);
  }

  TreeNode* getOneNode(string& s) {
    int end = 1;
    while (s[end] != '|') {
      end++;
    }

    TreeNode* node = nullptr;
    if (end == 1) {
      s = s.substr(end + 1, s.size() - end - 1);
      return node;
    } else {
      node = new TreeNode(stoi(s.substr(1, end - 1)));
    }
    s = s.substr(end + 1, s.size() - end - 1);
    node->left = getOneNode(s);
    node->right = getOneNode(s);
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
  Codec codec;
  TreeNode *root, *p, *q;
  TreeNode *ret;

  // example 1
  p = new TreeNode(3, new TreeNode(4), new TreeNode(5));
  root = new TreeNode(1, new TreeNode(2), p);
  ret = codec.deserialize(codec.serialize(root));
  print_ret(ret);

  // example 2
  ret = codec.deserialize(codec.serialize(nullptr));
  print_ret(ret);

  // example 3

  return 0;
}
