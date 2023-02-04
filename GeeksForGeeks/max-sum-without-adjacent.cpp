// problem link
// https://practice.geeksforgeeks.org/problems/7a33c749a79327b2889d420dd80342fff33aac6d/1

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int ans = 0;
	    
	    for(int i=0; i<n; i++) {
	        int one = i-2>=0 ? arr[i-2] : 0;
	        int two = i-3>=0 ? arr[i-3] : 0;
	        arr[i] += max(one, two);
	        ans = max(ans, arr[i]);
	    }
	    
	    
	    return ans;
	}
};