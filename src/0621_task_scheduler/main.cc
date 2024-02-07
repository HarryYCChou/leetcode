/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::stack;

class Solution {
 public:
  int leastInterval(const vector<char>& tasks, const int& n) {
    priority_queue<int> pq;
    stack<int> stk;
    int t[26];
    for (int i = 0; i < 26; i++) {
      t[i] = 0;
    }
    for (const auto& c : tasks) {
      t[c - 'A'] += 1;
    }

    for (int i = 0; i < 26; i++) {
      if (t[i] != 0) pq.push(t[i]);
    }

    int wait = 0;
    int ret = 0;
    while (!pq.empty() || !stk.empty()) {
      if (wait == 0) {
        while (!stk.empty()) {
          pq.push(stk.top());
          stk.pop();
        }
        wait = n + 1;
        continue;
      }

      if (!pq.empty()) {
        int tmp = pq.top();
        if (tmp != 1) {
          stk.push(tmp-1);
        }
        pq.pop();
      }
      wait -= 1;
      ret += 1;
    }
    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<char> tasks;

  // example 1
  tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  ret = s.leastInterval(tasks, 2);
  print_ret(ret);

  // example 2
  tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  ret = s.leastInterval(tasks, 0);
  print_ret(ret);

  // example 3
  tasks = {'A', 'A', 'A', 'A', 'A', 'A',
           'B', 'C', 'D', 'E', 'F', 'G'};
  ret = s.leastInterval(tasks, 2);
  print_ret(ret);

  return 0;
}
