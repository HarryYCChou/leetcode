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
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  void reorderList(ListNode* head) {
    ListNode* cur = head;
    while (cur->next != NULL) {
      ListNode* pre_end = NULL;
      ListNode* end = cur->next;
      while (end->next != NULL) {
        pre_end = end;
        end = end->next;
      }

      if (pre_end == NULL) {
        // the list is on the end
        cur = end;
      } else {
        pre_end->next = NULL;
        end->next = cur->next;
        cur->next = end;
        cur = end->next;
      }
    }
  }
};

void print_ret(ListNode* ret) {
  ListNode* tmp = ret;
  while (tmp != NULL) {
    cout << tmp->val << ", ";
    tmp = tmp->next;
  }
  cout << endl;
}

int main() {
  Solution s;
  ListNode* head = new ListNode(1, new ListNode(2,
                    new ListNode(3, new ListNode(4))));

  // example 1
  s.reorderList(head);
  print_ret(head);

  // example 2
  head = new ListNode(1, new ListNode(2, new ListNode(3,
          new ListNode(4, new ListNode(5)))));
  s.reorderList(head);
  print_ret(head);

  // example 3

  return 0;
}
