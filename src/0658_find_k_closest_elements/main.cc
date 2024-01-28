/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
 public:
  vector<int> findClosestElements(const vector<int>& arr,
                                  const int& k, const int& x) {
    int left = 0;
    int right = arr.size()-k;
    int mid;

    while (left < right) {
      mid = left + (right - left) / 2;
      if (arr[mid] - x >= x - arr[mid+k]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    vector<int> ret = (arr.begin() + mid, arr.begin() + mid + k);
    return vector<int>(arr.begin() + mid, arr.begin() + mid + k);
  }
};

void print_ret(const vector<int>& ret) {
  for (const auto& n : ret) {
    cout << n << ",";
  }
  cout << endl;
}

int main() {
  Solution s;

  std::vector<int> ret;
  std::vector<int> arr;

  // example 1
  arr = {1, 2, 3, 4, 5};
  ret = s.findClosestElements(arr, 4, 3);
  print_ret(ret);

  // example 2
  arr = {1};
  ret = s.findClosestElements(arr, 1, 1);
  print_ret(ret);

  // example 3

  return 0;
}
