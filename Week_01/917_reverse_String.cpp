#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string reverseOnlyLetters(string S)
{
    int i = 0, j = S.size() - 1;
    while (i < j)
    {
        if (((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z')) && ((S[j] >= 'A' && S[j] <= 'Z') || (S[j] >= 'a' && S[j] <= 'z')))
        {
            char temp = S[j];
            S[j] = S[i];
            S[i] = temp;
            j--;
            i++;
        }
        else if ((S[i] < 'A' || (S[i] > 'Z' && S[i] < 'a') || S[i] > 'z'))
        {
            i++;
        }
        else if ((S[j] < 'A' || (S[j] > 'Z' && S[j] < 'a') || S[j] > 'z'))
        {
            j--;
        }
    }
    return S;
}

string reverseOnlyLetters_2(string S)
{
    stack<char> stk;
    for (char c : S)
    {
        if (isalpha(c))
        {
            stk.push(c);
        }
    }
    for (int i = 0; i < S.size(); ++i)
    {
        if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
        {
            S[i] = stk.top();
            stk.pop();
        }
    }
    return S;
}

int main()
{
    string s = "a-bC-dEf-ghIj";
    string res = reverseOnlyLetters_2(s);
    return 0;
}