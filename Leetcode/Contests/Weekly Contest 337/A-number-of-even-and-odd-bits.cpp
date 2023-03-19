#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even=0, odd=0;
        int i=0;
        while(n) {
            if(n%2 == 1) {
                if(i%2 == 0) ++even;
                else ++odd;
            }
            n /= 2;
            i += 1;
        }
        
        return {even, odd};
    }
};