/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::vector;
using std::map;

class Solution {
 public:
  bool isNStraightHand(const vector<int>& hand, const int& groupSize) {
    map<int, int> m;

    if (hand.size() % groupSize != 0) return false;

    for (const auto& n : hand) {
      m[n]++;
    }

    while (!m.empty()) {
      int n = m.begin()->first;
      int count = m.begin()->second;

      for (int i = 0; i < groupSize; i++) {
        if (m[n + i] < count) return false;
        m[n + i] -= count;
        if (m[n + i] <= 0) m.erase(n + i);
      }
    }
    return true;
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

  vector<int> hand;
  bool ret;

  // example 1
  hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
  ret = s.isNStraightHand(hand, 3);
  print_ret(ret);

  // example 2
  hand = {1, 2, 3, 4, 5};
  ret = s.isNStraightHand(hand, 4);
  print_ret(ret);

  return 0;
}
