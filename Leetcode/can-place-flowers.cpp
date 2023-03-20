// problem link
// https://leetcode.com/problems/can-place-flowers/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int consecutive_zeros = 0;
        int sz = flowerbed.size();
        if(sz == 1) {
            return !(flowerbed[0] & n);
        }

        bool start = true, end = false;

        for(int i=0; i<sz; i++) {
            if(flowerbed[i] == 0) {
                consecutive_zeros += 1;
                if(i+1 == sz) end = true;
            }

            if(flowerbed[i] == 1 or i+1 == sz) {
                n -= (consecutive_zeros-1+start+end)/2;
                consecutive_zeros = 0;
                start = false;
            }
            if(n <= 0) return true;
        }
        
        return false;
    }
};