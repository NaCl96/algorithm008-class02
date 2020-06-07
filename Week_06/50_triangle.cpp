/*
 * @Author: your name
 * @Date: 2020-06-02 18:57:36
 * @LastEditTime: 2020-06-02 19:01:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_06\50_triangle.cpp
 */ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mininumTotal(vector<vector<int>>& triangle){
    int n = triangle.size();
    if(n == 0){
        return 0;
    }
    for(int i = n-2; i >= 0; --i){
        for(int j = 0; j < triangle[i].size(); ++j){
            triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}

int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int res = mininumTotal(triangle);
    cout<<res<<endl;
    return 0;
}