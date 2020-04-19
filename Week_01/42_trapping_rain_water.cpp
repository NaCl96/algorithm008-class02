#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap(vector<int>& heights){
    stack<int> stk;
    int mx = 0;
    for(int i = 0; i < heights.size(); ++i){
        while(!stk.empty() && heights[i] > heights[stk.top()]){
            int cur = stk.top();
            stk.pop();
            if(stk.empty()){
                break;
            }
            int left = stk.top();
            int right = i;
            int h = min(heights[left],heights[right])-heights[cur];
            mx += h * (right-left-1);
        }
        stk.push(i);
    }
    return mx;
}
int main(){
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = trap(heights);
    return 0;
}