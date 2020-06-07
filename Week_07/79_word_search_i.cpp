/*
 * @Author: your name
 * @Date: 2020-06-07 10:07:26
 * @LastEditTime: 2020-06-07 10:13:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_07\79_word_search_i.cpp
 */ 

#include <iostream>
#include <vector>

using namespace std; 

bool dfs(vector<vector<char>>& board,string& word,int i,int j,int index){
    if(board[i][j] == '.'||board[i][j] != word[index]){
        return false;
    }
    if(index == word.size()-1){
        return true;
    }
    char c = board[i][j];
    board[i][j] = '.';
    if((i-1>0 && dfs(board,word,i-1,j,index+1)) || (j-1>0 && dfs(board,word,i,j-1,index+1)) || 
    (i+1<board.size()&&dfs(board,word,i+1,j,index+1)) || (j+1<board[0].size() && dfs(board,word,i,j+1,index+1))){
        return true;
    }
    board[i][j] = c;
    return false;
}

bool exist(vector<vector<char>>& board,string word){
    int n = board.size();
    if(n == 0) return false;
    int m = board[0].size();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] != word[0]) continue;
            if(dfs(board,word,i,j,0)){
                return true;
            }
        }
    }
    return false;
}
