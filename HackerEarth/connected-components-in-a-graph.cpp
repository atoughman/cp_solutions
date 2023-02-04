// problem link
// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

#include<bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int> adj[], bool vis[]) {
	vis[u] = true;
	for(auto &v: adj[u]) if(!vis[v]) dfs(v, adj, vis);
}

int main() {
	int n,m;
	cin >> n >> m;
	int ans = 0;
	vector<int> adj[n+1];
	bool vis[n+1];

	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(vis, false, sizeof(vis));

	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			++ans;
			dfs(i, adj, vis);
		}
	}

	cout << ans << endl;
	return 0;
}