/*
 *    author: a.k
 *    created: idk
*/
#include <bits/stdc++.h> 
using namespace std;
 
#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define nl '\n'

void solve() {
	int B, E, P, N, M; cin >> B >> E >> P >> N >> M;
	vector<vector<int>> G(N + 1);
	
	for(int j = 0; j < M; j++) {
		int a, b; cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	
	auto bfs = [&](int st) {
		vector<int> d(N + 1, 1e9);
		queue<int> q;
		q.push(st);
		d[st] = 0;
		while(!q.empty()) {
			auto v = q.front();
			q.pop();
			for(auto to : G[v]) {
				if(d[to] > d[v] + 1) {
					d[to] = d[v] + 1;
					q.push(to);
				}
			}
		}
		return d;
	};
	vector<int> d1 = bfs(1);
	vector<int> d2 = bfs(2);
	vector<int> d = bfs(N);
	
	int ans = d1[N] * B + d2[N] * E;
	for(int v = 1; v <= N; v++) {
		ans = min(ans, d1[v] * B + d2[v] * E + d[v] * P);
	}
	cout << ans << nl;
}
 
signed main() {
	freopen("piggyback.in", "r", stdin);
	freopen("piggyback.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
