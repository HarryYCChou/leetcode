/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::string;
using std::pair;
using std::make_pair;

class TimeMap {
 public:
  // key, vector<value, timestamp>
  unordered_map<string, vector<pair<string, int>>> map;

  TimeMap() {}

  void set(const string& key, const string& value, const int& timestamp) {
    map[key].push_back(make_pair(value, timestamp));
  }

  string get(const string& key, const int& timestamp) {
    // note: copy vector below is time consuming
    // vector<pair<string, int>> vec = map[key];

    if (map[key].size() == 0) return "";

    int left = 0, right = map[key].size() - 1;
    int mid;
    string ret;

    while (left <= right) {
      mid = left + (right - left) / 2;

      // check boundary
      if (map[key][right].second < timestamp) return map[key][right].first;

      if (map[key][mid].second == timestamp) return map[key][mid].first;
      if (map[key][mid].second > timestamp) {
        right = mid - 1;
      } else {
        ret = map[key][mid].first;
        left = mid + 1;
      }
    }

    return ret;
  }
};

void print_ret(const string& ret) {
  cout << ret << endl;
}

int main() {
  string ret;

  // example 1
  TimeMap timeMap;                // = new TimeMap();
  timeMap.set("foo", "bar", 1);   // store the key "foo" and value "bar" along
                                  // with timestamp = 1.
  ret = timeMap.get("foo", 1);    // return "bar"
  print_ret(ret);
  ret = timeMap.get("foo", 3);    // return "bar", since there is no value
                                  // corresponding to foo at timestamp 3 and
                                  // timestamp 2, then the only value is at
                                  // timestamp 1 is "bar".
  print_ret(ret);
  timeMap.set("foo", "bar2", 4);  // store the key "foo" and value "bar2" along
                                  // with timestamp = 4.
  ret = timeMap.get("foo", 4);    // return "bar2"
  print_ret(ret);
  ret = timeMap.get("foo", 5);    // return "bar2"
  print_ret(ret);

  return 0;
}
