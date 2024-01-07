/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
 public:
  bool isPalindrome(const string& s) {
    // sort string
    // 1. remove non-alphanumeric
    // 2. uppercase to lowercase
    string ss;  // ss is sorted string
    for (const auto& c : s) {
      if (c >= 'A' && c <= 'Z') {
        // upper to lower
        ss += (static_cast<char>(c-'A'+'a'));
      } else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
        // 0~9 or a~z
        ss += c;
      }
      // skip other non-alphanumeric
    }

    // check empty
    if (s == "") return true;

    // check palindromue
    int index_a = 0;
    int index_b = ss.length()-1;

    while (index_a < index_b) {
      if (ss[index_a] == ss[index_b]) {
        index_a++;
        index_b--;
      } else {
        return false;
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
  string str;
  bool ret;

  // example 1
  str = "A man, a plan, a canal: Panama";
  ret = s.isPalindrome(str);
  print_ret(ret);

  // example 2
  str = "race a car";
  ret = s.isPalindrome(str);
  print_ret(ret);

  // example 3
  str = " ";
  ret = s.isPalindrome(str);
  print_ret(ret);

  return 0;
}
