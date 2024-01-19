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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ret = NULL;
    ListNode* pre = NULL;

    while (list1 != NULL || list2 != NULL) {
      int smaller;
      ListNode* cur = new ListNode();
      if (list1 == NULL) {
        cur->val = list2->val;
        list2 = list2->next;
      } else if (list2 == NULL) {
        cur->val = list1->val;
        list1 = list1->next;
      } else {
        if (list1->val > list2->val) {
          cur->val = list2->val;
          list2 = list2->next;
        } else {
          cur->val = list1->val;
          list1 = list1->next;
        }
      }

      if (ret == NULL) {
        ret = cur;
        pre = cur;
      } else {
        pre->next = cur;
        pre = cur;
      }
    }

    return ret;
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
  ListNode* ret;
  ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(3)));
  ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

  // example 1
  list1 = new ListNode(1, new ListNode(2, new ListNode(3)));
  list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
  ret = s.mergeTwoLists(list1, list2);
  print_ret(ret);

  // example 2
  list1 = NULL;
  list2 = NULL;
  ret = s.mergeTwoLists(list1, list2);
  print_ret(ret);

  // example 3
  list2 = new ListNode(0);
  ret = s.mergeTwoLists(list1, list2);
  print_ret(ret);
  return 0;
}
