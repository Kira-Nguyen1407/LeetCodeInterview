#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string s)
{
    int s_len = (int)s.length();
    int pattern_len = (int)pattern.length();

    if (pattern_len <= s_len)
        return false;

    unordered_map<char, string> map_pattern;
    vector<string> words;
    int startFindingIndex = 0;

    for (int i = 0; i < s_len; i++)
    {
        if (i == s_len - 1)
        {
            words.push_back(s.substr(startFindingIndex, s_len - startFindingIndex));
        }
        else
        {
            if (s[i] == ' ')
            {
                words.push_back(s.substr(startFindingIndex, i - startFindingIndex));
                startFindingIndex = i + 1;
            }
        }
    }

    cout << words.size() << endl;
    for(string s : words){
        cout << s << " ";
    }
    cout << endl;

    if (int(words.size()) != pattern_len)
        return false;

    for (int i = 0; i < pattern_len; i++)
    {
        if (map_pattern.count(pattern[i]) == 0)
        {
            map_pattern.insert(make_pair(pattern[i], words[i]));
        }
        else
        {
            if (map_pattern[pattern[i]] != words[i])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    string pattern = "abba", s = "dog cat cat dog";
    cout << wordPattern(pattern, s) << endl;

    return 0;
}