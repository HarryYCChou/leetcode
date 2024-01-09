/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::sort;

class Solution {
 public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    // pair
    // pair<position, time>
    vector<pair<int, double>> pt;
    int len = position.size();

    for (int i = 0 ; i < len; i++) {
      pt.push_back({position[i], (target-position[i])/(double)speed[i]});
    }

    // sort
    sort(pt.begin(), pt.end());

    // from back due to heightest position can be catched
    double slowest_time = pt[len-1].second;
    int fleet = 1;
    for (int i = len-2; i >=0 ; i--) {
      if (pt[i].second > slowest_time) {
        slowest_time = pt[i].second;
        fleet++;
      }
    }

    return fleet;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  int ret;
  vector<int> position;
  vector<int> speed;


  // example 1
  position.clear();
  speed.clear();
  position = {10, 8, 0, 5, 3};
  speed = {2, 4, 1, 1, 3};
  ret = s.carFleet(12, position, speed);
  print_ret(ret);

  // example 2
  position.clear();
  speed.clear();
  position = {3};
  speed = {3};
  ret = s.carFleet(10, position, speed);
  print_ret(ret);

  // example 3
  position.clear();
  speed.clear();
  position = {0, 2, 4};
  speed = {4, 2, 1};
  ret = s.carFleet(100, position, speed);
  print_ret(ret);

  return 0;
}
