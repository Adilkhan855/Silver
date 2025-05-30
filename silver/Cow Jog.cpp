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
	int n, t; cin >> n >> t;
	vector<int> a;
	for(int i = 0; i < n; i++) {
		int x, v; cin >> x >> v;
		a.pb(x + v * t);
	}
	int ans = 1, mn = a.back();
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] < mn) {
			ans++;
			mn = a[i];
		}
	}
	cout << ans << nl;
}

signed main() {
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
