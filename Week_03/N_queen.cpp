/*
 * @Author: your name
 * @Date: 2020-05-08 10:51:54
 * @LastEditTime: 2020-05-08 11:15:59
 * @LastEditors: Please set LastEditors
 * @Description: N皇后问题
 * @FilePath: \algorithm008-class02\Week_03\N_queen.cpp
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isvalid(vector<string>& board,int row,int col){
    int n = board.size();
    for(int i = 0; i < n;++i){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    for(int i = row-1,j = col+1; i >= 0 && j < n; --i,++j){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    for(int i = row-1,j = col-1; i >=0 && j >=0;--i,--j){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}
void trackBack(vector<vector<string>>& ans,vector<string>& board,int row){
    if(row == board.size()){
        ans.push_back(board);
        return;
    }
    int n = board[row].size();
    for(int i = 0; i < n; ++i){
        if(!isvalid(board,row,i)){
            continue;
        }
        board[row][i] = 'Q';
        trackBack(ans,board,row+1);
        board[row][i] = '.';
    }
}

vector<vector<string>> solveNqueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n,string(n,'.'));
    trackBack(ans,board,0);
    return ans;
}

int main(){
    int n = 8;
    auto res = solveNqueens(n);
    for(auto i : res[0]){
        cout<<i<<endl;
    }
    return 0;
}
