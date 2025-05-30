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

const int mxD = 100 * 100;
void solve() {
	int n, m; cin >> n >> m;
	
	vector A(n, vector(n, 0ll));
	vector B(n, vector(n, 0ll));
	for(int j = 0; j < m; j++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--;
		A[a][b] = c;
		B[a][b] = d;
	}
	
	auto can = [&](vector<vector<int>> &dis) {
		vector dp(n, vector(mxD + 1, 0));
		dp[0][0] = 1;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				if(dis[i][j]) {
					for(int k = mxD; k >= dis[i][j]; k--) {
						dp[j][k] |= dp[i][k - dis[i][j]];
					}
				}
			}
		}
		return dp[n - 1];
	};
	auto canA = can(A);
	auto canB = can(B);
	
	for(int k = 0; k <= mxD; k++) {
		if(canA[k] && canB[k]) {
			cout << k << nl;
			return;
		}
	}
	cout << "IMPOSSIBLE" << nl;
}

signed main() {
	freopen("meeting.in", "r", stdin);
	freopen("meeting.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
