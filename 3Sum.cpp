#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        // print(nums);

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == nums[i-1]){
                continue;
            }

            cout << i << " ";

            // if(i == 3){
            //     cout << "here" << endl;
            // }

            int j = 0, k = size - 1;
            if(i == 0){
                j = 1;
            }
            if(i == size - 1){
                k = size - 2;
            }
            while(j < k){
                if(j == i || k == i){
                    continue;
                }
                
                if(i == 1){
                    cout << "j: " << j << ", k: " << k << endl;
                }
                if(nums[j] + nums[k] < -nums[i] || nums[j] == nums[j-1]){
                    j++;
                }
                else if(nums[j] + nums[k] > -nums[i] || nums[k] == nums[k+1]){
                    k--;
                }
                else if(nums[j] + nums[k] == -nums[i] && j != i && k != i && j != k){
                    vector<int> triplet(3);
                    triplet[0] = nums[j];
                    triplet[1] = nums[i];
                    triplet[2] = nums[k];

                    result.push_back(triplet);
                    j++;
                    k--;
                }
            }
        }

        return result;
    }

    void print(vector<int> nums){
        for(int x : nums){
            cout << x << " ";
        }

        cout << endl;
    }
};

int main(){
    Solution *s = new Solution();
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = s->threeSum(nums);
    // for(vector<int> x : result){
    //     s->print(x);
    // }
    delete s;
    return 0;
}