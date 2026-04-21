#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

using ll = long long;

const int inf = 1e9 + 5;

void dfs(int v, vector<int> &used, vector<int> &out, const vector<vector<int>> &adj) {
	used[v] = true;
	
	for(auto to : adj[v]) {
		if(!used[to]) {
			dfs(to, used, out, adj);
		}
	}
	
	out.push_back(v);
}

bool chmax(int &a, const int &b) {
	return a < b ? a = b, true : false;
}

void solve() {
	int n, m; cin >> n >> m;
	
	vector<vector<int>> adj(n), radj(n);
	
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		
		u--, v--;
		
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	
	vector<int> used(n), order;
	
	for(int i = 0; i < n; i++) {
		if(!used[i]) {
			dfs(i, used, order, adj);
		}
	}
	
	fill(used.begin(), used.end(), false);
	
	reverse(order.begin(), order.end());
	
	vector<int> root(n), sz(n);
	
	for(auto v : order) {
		if(used[v]) continue;
		
		vector<int> here;
		
		dfs(v, used, here, radj);
		
		sz[v] = here.size();
		
		// cout << "here: " << nl;
		
		for(auto u : here) {
			root[u] = v;
			// cout << u + 1 << ' ';
		}
		
		// cout << nl;
	}
	
	vector<int> dp2(n, -inf);
	
	dp2[root[0]] = sz[0];
	
	for(auto v : order) {
		for(auto to : adj[v]) {
			if(root[to] == root[v]) continue;
			
			chmax(dp2[root[to]], dp2[root[v]] + sz[root[to]]);
		}
	}
	
	reverse(order.begin(), order.end());
	
	vector<int> dp(n, -inf);
	
	dp[root[0]] = 0;
	
	for(auto v : order) {
		for(auto to : radj[v]) {
			if(root[to] == root[v]) continue;
			
			chmax(dp[root[to]], dp[root[v]] + sz[root[to]]);
		}
	}
	
	// cout << "root: " << nl;
	
	// for(int i = 0; i < n; i++) {
		// cout << root[i] << ' ';
	// }
	
	// cout << nl;
	
	// cout << "dp: " << nl;
	
	// for(int i = 0; i < n; i++) {
		// cout << dp[i] << ' ';
	// }
	
	// cout << nl;
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		int mx = -inf;
		
		// cout << i + 1 << ": ";
		
		for(auto v : radj[i]) {
			chmax(mx, dp[root[v]]);
		}
		
		// cout << mx << nl;
		
		chmax(ans, dp2[root[i]] + mx);
	}
	
	cout << ans << nl;
}

signed main() {
	freopen("grass.in", "r", stdin);
	freopen("grass.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
