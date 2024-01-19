/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  bool hasCycle2(ListNode *head) {
    ListNode* trap = new ListNode();
    ListNode* cur = head;
    ListNode* prev = head;
    while (cur != NULL) {
      if (cur == trap) return true;
      prev = cur;
      cur = cur->next;
      prev->next = trap;
    }
    return false;
  }

  bool hasCycle(ListNode *head) {
    ListNode* cur = head;
    int count = 0;
    while (cur != NULL) {
      if (count++ > 10000) return true;
      cur = cur->next;
    }
    return false;
  }
};

void print_ret(const bool& ret) {
  if (ret) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}

int main() {
  Solution s;
  ListNode *l1;
  bool ret;

  // example 1
  l1 = new ListNode(3, new ListNode(2, new ListNode(0, new ListNode(-4))));
  ret = s.hasCycle(l1);
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
