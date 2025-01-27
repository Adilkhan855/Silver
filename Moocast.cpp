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
	setIO("moocast");
	
	int n; cin >> n;
	
	vector<int> x(n), y(n), p(n);
	
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> p[i];
	}
	
	auto check = [&](int i, int j) {
		return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= p[i] * p[i];
	};
	
	vector can(n, vector(n, false));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			can[i][j] = check(i, j);
		}
	}
	
	vector<int> used(n);
	
	auto dfs = [&](auto &&dfs, int v) -> int {
		if(used[v]) return 0;
		used[v] = true;
		
		int res = 1;
		for(int u = 0; u < n; u++) {
			if(can[v][u]) {
				res += dfs(dfs, u);
			}
		}
		return res;
	};
	
	int ans = 1;
	for(int i = 0; i < n; i++) {
		used.assign(n, 0);
		ans = max(ans, dfs(dfs, i));
	}
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
