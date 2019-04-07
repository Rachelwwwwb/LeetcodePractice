#include<iostream>
using namespace std;
string longestPalindrome(string s) {
    if (s.size() <= 1) return s;
    string retval = "";
    bool**result = new bool*[s.size()];
    for (int i = 0; i < s.size();i++){
        result[i] = new bool[s.size()];
    }
    
    for (int i = 0; i < s.size();i++){
        for (int j = i; j < s.size();j++){
             if (i == j) result[i][j] = true;
             else if (j == i+1) result[i][j] = (s[i] == s[j]);
        }
    }
    for (int i = (int)s.size(); i >= 0 ;i--){
        for (int j = i; j < s.size();j++){
            if (i != j && j != i+1){
                result[i][j] = (bool)((s[i] == s[j]) && result[i+1][j-1]);

            }
        }
    }

    for (int i = 0; i < s.size();i++){
        for (int j = i; j < s.size();j++){
            if (result[i][j]){
                if (j-i+1 > retval.size()){
                    retval = s.substr(i,j-i+1);
                }
            }
        }
    }
    return retval;
}
  
