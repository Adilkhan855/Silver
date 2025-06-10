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

auto add_self(int &a, const int &b) {
	a = (a + b) % 12;
	if(a < 0) a += 12;
}

void solve() {
	setIO("clocktree");
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x, x--;
	
	vector<vector<int>> adj(n);
	
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	int ans = 0;
	
	for(int r = 0; r < n; r++) {
		auto s = a;
		auto dfs = [&](auto &&self, int v, int p) -> void {
			for(auto to : adj[v]) {
				if(to == p) continue;
				self(self, to, v);
				add_self(s[v], 11 - s[to]);
			}
		};
		dfs(dfs, r, -1);
		ans += (s[r] == 0 || s[r] == 1);
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
