#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitNum(int num) {
        int a = 0;
        int b = 0;
        vector<int> v;
        while(num) {
            v.push_back(num%10);
            num /= 10;
        }
        
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++) {
            if(i%2 == 0) {
                a = a*10 + v[i];
            } else b = b*10 + v[i];
        }
        
        return a+b;
    }
};