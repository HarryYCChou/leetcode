/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>

using std::cout;
using std::endl;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::make_pair;

class Trie;

class Trie {
 public:
  unordered_map<char, Trie*> map;
  unordered_set<char> s;    // for end
  Trie() {

  }
  
  void insert(string word) {
    char c = word[0];
    if (map.find(c) == map.end()) {
      Trie* t = new Trie;
      map.insert(make_pair(c, t));
      //map[c] = t;
    }
    if (word.size() > 1) {
      map[c]->insert(word.substr(1, word.size() - 1));
    } else {
      s.insert(c);
    }
  }

  // type == 0, all match 
  // type == 1, prefix match
  bool search_all(string word, const int& type) {
    char c = word[0];
    if (map.find(c) != map.end()) {
      if (word.size() > 1) {
        return map[c]->search_all(word.substr(1, word.size() - 1), type);
      } else {
        if (type == 0) return (s.find(c) != s.end());
        return true;
      }
    }
    return false;
  }

  bool search(string word) {
    return search_all(word, 0);
  }
  
  bool startsWith(const string& prefix) {
    return search_all(prefix, 1);
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
  Trie t;
  bool ret;

  // example 1
  t.insert("apple");
  print_ret(t.search("apple"));
  print_ret(t.search("app"));
  print_ret(t.startsWith("app"));
  t.insert("app");
  print_ret(t.search("app"));

  // example 2

  // example 3

  return 0;
}
