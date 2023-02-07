// problem link
// https://practice.geeksforgeeks.org/problems/4dfa8ba14d4c94f4d7637b6b5246782412f3aeb8/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           int neg_times = 0;
           int neg1 = 0;
           int neg2 = 0;
           int len = 0;
           bool fresh = true;
           int so_far =0;
           for(int i=0; i<n; i++) {
               if(arr[i] == 0) {
                //   cout << len << ' ' << neg1 << ' ' << neg2 << ' ' << so_far << endl;
                   if(neg_times % 2 == 0) so_far = max(so_far, len);
                   else {
                       int mx = max(len-neg1, len-neg2);
                       so_far = max(so_far, mx);
                   }
                   neg_times = 0;
                   neg1 = 0;
                   neg2 = 0;
                   len = 0;
                   fresh = true;
                   continue;
               }
               
               ++len;
               if(fresh) ++neg1;
               else ++neg2;
               if(arr[i] < 0) {
                   fresh = false;
                   neg2 = 1;
                   ++neg_times;
               }
           }
        //   cout << len << ' ' << neg1 << ' ' << neg2 << ' ' << so_far << endl;
           if(neg_times % 2 == 0) so_far = max(so_far, len);
           else {
               int mx = max(len-neg1, len-neg2);
               so_far = max(so_far, mx);
           }
           
           return so_far;
        }
};