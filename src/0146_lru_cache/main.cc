/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <unordered_map>
#include <utility>

using std::cout;
using std::endl;
using std::unordered_map;
using std::pair;

struct LN {
  int key;
  int val;
  LN *prev;
  LN *next;
  LN() : key(0), val(0), prev(nullptr), next(nullptr) {}
  LN(int x, int y) : key(x), val(y), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 public:
  LRUCache(int capacity) {
    cap = capacity;
  }

  int get(int key) {
    if (map.find(key) != map.end()) {
      LN* node = map[key];
      remove(node);
      insert(node);
      return node->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (map.find(key) != map.end()) {
      LN* node = map[key];
      node->val = value;
      remove(node);
      insert(node);
    } else {
      LN* node = new LN(key, value);
      insert(node);
      map[key] = node;
    }
  }

 private:
  int cap = 0;
  int count = 0;
  LN *head = nullptr;
  LN *tail = nullptr;
  unordered_map<int, LN*> map;

  void insert(LN* node) {
    node->prev = tail;
    node->next = nullptr;
    if (head == nullptr) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      node->prev = tail;
      tail = node;
    }
    count++;
    if (count > cap) {
      LN* tmp = head;
      map.erase(head->key);
      remove(head);
      delete tmp;
    }
  }

  void remove(LN* node) {
    if (node == nullptr) return;

    if (node == head) {
      head = head->next;
      if (head != nullptr) {
        head->prev = nullptr;
      } else {
        tail = nullptr;
      }
    } else if (node == tail) {
      tail = tail->prev;
      tail->next = nullptr;
    } else {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
    count--;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  // example 1
  LRUCache *lRUCache = new LRUCache(2);
  lRUCache->put(1, 1);          // cache is {1=1}
  lRUCache->put(2, 2);          // cache is {1=1, 2=2}
  print_ret(lRUCache->get(1));  // return 1
  lRUCache->put(3, 3);          // cache is {1=1, 3=3}
  print_ret(lRUCache->get(2));  // returns -1 (not found)
  lRUCache->put(4, 4);          // cache is {4=4, 3=3}
  print_ret(lRUCache->get(1));  // return -1 (not found)
  print_ret(lRUCache->get(3));  // return 3
  print_ret(lRUCache->get(4));  // return 4

  // example 2
  lRUCache = new LRUCache(2);
  lRUCache->put(1, 0);          // cache is {1=0}
  lRUCache->put(2, 2);          // cache is {1=0, 2=2}
  print_ret(lRUCache->get(1));  // return 0
  lRUCache->put(3, 3);          // cache is {1=1, 3=3}
  print_ret(lRUCache->get(2));  // returns -1 (not found)
  lRUCache->put(4, 4);          // cache is {4=4, 3=3}
  print_ret(lRUCache->get(1));  // return -1 (not found)
  print_ret(lRUCache->get(3));    // return 3
  print_ret(lRUCache->get(4));    // return 4

  return 0;
}
