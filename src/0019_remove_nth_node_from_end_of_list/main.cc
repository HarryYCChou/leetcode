/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    stack<ListNode*> stk;
    ListNode* cur = head;

    int count = 0;
    while (cur != NULL) {
      stk.push(cur);
      cur = cur->next;
    }

    count = stk.size();

    for (int i = 0; i < n; i++) {
      stk.pop();
    }

    if (stk.empty()) {
      return head->next;
    } else {
      stk.top()->next = stk.top()->next->next;
    }

    return head;
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
                    new ListNode(3, new ListNode(4, new ListNode(5)))));

  // example 1
  head = s.removeNthFromEnd(head, 2);
  print_ret(head);

  // example 2
  head = new ListNode(1);
  head = s.removeNthFromEnd(head, 1);
  print_ret(head);

  // example 3
  head = new ListNode(1, new ListNode(2));
  head = s.removeNthFromEnd(head, 1);
  print_ret(head);

  return 0;
}
