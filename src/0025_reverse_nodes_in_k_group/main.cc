/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_ret(ListNode* ret) {
  ListNode* cur = ret;
  cout << "[";
  while (cur != nullptr) {
    cout << cur->val << ", ";
    cur = cur->next;
  }
  cout << "]" << endl;
}

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* new_head = nullptr;
    ListNode* tail = nullptr;
    ListNode* next_head = nullptr;
    ListNode* cur = head;

    while (checkValid(cur, k)) {
      next_head = stk.top()->next;
      while (!stk.empty()) {
        if (new_head == nullptr) {
          new_head = stk.top();
          tail = new_head;
        } else {
          tail->next = stk.top();
          tail = tail->next;
        }
        stk.pop();
      }
      tail->next = next_head;
      cur = next_head;
    }
    return new_head;
  }

 private:
  stack<ListNode*> stk;
  bool checkValid(ListNode* head, int k) {
    ListNode* cur = head;
    for (int i = 0; i < k; i++) {
      if (cur != nullptr) {
        stk.push(cur);
        cur = cur->next;
      } else {
        return false;
      }
    }
    return true;
  }
};


int main() {
  Solution s;
  ListNode* head;
  ListNode* ret;

  // example 1
  head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4,
                    new ListNode(5)))));
  ret = s.reverseKGroup(head, 2);
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
