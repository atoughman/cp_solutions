#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<int>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            string a = strs[i];
            sort(a.begin(), a.end());
            mp[a].push_back(i);
        }
        vector<vector<string>> ans;

        for (auto it : mp)
        {
            vector<string> v;
            vector<int> ind = it.second;
            for (int i = 0; i < ind.size(); i++)
            {
                v.push_back(strs[ind[i]]);
            }
            ans.push_back(v);
        }

        return ans;
    }
};