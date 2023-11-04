#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int partition(vector<int>& arr, int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(vector<int>& arr, int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int removeElement(vector<int>& nums, int val) {
    int nums_size = (int)nums.size();

    if(nums_size == 0) return 0;

    if(nums_size == 1){
        if(nums[0] == val) return 1;
    }

    int firstMatch = -1, m = 0;

    quickSort(nums, 0, nums_size-1);

    for(int i = 0; i < nums_size; i++) {
        if(nums[i] == val){
            if(firstMatch == -1){
                firstMatch = i;
                int j = i;

                while(nums[j] == val){
                    j++;
                    m++;
                }
            }

            if(i+m < nums_size){
                nums[i] = nums[i+m];
            }
            else{
                break;
            }
        }
    }

    return nums_size - m;
}

int main(){
    vector<int> nums = {3,2,2,3}; // 0 0 1 2 2 2 3 4
    int val = 2;

    int k = removeElement(nums, val);
    cout << "k = " << k << endl;

    for(int i = 0; i < k; i++) {
        cout << nums[i];
        i == k-1 ? cout << endl : cout << " ";
    }

    return 0;
}