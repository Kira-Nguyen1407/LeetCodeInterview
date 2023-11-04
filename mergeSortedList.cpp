#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i = 0, j = 0;
    vector<int> mergedList;

    while(i < m && j < n){
        if(nums1[i] < nums2[j]){
            mergedList.push_back(nums1[i]);
            i++;
        }
        else if(nums1[i] == nums2[j]){
            mergedList.push_back(nums1[i]);
            mergedList.push_back(nums2[j]);
            i++;
            j++;
        }
        else{
            mergedList.push_back(nums2[j]);
            j++;
        }
    }

    while(i < m){
        mergedList.push_back(nums1[i]);
        i++;
    }

    while(j < n){
        mergedList.push_back(nums2[j]);
        j++;
    }

    for(int i = 0; i < nums1.size(); i++){
        nums1[i] = mergedList[i];
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;

    return 0;
}