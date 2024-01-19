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

void print_ret(ListNode* ret) {
  ListNode *cur = ret;
  cout << "[";
  while (cur != nullptr) {
    cout << cur->val;
    cur = cur->next;
    if (cur != nullptr) cout << ", ";
  }
  cout << "]" << endl;
}

class Solution {
 public:
  ListNode* mergeKLists(const vector<ListNode*>& lists) {
    if (lists.size() == 0) return nullptr;
    if (lists.size() == 1) return lists[0];
    ListNode* head1 = nullptr;
    ListNode* head2 = nullptr;

    for (int i = 1; i < lists.size(); i++) {
      cout << "i:" << i << endl;
      if (i == 1) head1 = lists[0];
      head2 = lists[i];
      head1 = mergeTwo(head1, head2);
    }
    return head1;
  }

 private:
  ListNode* mergeTwo(ListNode* node1, ListNode* node2) {
    if (node1 == nullptr && node2 == nullptr) return nullptr;
    if (node1 == nullptr) return node2;
    if (node2 == nullptr) return node1;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode *cur1 = node1, *cur2 = node2;
    while (cur1 != nullptr && cur2 != nullptr) {
      if (cur1->val < cur2->val) {
        if (head == nullptr) {
          head = cur1;
          tail = cur1;
          cur1 = cur1->next;
        } else {
          tail->next = cur1;
          cur1 = cur1->next;
          tail = tail->next;
        }
      } else {
        if (head == nullptr) {
          head = cur2;
          tail = cur2;
          cur2 = cur2->next;
        } else {
          tail->next = cur2;
          cur2 = cur2->next;
          tail = tail->next;
        }
      }
    }
    if (cur1 != nullptr) tail->next = cur1;
    if (cur2 != nullptr) tail->next = cur2;

    return head;
  }
};

int main() {
  Solution s;
  vector<ListNode*> lists;
  ListNode* ret;

  // example 1
  lists = {new ListNode(1, new ListNode(4, new ListNode(5))), new ListNode(1,
          new ListNode(3, new ListNode(4))), new ListNode(2, new ListNode(6))};
  ret = s.mergeKLists(lists);
  print_ret(ret);

  // example 2
  lists = {new ListNode(1), new ListNode(2)};
  ret = s.mergeKLists(lists);
  print_ret(ret);

  // example 3

  return 0;
}
