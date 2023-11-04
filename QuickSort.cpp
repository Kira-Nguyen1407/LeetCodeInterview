#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int k = right;

        for(int i = right; i > left; i--){
            if(nums[i] > pivot){
                swap(nums[i], nums[k]);
                k--;
            }
        }
        cout << "k: " << k << endl;

        swap(nums[left], nums[k]);

        return k;

        // // First element as pivot
        // int pivot = nums[left];
        // int st = left; // st points to the starting of array
        // int end = right; // end points to the ending of the array
        // int k = right;
        // for (int i = right; i > left; i--) {
        //     if (nums[i] > pivot)
        //         swap(nums[i], nums[k--]);
        // }
        // swap(nums[left], nums[k]);
        // // As we got pivot element index is end
        // // now pivot element is at its sorted position
        // // return pivot element index (end)
        // return k;
    }

    void quickSort(vector<int>& nums, int left, int right){
        if(left < right){
            int mid = partition(nums, left, right);
            // cout << mid << endl;

            quickSort(nums, left, mid-1);
            quickSort(nums, mid+1, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void print(vector<int> nums){
        for(int x : nums){
            cout << x << " ";
        }

        cout << endl;
    }
};

int main(){
    vector<int> nums = {7,   6,   10,   5,   9,   2,   1,   15,   7};
    vector<int> newNums;
    Solution *s = new Solution();

    newNums = s->sortArray(nums);
    s->print(newNums);

    delete s;
    return 0;
}