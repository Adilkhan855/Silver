/*
 *    author: a.k
 *    created: idk
*/
#include <bits/stdc++.h> 
using namespace std;

using i64 = long long;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
	setIO("buffet");
	int n, E; cin >> n >> E;
	vector<vector<int>> g(n);
	vector<int> Q(n), P(n);
	for(int i = 0; i < n; i++) {
		P[i] = i;
		int len; cin >> Q[i] >> len;
		for(int j = 0; j < len; j++) {
			int v; cin >> v;
			g[i].emplace_back(v - 1);
		}
	}
	sort(P.begin(), P.end(), [&](int x, int y) {
		return Q[x] > Q[y];
	});
	vector<int> dp(n);
	for(int i = 0; i < n; i++) {
		int u = P[i];
		
		vector<int> d(n, -1);
		queue<int> q;
		q.emplace(u);
		d[u] = 0;
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			for(auto to : g[v]) {
				if(d[to] == -1) {
					d[to] = d[v] + 1;
					q.emplace(to);
				}
			}
		}
		dp[u] = Q[u];
		for(int j = 0; j < n; j++) {
			if(j == u) continue;
			if(d[j] != -1) {
				dp[u] = max(dp[u], dp[j] + Q[u] - E * d[j]);
			}
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
