/*
 * @Author: your name
 * @Date: 2020-04-25 10:55:48
 * @LastEditTime: 2020-04-25 10:57:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_02\299.bull.cpp
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


string getHint(string secret, string guess) {
        string res = "";
        int cnt_A = 0;
        int cnt_B = 0;
        unordered_map<char,int> map;
        for(int i = 0;i < secret.size();++i){
            if(secret[i] == guess[i]) cnt_A++;
            map[secret[i]]++;
        }
        for(int j = 0; j < guess.size();++j){
            if(map.count(guess[j]) > 0){
                cnt_B++;
                map[guess[j]]--;
            }
        }
        cnt_B -= cnt_A;
        return to_string(cnt_A)+'A' + to_string(cnt_B)+'B';
}
int main(){
    string secret = "1123";
    string guess = "0111";
    string res = getHint(secret,guess);
    return 0;
}