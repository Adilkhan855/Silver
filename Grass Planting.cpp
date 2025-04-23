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

void solve() {
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
	int n; cin >> n;
	
	vector<vector<int>> adj(n);
	
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		ans = max(ans, (int)adj[i].size() + 1);
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
