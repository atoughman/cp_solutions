// problem link
// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

#include<bits/stdc++.h>
using namespace std;

string solve(string A) {
    map<char, int> mp;
    string B = "";
    int l = 0;
    int n = A.size();
    
    for(int i=0; i<n; i++) {
        mp[A[i]]++;
        while(l < i and mp[A[l]] > 1) ++l;
        if(mp[A[l]] == 1) B += A[l];
        else B += "#";
    }
    
    return B;
}
