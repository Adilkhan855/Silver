#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

template <typename A, typename B>
bool chmin(A &a, const B &b) {
	if(a > b) {
		return a = b, true;
	}
	return false;
}

template <typename A, typename B>
bool chmax(A &a, const B &b) {
	if(a < b) {
		return a = b, true;
	}
	return false;
}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
	setIO("fenceplan");
	int n, m; cin >> n >> m;
	
	vector<int> x(n), y(n);
	
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	
	vector<vector<int>> adj(n);
	
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	vector<int> used(n), ms(4);
	
	auto reset = [&]() {
		ms[0] = ms[1] = 1e18;
		ms[2] = ms[3] = -1e18;
	};
	
	auto dfs = [&](auto &&self, int v) -> void {
		used[v] = 1;
		chmin(ms[0], x[v]);
		chmin(ms[1], y[v]);
		chmax(ms[2], x[v]);
		chmax(ms[3], y[v]);
		for(auto to : adj[v]) {
			if(!used[to]) self(self, to);
		}
	};
	
	int ans = 1e18;
	
	for(int i = 0; i < n; i++) {
		if(!used[i]) {
			reset();
			dfs(dfs, i);
			ans = min(ans, 2 * (ms[2] - ms[0]) + 2 * (ms[3] - ms[1]));
		}
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
