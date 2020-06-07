/*
 * @Author: your name
 * @Date: 2020-06-05 10:40:33
 * @LastEditTime: 2020-06-05 10:42:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_07\word-ladder.cpp
 */

#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  if (beginWord.empty() || endWord.empty() || wordList.empty()) {
    return 0;
  }
  wordList.push_back(beginWord);
  int start = wordList.size() - 1;
  int end = 0;
  for (int i = 0; i < wordList.size(); ++i) {
    if (wordList[i] == endWord) {
      end = i;
    }
  }
  queue<string> que1;
  que1.push(beginWord);
  queue<string> que2;
  que2.push(endWord);
  unordered_set<int> visited_1;
  unordered_set<int> visited_2;
  visited_1.insert(start);
  visited_2.insert(end);
  int res = 0;

  while (!que1.empty() && !que2.empty()) {
    res++;
    if (que1.size() > que2.size()) {
      queue<string> temp = que1;
      que1 = que2;
      que2 = temp;
      unordered_set<int> t = visited_1;
      visited_1 = visited_2;
      visited_2 = t;
    }
    int n = que1.size();
    for (int i = 0; i < n; ++i) {
      string s = que1.front();
      que1.pop();
      for (int j = 0; j < wordList.size(); ++j) {
        if (!visited_1.count(j)) {
          int diff = 0;
          for (int k = 0; k < s.size(); ++k) {
            if (s[k] != wordList[j][k]) diff++;
          }
          if (diff == 1) {
            if (wordList[j] == endWord) return res;
            que1.push(wordList[j]);
            visited_1.insert(j);
          }
        }
      }
    }
  }
  return 0;
}


int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int res = ladderLength(beginWord,endWord,wordList);

    cout << res << endl;
    return 0;
}