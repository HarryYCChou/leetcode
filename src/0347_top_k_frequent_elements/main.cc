/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::pair;
using std::sort;

class Solution {
 public:
  vector<int> topKFrequent(const vector<int>& nums, int k) {
    // map<num, times>
    unordered_map<int, int> map;
    for (const auto& num : nums) {
      map[num] += 1;
    }

    // mapping to vector for sorting
    vector<pair<int, int>> v(map.begin(), map.end());
    sort(v.begin(), v.end(),
              [](const auto& lhr, const auto& rhr) {
                return ((lhr.second) > (rhr.second));
              });

    vector<int> ret;
    for (int i = 0; i < k; i++) {
      ret.push_back(v[i].first);
    }

    return ret;
  }
};

void print_ret(const vector<int>& ret) {
  for (const auto& n : ret) {
    cout << n << " ";
  }
  cout << endl;
}

int main() {
  Solution s;
  vector<int> nv;
  vector<int> ret;

  // example 1
  nv.clear();
  nv = {1, 1, 1, 2, 2, 3};
  ret = s.topKFrequent(nv, 2);
  print_ret(ret);

  // example 2
  nv.clear();
  nv = {1};
  ret = s.topKFrequent(nv, 1);
  print_ret(ret);

  return 0;
}
