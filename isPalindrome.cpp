#include<iostream>
#include<string>

using namespace std;

bool isAlphanumeric(char s){
    if(((int)s >= 48 && (int)s <= 57) || ((int)s >= 65 && (int)s <= 90) || 
        ((int)s >= 97 && (int)s <= 122))
    {
        return true;
    }

    return false;
}

bool isPalindrome(string s){
    string processed_str = "";

    for(int i=0; i < s.length(); i++){
        if(isAlphanumeric(s[i])){
            if(int(s[i]) >= 65 && int(s[i]) <= 90){
                char new_char = s[i] + 32;
                processed_str.append(1, new_char);
            }
            else{
                processed_str.append(1, s[i]);
            }
        }
    }

    int process_str_len = (int)processed_str.length();

    if(process_str_len <= 1) return true;

    cout << processed_str << endl;

    for(int i=0; i < process_str_len/2; i++){
        if(processed_str[i] == processed_str[process_str_len-1-i]){
            if(i == process_str_len/2 -1){
                return true;
            }
        }
    }

    return false;
}

int main(){
    string s = ",; W;:GlG:;l ;,";
    cout << isPalindrome(s) << endl;
    return 0;
}