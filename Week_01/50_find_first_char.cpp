#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

char firstUniqChar(string s)
{
    if (s.size() == 0)
    {
        return ' ';
    }
    unordered_map<char, bool> map;
    for (int i = 0; i < s.size(); ++i)
    {
        if (map.find(s[i]) != map.end())
        {
            map[s[i]] = false;
            continue;
        }
        map[s[i]] = true;
    }
    for (char c : s)
    {
        if (map[c])
        {
            return c;
        }
    }
    return ' ';
}

int main()
{
    string s = "leetcode";
    char ans = firstUniqChar(s);
    return 0;
}