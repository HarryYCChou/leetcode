/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::max;

class Solution {
 public:
  double findMedianSortedArrays(const vector<int>& nums1,
                                const vector<int>& nums2) {
    int n_nums1 = nums1.size();
    int n_nums2 = nums2.size();

    // make sure n_nums1 is smaller
    if (n_nums2 < n_nums1) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int n_mid = (n_nums1 + n_nums2) / 2;
    int il = 0, ir = n_nums1, imid;
    int left1, left2, right1, right2;  // value

    double ret = 0.0;

    while (il <= ir) {
      imid = il + (ir - il) / 2;

      left1 = (imid > 0) ? nums1[imid - 1] : INT_MIN;
      right1 = (imid < n_nums1) ? nums1[imid] : INT_MAX;
      left2 = ((n_mid - imid) > 0) ? nums2[n_mid - imid - 1] : INT_MIN;
      right2 = ((n_mid - imid) < n_nums2) ? nums2[n_mid - imid] : INT_MAX;

      // partition is correct
      if (left1 <= right2 && left2 <= right1) {
        // even
        if ((n_nums1 + n_nums2) % 2 == 0) {
          ret = static_cast<double>(max(left1, left2) +
                                    min(right1, right2)) / 2;
        } else {
          // odd
          ret = static_cast<double>(min(right1, right2));
        }

        break;
      }

      // move il and ir
      if (left1 > right2) {
        ir = imid - 1;
      } else if (left2 > right1) {
        il = imid + 1;
      }
    }

    return ret;
  }
};

void print_ret(const double& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;
  double ret;
  vector<int> nums1, nums2;

  // example 1
  nums1.clear();
  nums2.clear();
  nums1 = {1, 3};
  nums2 = {2};
  ret = s.findMedianSortedArrays(nums1, nums2);
  print_ret(ret);

  // example 2
  nums1.clear();
  nums2.clear();
  nums1 = {1, 2};
  nums2 = {3, 4};
  ret = s.findMedianSortedArrays(nums1, nums2);
  print_ret(ret);

  return 0;
}
