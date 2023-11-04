#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &nums, int k)
{
    int nums_size = (int)nums.size();

    if (k > 0)
    {
        while (k > nums_size)
        {
            k -= nums_size;
        }

        if (k < nums_size)
        {
            int current, walker;

            if(k <= nums_size - k){
                current = k;
                walker = nums_size - k;
            }
            else{
                current = nums_size - k;
                walker = current;
            }

            for (int i = 0; i < current; i++)
            {
                swap(nums[i], nums[walker]);
                walker++;
            }

            for (int i : nums)
            {
                cout << i << " ";
            }

            cout << endl;

            if(k <= nums_size - k){
                walker = nums_size - k;
            }

            while (walker < nums_size)
            {
                int j = walker;
                while (j > current)
                {
                    swap(nums[j], nums[j - 1]);
                    j--;
                }

                walker++;
                current++;
                // break;
            }
        }
    }
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,
                        24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,
                        44,45,46,47,48,49,50,51,52,53};

    // vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int k = 29;

    rotate(nums, k);

    for (int i : nums)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}