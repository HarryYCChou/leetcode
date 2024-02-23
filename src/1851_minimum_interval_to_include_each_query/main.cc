/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::unordered_map;
using std::pair;
using std::priority_queue;
using std::greater;

class Solution {
 public:
  vector<int> minInterval(vector<vector<int>> intervals, vector<int> queries) {
    vector<int> ques = queries;
    unordered_map<int, int> ans;
    vector<int> ret;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                  greater<pair<int, int>>> pq;

    sort(intervals.begin(), intervals.end());
    sort(ques.begin(), ques.end());

    int i = 0;

    for (const auto & q : ques) {
      while (i < intervals.size() && intervals[i][0] <= q) {
        pq.push(pair(intervals[i][1] - intervals[i][0] + 1, intervals[i][1]));
        i++;
      }

      while (!pq.empty() && pq.top().second < q) {
        pq.pop();
      }

      if (pq.empty()) {
        ans[q] = -1;
      } else {
        ans[q] = pq.top().first;
      }
    }

    for (const auto & q : queries) {
      ret.push_back(ans[q]);
    }

    return ret;
  }
};

void print_ret(const vector<int>& ret) {
  cout << "[";
  for (const auto & n : ret) {
    cout << n << ", ";
  }
  cout << "]" << endl;
}

int main() {
  Solution s;

  vector<int> ret;
  vector<vector<int>> intervals;
  vector<int> queries;

  // example 1
  intervals = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
  queries = {2, 3, 4, 5};
  ret = s.minInterval(intervals, queries);
  print_ret(ret);

  // example 2
  intervals = {{2, 3}, {2, 5}, {1, 8}, {20, 25}};
  queries = {2, 19, 5, 22};
  ret = s.minInterval(intervals, queries);
  print_ret(ret);

  // example 3

  return 0;
}
