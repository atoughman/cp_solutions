// problem link
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    long long merge(long long arr[], long long left, long long right) {
        long long merge_inv = 0;
        long long mid = left + (right - left)/2;
        
        vector<long long> left_arr;
        vector<long long> right_arr;
        
        for(long long i=left; i<=mid; i++) left_arr.push_back(arr[i]);
        for(long long i=mid + 1; i<=right; i++) right_arr.push_back(arr[i]);
        
        long long l1 = 0;
        long long r1 = left_arr.size();
        long long l2 = 0;
        long long r2 = right_arr.size();
        
        while(l1 < r1 and l2 < r2) {
            if(left_arr[l1] <= right_arr[l2]) {
                arr[left] = left_arr[l1];
                ++l1;
            }
            else {
                arr[left] = right_arr[l2];
                ++l2;
                merge_inv += r1 - l1;
            }
            ++left;
        }
        
        while(l1 < r1) {
            arr[left] = left_arr[l1];
            ++l1;
            ++left;
        }
        
        while(l2 < r2) {
            arr[left] = right_arr[l2];
            ++l2;
            ++left;
        }
        
        left_arr.clear();
        left_arr.shrink_to_fit();
        right_arr.clear();
        right_arr.shrink_to_fit();
        
        return merge_inv;
    }
    
    long long merge_sort(long long arr[], long long left, long long right) {
        long long inv_count = 0;
        if(right>left) {
            long long mid = left + (right - left)/2;
            
            inv_count += merge_sort(arr, left, mid);
            inv_count += merge_sort(arr, mid + 1, right);
            inv_count += merge(arr, left, right);
        }
        
        return inv_count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return merge_sort(arr, 0, N-1);
    }

};