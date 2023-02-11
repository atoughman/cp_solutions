// problem link
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include<bits/stdc++.h>
using namespace std;

#define pi pair<int,int>

class Solution
{
	public:
	const int INF = INT_MAX;
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V, INF);
        dis[S] = 0;
        
        priority_queue<pi, vector<pi>, greater<pi>> q;
        q.push({0, S});
        
        while(!q.empty()) {
            pi top = q.top();
            q.pop();
            int so_far = top.first;
            int u = top.second;
            if(dis[u] < so_far) continue;
            
            for(auto &node: adj[u]) {
                int v = node[0];
                int w = node[1];
                if(dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
        
        return dis;
    }
};