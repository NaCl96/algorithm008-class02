/*
 * @Author: your name
 * @Date: 2020-06-02 13:40:30
 * @LastEditTime: 2020-06-07 12:35:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_07\212_word_search.cpp
 */

#include <iostream>
#include <string>
#include <vector>

#include "Trie.h"
using namespace std;

vector<string> res;
vector<vector<int>> direct = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// void dfs(vector<vector<char>>& board,int i,int j,Trie* root){
//     char c = board[i][j];
//     if(c == '.' || root->next[c-'a'] == nullptr) return;
//     root = root->next[c-'a'];
//     if(root->str != ""){
//         res.push_back(root->str);
//         root->str = "";
//     }
//     board[i][j] = '.';
//     // for(int i = 0; i < 4;++i){
//     //     int new_i = direct[i][0] + i;
//     //     int new_j = direct[i][1] + j;
//     //     if(new_i < 0 || new_j < 0 || new_i >= board.size() || new_j >=
//     board[0].size()) continue;
//     //     dfs(board,new_i,new_i,root);
//     // }
//     if(i > 0) dfs(board,i-1,j,root);
//     if(j > 0) dfs(board,i,j-1,root);
//     if(i+1 < board.size()) dfs(board,i+1,j,root);
//     if(j+1 < board[0].size()) dfs(board,i,j+1,root);
//     board[i][j] = c;
// }
void dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
  if (board[i][j] == '.' || board[i][j] != word[index]) {
    return;
  }
  if (index == word.size() - 1) {
    res.push_back(word);
    return;
  }
  char c = board[i][j];
  board[i][j] = '.';
  if (i - 1 > 0) dfs(board, word, i - 1, j, index + 1); 
  if (j - 1 > 0 ) dfs(board, word, i, j - 1, index + 1);
  if (i + 1 < board.size()) dfs(board, word, i + 1, j, index + 1);
  if (j + 1 < board[0].size()) dfs(board, word, i, j + 1, index + 1);
  board[i][j] = c;
}

// vector<string> findWord(vector<vector<char>>& board, vector<string>& words) {
//   int raw = board.size();
//   int col = board[0].size();
//   if (raw == 0 || col == 0) {
//     return {};
//   }
//   Trie* root = new Trie();
//   for (auto w : words) {
//     root->insert(w);
//   }

//   for (int i = 0; i < raw; ++i) {
//     for (int j = 0; j < col; ++j) {
//       dfs(board, i, j, root);
//     }
//   }
//   return res;
// }

vector<string> findWords_2(vector<vector<char>>& board, vector<string>& words) {
  int n = board.size();
  if (n == 0) return {};
  int m = board[0].size();

  for (string word : words) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] != word[0]) continue;
        dfs(board,word,i,j,0);
      }
    }
  }
  return res;
}

int main() {
  vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                {'e', 't', 'a', 'e'},
                                {'i', 'h', 'k', 'r'},
                                {'i', 'f', 'l', 'v'}};
  vector<string> words = {"oath", "pea", "eat", "rain"};

  auto ans = findWords_2(board, words);

  for (auto i : ans) {
    cout << i << endl;
  }
  return 0;
}
