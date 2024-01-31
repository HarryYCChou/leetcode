/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
 public:
  int len;
  vector<vector<string>> solveNQueens(int n) {
    len = n;
    vector<vector<string>> ret;
    vector<string> curr;
    vector<vector<int>> occupied;
    int count = 0;
    string tmp;
    vector<int> tmp_o;

    // create a empty result
    for (int i = 0; i < n; i++) {
      tmp += ".";
      tmp_o.push_back(0);
    }

    for (int j = 0; j < n; j++) {
      curr.push_back(tmp);
      occupied.push_back(tmp_o);
    }

    for (int i = 0; i < n*n; i++) {
      solveByPoint(i, occupied, count, curr, ret);
    }

    return ret;
  }

 private:
  void solveByPoint(int pos, vector<vector<int>>& occupied, int& count,
            vector<string>& curr, vector<vector<string>>& ret) {
    int n = occupied.size();
    int i = pos / n;
    int j = pos % n;

    // can not occupied
    if (occupied[i][j] > 0) return;

    // full
    if (count + 1 >= curr.size()) {
      curr[i][j] = 'Q';
      ret.push_back(curr);
      curr[i][j] = '.';
      return;
    }
    // not full
    count++;
    curr[i][j] = 'Q';
    setOccupied(pos, occupied, 1);
    for (int start = pos + 1; start < curr.size()*curr.size(); start++) {
      solveByPoint(start, occupied, count, curr, ret);
    }
    setOccupied(pos, occupied, -1);
    curr[i][j] = '.';
    count--;
  }

  void setOccupied(int pos, vector<vector<int>>& occupied, int val) {
    int i, j;
    int n = occupied.size();

    // set current position
    getPos(pos, i, j);
    occupied[i][j] += val;

    // left-top
    getPos(pos, i, j);
    while (true) {
      i--;
      j--;
      if (i < 0 || j < 0 || i >= n || j >=n) break;
      occupied[i][j] += val;
    }
    // top
    getPos(pos, i, j);
    while (true) {
      i--;
      if (i < 0 || j < 0 || i >= n || j >=n) break;
      occupied[i][j] += val;
    }
    // right-top
    getPos(pos, i, j);
    while (true) {
      i--;
      j++;
      if (i < 0 || j < 0 || i >= n || j >=n) break;
      occupied[i][j] += val;
    }
    // left
    getPos(pos, i, j);
    while (true) {
      j--;
      if (i < 0 || j < 0 || i >= n || j >=n) break;
      occupied[i][j] += val;
    }
    // right
    getPos(pos, i, j);
    while (true) {
      j++;
      if (i < 0 || j < 0 || i >= n || j >=n) break;
      occupied[i][j] += val;
    }
    // left-down
    getPos(pos, i, j);
    while (true) {
      i++;
      j--;
      if (i < 0 || j < 0 || i >= n || j >=n) break;
      occupied[i][j] += val;
    }
    // down
    getPos(pos, i, j);
    while (true) {
      i++;
      if (i < 0 || j < 0 || i >= n || j >=n) break;
      occupied[i][j] += val;
    }
    // right-down
    getPos(pos, i, j);
    while (true) {
      i++;
      j++;
      if (i < 0 || j < 0 || i >= n || j >=n) break;
      occupied[i][j] += val;
    }
  }

  void getPos(int pos, int& i, int& j) {
    i = pos / len;
    j = pos % len;
  }
};

void print_ret(const vector<vector<string>>& ret) {
  for (const auto& v : ret) {
    for (const auto s : v) {
      cout << s << endl;
    }
    cout << "------" << endl;
  }
}

int main() {
  Solution s;

  vector<vector<string>> ret;

  // example 1
  ret = s.solveNQueens(4);
  print_ret(ret);

  // example 2
  ret = s.solveNQueens(1);
  print_ret(ret);

  // example 3
  ret = s.solveNQueens(2);
  print_ret(ret);

  return 0;
}
