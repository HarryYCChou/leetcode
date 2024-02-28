/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

class Solution {
 public:
  bool mergeTriplets(const vector<vector<int>>& triplets,
                     const vector<int>& target) {
    bool valid[3]{false};

    for (int i = 0; i < triplets.size(); i++) {
      vector<int> v = triplets[i];
      if (v[0] > target[0] ||
        v[1] > target[1] ||
        v[2] > target[2]) {
        continue;
      }
      if (v[0] == target[0]) valid[0] = true;
      if (v[1] == target[1]) valid[1] = true;
      if (v[2] == target[2]) valid[2] = true;
      if (valid[0] && valid[1] && valid[2]) return true;
    }
    return false;
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

  bool ret;
  vector<vector<int>> triplets;
  vector<int> target;

  // example 1
  triplets = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}, {2, 7, 5}};
  target = {2, 7, 5};
  ret = s.mergeTriplets(triplets, target);
  print_ret(ret);

  // example 2
  triplets = {{3, 4, 5}, {4, 5, 6}};
  target = {3, 2, 5};
  ret = s.mergeTriplets(triplets, target);
  print_ret(ret);

  // example 3
  triplets = {{2, 5, 3}, {2, 3, 4}, {1, 2, 5}, {5, 2, 3}};
  target = {5, 5, 5};
  ret = s.mergeTriplets(triplets, target);
  print_ret(ret);

  return 0;
}
