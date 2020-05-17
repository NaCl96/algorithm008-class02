/*
 * @Author: your name
 * @Date: 2020-05-13 10:46:45
 * @LastEditTime: 2020-05-13 10:47:06
 * @LastEditors: Please set LastEditors
 * @Description: 435. 无重叠区间
 * @FilePath: \algorithm008-class02\Week_04\435_non_overlapping_intervals.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<vector<int>>& intervals,int l,int r){
    int pivot = l;
    int index = pivot;
    for(int i = l+1; i <= r; ++i){
        if(intervals[i][0] < intervals[pivot][0]){
            swap(intervals[i],intervals[++index]);
        }
    }
    swap(intervals[pivot],intervals[index]);
    return index;
}

void quick(vector<vector<int>>& intervals,int l,int r){
    while(l < r){
        int x = partition(intervals,l,r);
        quick(intervals,l,x-1);
        quick(intervals,x+1,r);
    }
}

//对起始时间排序，进行贪婪
int eraseOverlapIntervals(vector<vector<int>>& intervals){
    if(intervals.size() < 2){
        return 0;
    }
    quick(intervals,0,intervals.size()-1);

    int end = intervals[0][1];
    int ans = 0;
    for(int i = 1; i < intervals.size();++i){
        if(intervals[i][0] < end){
            ans++;
            end = min(intervals[i][1],end);
        }
        else{
            end = intervals[i][1];
        }
    }
    return ans;
}

//对结束时间进行排序，进行贪婪
int eraseOverlapIntervals_2(vector<vector<int>>& intervals){
    if(intervals.size() <2 ){
        return 0;
    }
    quick(intervals,0,intervals.size()-1);
    int end = intervals[0][1];
    int ans = 0;
    for(int i = 1; i < intervals.size()-1; ++i){
        if(intervals[i][0] >= end){
            ans++;
            end = intervals[i][1];
        }
    }
    return intervals.size()-ans;
}

//动态规划
int eraseOverlapIntervals_3(vector<vector<int>>& intervals){
    if(intervals.size() < 2){
        return 0;
    }
    quick(intervals,0,intervals.size()-1);
    vector<int> dp(intervals.size(),-1);
    dp[0] = 1;
    int ans = 1;
    for(int i = 1;i < intervals.size();++i){
        int mx = 0;
        for(int j = i-1; j >= 0;--j){
            if(intervals[i][0] >= intervals[j][1]){
                mx = max(dp[j],mx);
            }
        }
        dp[i] = mx+1;
        ans = max(ans,dp[i]); 
    }
    return intervals.size()-ans;
}
int main(){
    
}