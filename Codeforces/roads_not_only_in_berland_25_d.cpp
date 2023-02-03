// problem link
// https://codeforces.com/contest/25/problem/D

#include<bits/stdc++.h>
using namespace std;

const int mxn = 1e3+2;
int parent[mxn];
int tree_size[mxn];

void make_set(int v) {
	parent[v] = v;
	tree_size[v] = 1;
}

int find_root(int v) {
	if(v == parent[v]) return v;  // root found
	int root = find_root(parent[v]);
	parent[v] = root;
	return root;
}

bool union_sets(int a, int b) {
	int a_root = find_root(a);
	int b_root = find_root(b);
	if(a_root != b_root) {
		if(tree_size[a_root] < tree_size[b_root]) swap(a_root,b_root);
		parent[b_root] = a_root;
		tree_size[a_root] += tree_size[b_root];
		return false;
	}
	return true;
}


int main() {
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) make_set(i);
	vector<vector<int>> waste;
	for(int i=0; i<n-1; i++) {
		int u,v;
		cin >> u >> v;
		if(union_sets(u,v)) {
			waste.push_back({u, v});
		}
	}

	int cur = 2;

	unordered_map<int,int> vis;
	int u = find_root(1);
	vis[u] = 1;

	cout << (int)waste.size() << endl;
	for(auto &x: waste) {
		cout << x[0] << ' ' << x[1];
		while(cur <= n) {
			if(!vis[find_root(cur)]) {
				cout << ' ' << u << ' ' << find_root(cur) << endl;
				vis[find_root(cur)] = 1;
				break;
			}
			++cur;
		}
	}

	return 0;
}