#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0, j = 1;
    while(j < nums.size()){
        if(nums[j] == nums[i]){
            j++;
        }
        else{
            i++;
        }
    }
    return i+1;
}

int main()
{
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};
    int res = removeDuplicates(nums);
    return 0;
}