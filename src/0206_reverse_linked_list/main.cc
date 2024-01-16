/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    ListNode* cur = head;
    while (cur != NULL) {
      ListNode* tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
    }
    return pre;
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
  ListNode* a = new ListNode();
  a->val = 5;
  ListNode* b = new ListNode();
  b->val = 4;
  b->next = a;
  ListNode* c = new ListNode();
  c->val = 3;
  c->next = b;
  ListNode* d = new ListNode();
  d->val = 2;
  d->next = c;
  ListNode* e = new ListNode();
  e->val = 1;
  e->next = d;
  ListNode* ret;

  ListNode* ex2_2 = new ListNode(2);
  ListNode* ex2 = new ListNode(1, ex2_2);

  // example 1
  ret = s.reverseList(e);
  print_ret(ret);

  // example 2
  ret = s.reverseList(ex2);
  print_ret(ret);

  return 0;
}
