#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares_1(vector<int> &A)
{
    int index = -1;
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] < 0 && A[i + 1] >= 0)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        for (int i = 0; i < A.size(); ++i)
        {
            A[i] = A[i] * A[i];
        }
    }
    else
    {
        vector<int> ans;
        int j = index, k = index + 1;
        while (j >= 0 && k < A.size())
        {
            if (j >= 0 && k < A.size() && A[j] * A[j] >= A[k] * A[k])
            {
                ans.push_back(A[k] * A[k]);
                k++;
            }
            else if (j >= 0 && k < A.size() && A[j] * A[j] < A[k] * A[k])
            {
                ans.push_back(A[j] * A[j]);
                j--;
            }
        }
        while (j >= 0)
        {
            ans.push_back(A[j] * A[j]);
            j--;
        }
        while (k < A.size())
        {
            ans.push_back(A[k] * A[k]);
            k++;
        }
        return ans;
    }
    return A;
}

vector<int> sortedSquares_2(vector<int> &A)
{
    vector<int> ans;
    int l = 0, r = A.size()-1;
    for(int i = A.size()-1; i >= 0; --i){
        if(abs(A[l]) < abs(A[r])){
            ans[i] = A[r]*A[r--];
        }else{
            ans[i] = A[l]*A[l++];
        }
    }
    return ans;
}

int main()
{
    vector<int> A{-4, -1, 0, 3, 10};
    auto res = sortedSquares_2(A);
    return 0;
}