// problem link
// https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        int n = s1.size();
        int target[26] = {0};

        int count = 0;
        for(int i=0; i<n; i++) {
            target[s1[i]-'a']++;
        }

        for(int i=0; i<26; i++) {
            if(target[i] == freq[i]) ++count;
        }

        for(int i=0; i<s2.size(); i++) {
            // update
            freq[s2[i]-'a']++;
            if(freq[s2[i]-'a'] == target[s2[i]-'a']) ++count;
            if(count == 26) return true;
            if(i >= n-1) {
                if(freq[s2[i-(n-1)]-'a'] == target[s2[i-(n-1)]-'a']) --count;
                freq[s2[i-(n-1)]-'a']--;
            }
        }

        return false;
    }
};