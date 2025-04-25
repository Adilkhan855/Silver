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
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
	int n, m; cin >> n >> m;
	
	vector<vector<int>> s(n), d(n);
	
	for(int i = 0; i < m; i++) {
		char c; int u, v; cin >> c >> u >> v;
		u--, v--;
		if(c == 'S') s[u].pb(v), s[v].pb(u);
		else d[u].pb(v), d[v].pb(u);
	}
	
	vector<int> used(n);
	
	auto dfs = [&](auto &&self, int v, int cur) -> void {
		used[v] = cur;
		for(auto to : s[v]) {
			if(used[to] == 3 - cur) {
				cout << "0" << nl;
				exit(0);
			}
			if(!used[to]) self(self, to, cur);
		}
		for(auto to : d[v]) {
			if(used[to] == cur) {
				cout << "0" << nl;
				exit(0);
			}
			if(!used[to]) self(self, to, 3 - cur);
		}
	};
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		if(!used[i]) dfs(dfs, i, 1), ans++;
	}
	
	cout << "1" + string(ans, '0') << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
