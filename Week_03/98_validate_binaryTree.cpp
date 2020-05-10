/*
 * @Author: your name
 * @Date: 2020-04-27 09:39:18
 * @LastEditTime: 2020-04-29 15:00:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_03\98_validate_binaryTree.cpp
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std; 

string replaceSpace(string s) {
        string res = "";
        for(int i = 0; i < s.size(); ++i){
            if(s[i] = ' '){
                res += "%20";
            }
            else{
                res += s[i];
            }
        }
        return res;
    }
int main(){
    string s = "we are happy";
    string res = replaceSpace(s);
    return 0;
}