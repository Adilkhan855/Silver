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
	setIO("milkvisits");
	int n, m; cin >> n >> m;
	
	string s; cin >> s;
	
	vector<vector<int>> adj(n);
	
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	vector<vector<int>> jmp(n, vector<int>(20)), H(n, vector<int>(20)), G(n, vector<int>(20));
	
	vector<int> d(n), tin(n), tout(n);
	
	int timer = 0;
	
	auto dfs = [&](auto &&self, int v, int p) -> void {
		d[v] = d[p] + 1;
		jmp[v][0] = p;
		H[v][0] = (s[v] == 'H');
		G[v][0] = (s[v] == 'G');
		for(int i = 1; i < 20; i++) {
			jmp[v][i] = jmp[ jmp[v][i - 1] ][i - 1];
			H[v][i] = (H[v][i - 1] | H[ jmp[v][i - 1] ][i - 1]);
			G[v][i] = (G[v][i - 1] | G[ jmp[v][i - 1] ][i - 1]);
		}
		
		tin[v] = ++timer;
		
		for(auto to : adj[v]) {
			if(to == p) continue;
			self(self, to, v);
		}
		
		tout[v] = timer;
	};
	
	dfs(dfs, 0, 0);
	
	auto upper = [&](int u, int v) {
		return tin[v] >= tin[u] && tout[v] <= tout[u];
	};
	
	auto lca = [&](int u, int v) {
		if(upper(u, v)) return u;
		if(upper(v, u)) return v;
		for(int i = 19; i >= 0; i--) {
			if(!upper(jmp[u][i], v)) u = jmp[u][i];
		}
		return jmp[u][0];
	};
	
	auto is = [&](int u, int v, char c) {
		int is_H = H[v][0], is_G = G[v][0], dist = d[u] - d[v];
		for(int i = 0; i < 20; i++) {
			if(dist >> i & 1) {
				is_H |= H[u][i];
				is_G |= G[u][i];
				u = jmp[u][i];
			}
		}
		while(u != v);
		return c == 'H' ? is_H : is_G;
	};
	
	while(m--) {
		int u, v; char c; cin >> u >> v >> c;
		u--, v--;
		int lc = lca(u, v);
		cout << (is(u, lc, c) || is(v, lc, c));
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
