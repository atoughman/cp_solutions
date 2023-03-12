#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isVowel(char ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
    
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for(int i=left; i<=right; i++) {
            if(isVowel(words[i][0]) and isVowel(words[i].back())) ++ans;
        }
    return ans;
    }
    
};