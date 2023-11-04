#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchRec(vector<int>& nums, int target, int left, int right){
        if(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] > target){
                return searchRec(nums, target, left, mid-1);
            }
            else{
                return searchRec(nums, target, mid+1, right);
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        return searchRec(nums, target, l, r);
    }
};

int main(){
    Solution *s = new Solution();
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;

    cout << s->search(nums, target) << endl;

    delete s;
    return 0;
}