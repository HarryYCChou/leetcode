/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <unordered_map>
#include <utility>

using std::cout;
using std::endl;
using std::unordered_map;
using std::make_pair;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  explicit Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  unordered_map<Node*, Node*> map;
  Node* copyRandomList(Node* head) {
    Node* new_head = nullptr;
    new_head = copySingleNode(head);

    return new_head;
  }

  Node* copySingleNode2(Node* node) {
    if (node == nullptr) return nullptr;

    Node* c = new Node(node->val);
    map.insert(make_pair(node, c));

    // copy next
    if (map.find(node->next) != map.end()) {
      c->next = map[node->next];
    } else {
      Node* next = copySingleNode(node->next);
      c->next = next;
    }
    // copy random
    if (map.find(node->random) != map.end()) {
      c->random = map[node->random];
    } else {
      Node* r = copySingleNode(node->random);
      c->random = r;
    }
    return c;
  }

  Node* copyRandomList(Node* head) {
    Node* cur = head;
    Node* cur2 = NULL;  // for copied list
    Node* new_head = NULL;
    unordered_map<Node*, Node*> map;

    // creating mapping table
    // give new list value and next pointer
    while (cur != NULL) {
      Node* tmp = new Node(cur->val);
      map.insert(make_pair(cur, tmp));  // create mapping table

      cur = cur->next;
      if (new_head == NULL) {
        new_head = tmp;
      } else {
        cur2->next = tmp;
      }
      cur2 = tmp;
    }

    // give new list corresponding random pointer
    cur = head;
    cur2 = new_head;
    while (cur != NULL) {
      if (cur->random != NULL) {
        cur2->random = map[cur->random];
      }
      cur = cur->next;
      cur2 = cur2->next;
    }

    return new_head;
  }
};

int main() {
  Solution s;

  // example 1

  // example 2

  // example 3

  return 0;
}
