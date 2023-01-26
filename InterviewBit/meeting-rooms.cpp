// problem link
// https://www.interviewbit.com/problems/meeting-rooms/

int solve(vector<vector<int> > &A) {
    map<int,int> mp;
    int ans = 0;
    
    for(auto x: A) {
        mp[x[0]]++;
        mp[x[1]]--;
    }
    
    int mx = 0;
    for(auto x: mp) {
        ans += x.second;
        mx = max(mx, ans);
    }
    
    return mx;
}
