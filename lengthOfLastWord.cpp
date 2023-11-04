#include<iostream>
#include<string>

using namespace std;

int lengthOfLastWord(string s) {
    string lastWord = "";
    size_t spacePos = -1;
    int s_len = (int)s.length();
    int j = 0;

    while(j < s_len && s[j] == ' '){
        j++;
    }

    spacePos = s.find(" ", j);

    while(spacePos != string::npos && j < s_len-1){
        lastWord = s.substr(j, spacePos-j);
        cout << "last word: " << lastWord << endl;

        j = spacePos+1;
        while(j < s_len && s[j] == ' '){
            j++;
        }

        if(j == s_len) break;

        spacePos = j-1;
        spacePos = s.find(" ", j);
    }

    if(j < s_len && j > 0){
        lastWord = s.substr(j, s_len-j);
    }

    return (int)lastWord.length();
}

int main(){
    string word = "a ";
    cout << lengthOfLastWord(word) << endl;
    return 0;
}