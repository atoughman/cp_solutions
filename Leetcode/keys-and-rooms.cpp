// problem link
// https://leetcode.com/problems/keys-and-rooms/description/

class Solution {
public:
    void dfs(int u, vector<vector<int>> &rooms, vector<bool>& vis) {
        vis[u] = 1;

        for(auto &v: rooms[u]) {
            if(!vis[v]) 
                dfs(v, rooms, vis);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), 0);
        dfs(0, rooms, vis);

        for(auto x: vis) if(!x) return false;
        return true;
    }
};