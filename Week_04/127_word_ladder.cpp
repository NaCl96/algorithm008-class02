/*
 * @Author: your name
 * @Date: 2020-05-12 11:54:40
 * @LastEditTime: 2020-05-12 11:56:58
 * @LastEditors: Please set LastEditors
 * @Description: 127.单词接龙
 * @FilePath: \algorithm008-class02\Week_04\127_word_ladder.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
    return 0;
  }
  if (beginWord.empty() || endWord.empty() || wordList.empty()) {
    return 0;
  }
  queue<string> que;
  que.push(beginWord);
  vector<int> visited(wordList.size(), 0);
  int ans = 0;
  while (!que.empty()) {
    ans++;
    for (int i = que.size() - 1; i >= 0; --i) {
      string temp = que.front();
      que.pop();
      for (int j = 0; j < wordList.size(); ++j) {
        if (visited[j] == 0) {
          int diff = 0;
          for (int k = 0; k < temp.size(); ++k) {
            if (temp[k] != wordList[j][k]) diff++;
          }
          if (diff == 1) {
            if (wordList[j] == endWord) return ans;
            visited[j] = 1;
            que.push(wordList[j]);
          }
        }
      }
    }
  }
  return ans;
}
int main() { 
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int res = ladderLength(beginWord,endWord,wordList);
    return 0; }