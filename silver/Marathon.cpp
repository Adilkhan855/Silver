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
	int n, k; cin >> n >> k;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	
	const int inf = 1e9;
	vector dp(k + 1, vector(n, inf));
		
	dp[0][0] = 0;
	auto dist = [&](int i, int j) {
		return abs(x[i] - x[j]) + abs(y[i] - y[j]);
	};
	auto chmin = [&](int &a, int b) {
		if(a > b) a = b;
	};
	
	for(int i = 0; i <= k; i++) {
		for(int j = 0; j < n; j++) {
			for(int l = j + 1; l < n && i + (l - j - 1) <= k; l++) {
				chmin(dp[i + (l - j - 1)][l], dp[i][j] + dist(l, j));
			}
		}
	}
	cout << dp[k][n - 1] << nl;
}

signed main() {
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
