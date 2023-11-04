#include<iostream>
#include<vector>
#include<unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    void heapUp(vector<pair<int, int>> &maxHeap, int pos){
        if(pos > 0){
            int parent = (pos-1)/2;
            if(maxHeap[pos].second > maxHeap[parent].second){
                swap(maxHeap[pos], maxHeap[parent]);
                heapUp(maxHeap, parent);
            }
        }
    }
    void heapDown(vector<pair<int, int>> &maxHeap, int pos, int lastPos){
        int left = pos*2 + 1;
        int right = pos*2 + 2;

        if(left <= lastPos){
            int large = -1;
            if(right <= lastPos && maxHeap[right].second > maxHeap[left].second){
                large = right;
            }
            else{
                large = left;
            }

            if(maxHeap[large].second > maxHeap[pos].second){
                swap(maxHeap[large], maxHeap[pos]);
                heapDown(maxHeap, large, lastPos);
            }
        }
    }
    void removeHeap(vector<pair<int, int>> &maxHeap){
        maxHeap[0] = maxHeap[maxHeap.size()-1];
        maxHeap.pop_back();

        // for(pair<int, int> x : maxHeap){
        //     cout << "key: " << x.first << ", " << "value: " << x.second << endl;
        // }
        // cout << "size: " << maxHeap.size()-1 << endl;
        heapDown(maxHeap, 0, maxHeap.size()-1);
    }
    void InsertHeap(vector<pair<int, int>> &maxHeap, pair<int, int> node){
        maxHeap.push_back(node);
        heapUp(maxHeap, maxHeap.size()-1);
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fmap;
        vector<pair<int, int>> maxHeap;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            fmap[nums[i]]++;
        }

        for(pair<int, int> x : fmap){
            // cout << "key: " << x.first << ", " << "value: " << x.second << endl;
            InsertHeap(maxHeap, x);
        }

        // for(pair<int, int> x : maxHeap){
        //     cout << "key: " << x.first << ", " << "value: " << x.second << endl;
        // }

        while(k > 0){
            result.push_back(maxHeap[0].first);
            removeHeap(maxHeap);
            k--;
        }

        // for(pair<int, int> x : maxHeap){
        //     cout << "key: " << x.first << ", " << "value: " << x.second << endl;
        // }


        return result;
    }
};

int main(){
    vector<int> nums = {5,3,1,1,1,3,73,1};
    int k = 2;
    Solution *s = new Solution();

    vector<int> result = s->topKFrequent(nums, k);
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    delete s;

    return 0;
}