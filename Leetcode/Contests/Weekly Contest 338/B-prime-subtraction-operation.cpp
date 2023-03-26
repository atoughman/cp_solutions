#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3+5;  // MAX till 1e8
bool is_prime[MAX];

void sieve() {
	fill(is_prime, is_prime+MAX, true);   // let's consider everything as prime in starting
	
	is_prime[0] = false;
	is_prime[1] = false;
	
	int fast = 1;
	for(int i=2; i*i<MAX; i+=fast) {
		if(is_prime[i]) {
			for(int j=i*i; j<MAX; j+=i) {
				is_prime[j] = false;    // it is not prime
			}
		}
		if(i==3) fast++;
	}
}

bool sieveRan = false;

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        if(!sieveRan) {
            sieveRan = true;
            sieve();
        }
        
        int so_far = 0;
        for(auto &x: nums) {
            bool done = false;
            for(int i=x-1; i>=0; i--) {
                if(is_prime[i] and x-i > so_far) {
                    so_far = x - i;
                    done = true;
                    break;
                }
            }
            if(!done) return false;
        }
        
        return true;
    }
};