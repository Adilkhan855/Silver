/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
	setIO("pails");
	int x, y, k, m; cin >> x >> y >> k >> m;
	
	map<pair<int, int>, int> dp;
	
	queue<pair<int, int>> q;
	
	q.emplace(0, 0);
	dp[{0, 0}] = 0;
	
	int ans = m;
	while(!q.empty()) {
		auto v = q.front();
		q.pop();
		
		if(dp[v] > k) continue;
		
		auto [a, b] = v;
		
		ans = min(ans, abs(m - (a + b)));
		
		vector<pair<int, int>> T;
		T.pb(0, b);
		T.pb(a, 0);
		T.pb(x, b);
		T.pb(a, y);
		T.pb(a + min(x - a, b), b - min(x - a, b));
		T.pb(a - min(y - b, a), b + min(y - b, a));
		
		for(auto u : T) {
			if(!dp.count(u)) {
				dp[u] = dp[v] + 1;
				q.emplace(u);
			}
		}
	}
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
