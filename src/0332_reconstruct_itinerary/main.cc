/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::sort;
using std::unordered_set;

class Solution {
 public:
  vector<string> ret;
  unordered_set<string> traveled;

  vector<string> findItinerary(const vector<vector<string>>& tickets) {
    unordered_map<string, vector<string>> station;
    unordered_map<string, int> ticket_used;

    int goal = tickets.size() + 1;
    ret.clear();
    for (const auto& v : tickets) {
      station[v[0]].push_back(v[1]);
      ticket_used[v[0]+v[1]]++;
    }

    // sort
    for (auto& pair : station) {
      sort(pair.second.begin(), pair.second.end());
    }

    vector<string> cur_ret;
    search(cur_ret, station, ticket_used, "JFK", goal);
    return ret;
  }

  bool search(vector<string>& cur_ret,
              unordered_map<string, vector<string>>& station,
              unordered_map<string, int>& ticket_used,
              const string& start, const int& goal) {
    cur_ret.push_back(start);

    if (cur_ret.size() == goal) {
      ret = cur_ret;
      cur_ret.pop_back();
      return true;
    }

    // for (const auto& s : cur_ret) {
    //   cout << s << " - ";
    // }
    // cout << endl;

    for (const auto& next : station[start]) {
      string str;
      for (const auto& s : cur_ret) {
        str += s;
      }
      if (ticket_used[start + next] > 0
          && traveled.find(str + next) == traveled.end()) {
        ticket_used[start + next]--;
        if (search(cur_ret, station, ticket_used, next, goal)) return true;
        ticket_used[start + next]++;
        traveled.insert(str + next);
      }
    }
    cur_ret.pop_back();

    return false;
  }
};


void print_ret(const vector<string>& ret) {
  cout << "[";
  for (const auto& s : ret) {
    cout << s << ", ";
  }
  cout << "]" << endl;
}

int main() {
  Solution s;

  vector<string> ret;
  vector<vector<string>> tickets;

  // example 1
  tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
  ret = s.findItinerary(tickets);
  print_ret(ret);

  // example 2
  tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"},
              {"ATL", "JFK"}, {"ATL", "SFO"}};
  ret = s.findItinerary(tickets);
  print_ret(ret);

  // example 3
  tickets = {{"EZE", "AXA"}, {"TIA", "ANU"}, {"ANU", "JFK"}, {"JFK", "ANU"},
            {"ANU", "EZE"}, {"TIA", "ANU"}, {"AXA", "TIA"}, {"TIA", "JFK"},
            {"ANU", "TIA"}, {"JFK", "TIA"}};
  ret = s.findItinerary(tickets);
  print_ret(ret);

  return 0;
}
