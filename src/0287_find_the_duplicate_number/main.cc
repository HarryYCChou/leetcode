/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct LN {
  int val;
  LN *l;
  LN *r;
  LN() : val(0), l(nullptr), r(nullptr) {}
  LN(int x) : val(x), l(nullptr), r(nullptr) {}
};

class Solution {
 public:
  int findDuplicate(const vector<int>& nums) {
    LN *head = NULL;
    LN *parent = NULL;

    for (const auto& n : nums) {
      LN *new_node = new LN(n);
      if (head == NULL) {
        head = new_node;
      } else {
        parent = head;
        while (true) {
          if (n > parent->val) {
            if (parent->r == NULL) {
              parent->r = new_node;
              break;
            } else {
              parent = parent->r;
            }
          } else if (n < parent->val) {
            if (parent->l == NULL) {
              parent->l = new_node;
              break;
            } else {
              parent = parent->l;
            }
          } else {
            return n;
          }
        }
      }
    }
    return -1;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  vector<int> nums;
  int ret;

  // example 1
  nums.clear();
  nums = {1, 3, 4, 2, 2};
  ret = s.findDuplicate(nums);
  print_ret(ret);

  // example 2
  nums.clear();
  nums = {3, 1, 3, 4, 2};
  ret = s.findDuplicate(nums);
  print_ret(ret);

  return 0;
}
