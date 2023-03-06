// problem link
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution 
{
    //Function to find if there is a celebrity in the party or not.
    celebrity(M, n)
    {
        let celeb = 0;
        for(let i=1; i<n; i++) {
            if(M[celeb][i] === 1 || M[i][celeb] === 0) celeb = i;
        }
        
        for(let i=0; i<n; i++) {
            if(i == celeb) continue;
            // row check
            if(M[celeb][i] === 1) return -1;
            
            // col check
            if(M[i][celeb] === 0) return -1;
        }
        
        return celeb;
    }
}