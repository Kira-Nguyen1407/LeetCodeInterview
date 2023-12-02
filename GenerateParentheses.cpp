#include<iostream>
#include<vector>

using namespace std;

/*
    Given n pairs of parentheses, generate all combos of well-formed parentheses
    Ex. n = 3 -> ["((()))","(()())","(())()","()(())","()()()"], n = 1 -> ["()"]

    Backtracking, keep valid, favor trying opens, then try closes if still valid

    Time: O(2^n)
    Space: O(n)
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, 0, 0, "", result);
        return result;
    }

    void Print(vector<string> strs){
        for(string str : strs){
            cout << str << " ";
        }
        cout << endl;
    }
private:
    void generate(int n, int open, int close, string str, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(str);
            return;
        }
        if (open < n) {
            generate(n, open + 1, close, str + '(', result);
        }
        if (open > close) {
            generate(n, open, close + 1, str + ')', result);
        }
    }
};

int main(){
    Solution *s = new Solution();
    int n = 3;
    vector<string> result = s->generateParenthesis(n);
    s->Print(result);

    delete s;
    return 0;
}