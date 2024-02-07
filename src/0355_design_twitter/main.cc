/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::unordered_set;

class Post {
 public:
  Post(int userId, int tweetId) {
    user_id = userId;
    tweet_id = tweetId;
  }
  Post *next = nullptr;
  int user_id = -1;
  int tweet_id = -1;
};

class User {
 public:
  unordered_set<int> follower;
  explicit User(int id) {
    follower.insert(id);
  }
};

class Twitter {
 public:
  Post *head = nullptr;
  unordered_map<int, User*> map;

  Twitter() {}

  void postTweet(int userId, int tweetId) {
    Post *post = new Post(userId, tweetId);
    post->next = head;
    head = post;
    if (map[userId] == nullptr) {
      // create user
      User *u = new User(userId);
      map[userId] = u;
    }
  }

  vector<int> getNewsFeed(int userId) {
    vector<int> ret;
    Post *cur = head;
    int count = 0;
    User *u = nullptr;
    while (cur != nullptr && count < 10) {
      u = map[cur->user_id];
      if (u->follower.find(userId) != u->follower.end()) {
        ret.push_back(cur->tweet_id);
        count++;
      }
      cur = cur->next;
    }
    return ret;
  }

  void follow(int followerId, int followeeId) {
    if (map[followeeId] == nullptr) {
      // create user
      User *u = new User(followeeId);
      map[followeeId] = u;
    }
    map[followeeId]->follower.insert(followerId);
  }

  void unfollow(int followerId, int followeeId) {
    if (map[followeeId] == nullptr) {
      // create user
      User *u = new User(followeeId);
      map[followeeId] = u;
    }
    map[followeeId]->follower.erase(followerId);
  }
};

void print_ret(const vector<int>& ret) {
  cout << "[";
  for (const auto& n : ret) {
    cout << n << ",";
  }
  cout << "]" << endl;
}

int main() {
  Twitter s;
  vector<int> ret;

  // example 1
  s.postTweet(1, 5);
  ret = s.getNewsFeed(1);
  print_ret(ret);
  s.follow(1, 2);
  s.postTweet(2, 6);
  ret = s.getNewsFeed(1);
  print_ret(ret);
  s.unfollow(1, 2);
  ret = s.getNewsFeed(1);
  print_ret(ret);
}
