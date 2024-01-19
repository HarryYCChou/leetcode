/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using std::cout;
using std::endl;
using std::unordered_map;
using std::stack;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *ret = NULL, * ret_cur = NULL;
    ListNode *cur1 = l1, *cur2 = l2;
    int next_digit = 0;

    while (cur1 != NULL || cur2 != NULL || next_digit > 0) {
      int n1, n2;
      if (cur1 == NULL) {
        n1 = 0;
      } else {
        n1 = cur1->val;
        cur1 = cur1->next;
      }
      if (cur2 == NULL) {
        n2 = 0;
      } else {
        n2 = cur2->val;
        cur2 = cur2->next;
      }
      ListNode* new_digit = new ListNode((n1 + n2 + next_digit) % 10);
      next_digit = (n1 + n2 + next_digit) / 10;
      if (ret == NULL) {
        ret = new_digit;
        ret_cur = new_digit;
      } else {
        ret_cur->next = new_digit;
        ret_cur = ret_cur->next;
      }
    }

    return ret;
  }
};

void print_ret(ListNode* ret) {
  ListNode* cur = ret;

  while (cur != NULL) {
    cout << cur->val;
    cur = cur->next;
  }
  cout << endl;
}

int main() {
  Solution s;
  ListNode *l1, *l2;
  ListNode *ret;
  // example 1
  l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
  ret = s.addTwoNumbers(l1, l2);
  print_ret(ret);

  // example 2
  l1 = new ListNode(0);
  l2 = new ListNode(0);
  ret = s.addTwoNumbers(l1, l2);
  print_ret(ret);

  // example 3
  l1 = new ListNode(9, new ListNode(9, new ListNode(9,
            new ListNode(9, new ListNode(9, new ListNode(9,
            new ListNode(9)))))));
  l2 = new ListNode(9, new ListNode(9,
          new ListNode(9, new ListNode(9))));
  ret = s.addTwoNumbers(l1, l2);
  print_ret(ret);

  return 0;
}
