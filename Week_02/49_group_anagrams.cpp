/* 
字母异位词分组
 */


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;    

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string,int> map;
    int sub = 0;
    string temp;

    for(auto str : strs){
        temp = str;
        sort(temp.begin(),temp.end());
        if(map.count(temp)){
            ans[map[temp]].push_back(str);
        }
        else{
            vector<string> vec(1,str);
            ans.push_back(vec);
            map[temp]=sub++;
        }
    }
    return ans;
}

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = groupAnagrams(strs);
    return 0;
}