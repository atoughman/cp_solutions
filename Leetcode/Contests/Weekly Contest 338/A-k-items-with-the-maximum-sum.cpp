#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        for(int i=0; i<k; i++) {
            if(numOnes > 0) {
                ans += numOnes;
                numOnes -= 1;
            } else if(numZeros > 0) {
                numZeros -= 1;
            } else {
                ans += numNegOnes;
                numNegOnes -= 1;
            }
        }
        
        return ans;
    }
};