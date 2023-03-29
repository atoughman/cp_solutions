// problem link
// https://leetcode.com/problems/reducing-dishes/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());

        int sum = 0;
        int like_time_co = 0;
        for(auto &x: satisfaction) {
            if(sum + x >= 0) {
                like_time_co += sum + x;
                sum += x;
            } else break;
        }

        return like_time_co;
    }
};