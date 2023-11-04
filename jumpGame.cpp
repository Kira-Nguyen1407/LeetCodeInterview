#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        
        for(int i = goal-1; i >= 0; i--){
            if(i + nums[i] >= goal){
                goal = i;
            }
        }

        return goal == 0;
    }
};

int main(){
    vector<int> nums = {4,0,0,0,2,3};
    Solution *s = new Solution();

    cout << s->canJump(nums) << endl;
    delete s;
    return 0;
}