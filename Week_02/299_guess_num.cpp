#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string getHint(string secret, string guess)
{
    string res = "";
    int cnt_A = 0;
    int cnt_B = 0;
    unordered_map<char, int> map;
    for (int i = 0; i < secret.size(); ++i)
    {
        map[secret[i]]++;
        if (secret[i] == guess[i])
        {
            cnt_A++;
        }
    }
    for (char j : guess)
    {
        if (map[j] > 0)
        {
            cnt_B++;
            map[j]--;
        }
    }
    cnt_B -= cnt_A;
    return to_string(cnt_A) + 'A' + to_string(cnt_B) + 'B';
}
int main()
{
    string s1 = "1123";
    string s2 = "0111";
    string res = getHint(s1, s2);
    return 0;
}