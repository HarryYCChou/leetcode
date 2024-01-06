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
using std::to_string;

class Solution {
 public:
  string encode(const vector<string>& strs) {
    if (strs.size() == 0) return "";

    string encode_str;
    for (const auto& s : strs) {
      int len = s.length();

      encode_str += to_string(len);
      encode_str += "|";
      encode_str += s;
    }

    return encode_str;
  }

  vector<string> decode(const string& s) {

    vector<string> decode_str;
    if (s == "") return decode_str;

    string len;
    int i = 0;
    while (i<s.length()) {
      if (s[i] != '|') {
        len += s[i];
      } else {
        int s_len = stoi(len);
        decode_str.push_back(s.substr(i+1, s_len));
        // shift length of substr length
        i += s_len;
        // clean len
        len = "";
      }
      i++;
    }

    return decode_str;
  }
};

void print_ret(const vector<string>& ret) {
  for (const auto& s : ret) {
    cout << s << ",";
  }
  cout << endl;
}

int main() {
  Solution s;

  string ret;

  // example 1
  ret = s.encode({"neet","code","love","you"});
  cout << "encode: " << ret << endl;
  print_ret(s.decode(ret));

  // example 2
  ret = s.encode({"we","say",":","yes"});
  cout << "encode: " << ret << endl;
  print_ret(s.decode(ret));

  return 0;
}
