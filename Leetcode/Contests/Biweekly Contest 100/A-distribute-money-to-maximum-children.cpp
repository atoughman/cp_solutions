#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children or (children == 1 and money == 4)) return -1;
        money -= children;
        int ans = money/7;
        int rem = money%7;
        if(ans <= children-2) return ans;
        if(ans == children - 1) {
            if(rem == 3) return ans - 1;
            return ans;
        }
        if(ans == children) {
            if(rem != 0) return ans - 1;
            return ans;
        }
        return children - 1;
        
    }
};