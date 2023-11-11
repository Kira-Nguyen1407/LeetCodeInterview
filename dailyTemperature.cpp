#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> output(size, 0);

        //<temperature, index>
        stack<pair<int, int>> st; 

        st.push({temperatures[0], 0});

        for(int i = 1; i < size; i++){
            while(!st.empty() && temperatures[i] >= st.top().first){
                output[st.top().second] = i - st.top().second;
                st.pop();
            }

            st.push({temperatures[i], i});
        }

        return output;
    }
};

void printVector(vector<int> nums){
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    Solution *s = new Solution();
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> output;

    output = s->dailyTemperatures(temperatures);
    printVector(output);

    delete s;
    return 0;
}