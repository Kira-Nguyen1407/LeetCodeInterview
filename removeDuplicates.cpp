#include <iostream>
#include <vector>

using namespace std;

void shiftLeft(vector<int> &nums, int pos, int k)
{
    for (int i = pos; i < k - 1; i++)
    {
        nums[i] = nums[i + 1];
    }
}

int removeDuplicates(vector<int> &nums)
{
    int count = 1;
    int k = (int)nums.size();
    cout << "k: " << k << endl;
    int n_shift = 0;

    for (int i = 0; i < k-1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            count++;
            if (count > 2)
            {
                while (nums[i] == nums[i + 1] && i < k-1)
                {
                    shiftLeft(nums, i, k);
                    // cout << "here" << endl;
                    n_shift++;
                    k--;
                    // if(n_shift == 2){
                    //     break;
                    // }
                }
                count = 1;
            }
        }
        else
        {
            count = 1;
        }

        cout << "i: " << i << endl;

        for (int j = 0; j < k; j++)
        {
            cout << nums[j];
            j == k - 1 ? cout << endl : cout << " ";
        }

        // if(n_shift == 2) break;
    }

    return k;
}

int main()
{
    vector<int> nums = {1,1,1};

    int result = removeDuplicates(nums);
    cout << result << endl;

    for (int i = 0; i < result; i++)
    {
        cout << nums[i];
        i == result - 1 ? cout << endl : cout << " ";
    }

    return 0;
}