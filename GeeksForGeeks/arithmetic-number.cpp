// problem link
// https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1

#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution{
public:
    int inSequence(ll A, ll B, ll C){
        if(A == B) return 1;
        if(C == 0) return 0;
        if(C > 0) return B > A and (B-A)%C == 0;
        else return A > B and (B-A)%C == 0;
    }
};