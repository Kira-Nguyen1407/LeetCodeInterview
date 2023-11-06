#include<iostream>
#include<vector>

using namespace std;

void printHeap(vector<int> nums);
void heapSort(vector<int>& nums);
void buildMaxHeap(vector<int>& nums);
void heapDown(vector<int>& nums, int parent, int heapSize);

void heapSort(vector<int>& nums){
    buildMaxHeap(nums);
    // printHeap(nums);

    int heapSize = nums.size();

    for(int i = nums.size()-1; i > 0; i--){
        swap(nums[i], nums[0]);
        cout << "before:" << endl;
        printHeap(nums);
        heapSize--;
        heapDown(nums, 0, heapSize);
        cout << "after:" << endl;
        printHeap(nums);
    }
}

void buildMaxHeap(vector<int>& nums){
    int heapSize = nums.size();

    for(int i = heapSize/2 - 1; i >= 0; i--){
        heapDown(nums, i, heapSize);
    }
}

void heapDown(vector<int>& nums, int parent, int heapSize){
    int left = parent*2 + 1;
    int right = parent*2 + 2;
    int large = -1;

    if(left < heapSize){
        if(right < heapSize && nums[right] > nums[left]){
            large = right;
        }
        else{
            large = left;
        }

        if(nums[large] > nums[parent]){
            swap(nums[large], nums[parent]);
            heapDown(nums, large, heapSize);
        }
    }
}

void printHeap(vector<int> nums){
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {5,2,3,1};
    heapSort(nums);
    // printHeap(nums);
    return 0;
}