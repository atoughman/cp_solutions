#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        for(int i=0; i<k; i++) {
            if(numOnes > 0) {
                ans += 1;
                numOnes -= 1;
            } else if(numZeros > 0) {
                numZeros -= 1;
            } else {
                ans -= 1;
                numNegOnes -= 1;
            }
        }
        
        return ans;
    }
};