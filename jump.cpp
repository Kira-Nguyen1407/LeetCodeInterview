#include<iostream>
#include<vector>

using namespace std;

bool jump(vector<int>& nums){
    int nums_size = (int)nums.size();
    if(nums_size == 0) return true;

    int walker = nums[0];
    if(walker == 0) return false;

    while(walker < nums_size-1){
        if(nums[walker] == 0){
            return false;
        }

        walker += nums[walker];
    }

    return true;
}

int main(){
    vector<int> nums = {2,0,0};

    cout << jump(nums) << endl;

    return 0;
}