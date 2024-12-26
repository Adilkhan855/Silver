/*
 *    author: a.k
 *    created: idk
*/
#include <bits/stdc++.h> 
using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mod = 1e9 + 7;
void solve() {
	setIO("hopscotch");
	
	int n, m, k; cin >> n >> m >> k;
	vector a(n, vector(m, 0ll));
	for(auto &i : a) {
		for(auto &j : i) cin >> j;
	}
	vector dp(n, vector(m, 0ll));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			for(int i1 = i + 1; i1 < n; i1++) {
				for(int j1 = j + 1; j1 < m; j1++) {
					if(a[i][j] != a[i1][j1]) {
						dp[i1][j1] = (dp[i1][j1] + dp[i][j]) % mod;
					}
				}
			}
		}
	}
	cout << dp[n - 1][m - 1] << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
