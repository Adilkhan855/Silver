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

void solve() {
	setIO("superbull");
	int n; cin >> n;
	vector<int> a(n);
	for(auto &i : a) {
		cin >> i;
	}
	vector used(n, false);
	vector d(n, 0ll);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int v = -1;
		for(int j = 0; j < n; j++) {
			if(!used[j] && (v == -1 || d[v] < d[j])) {
				v = j;
			}
		}
		ans += d[v];
		used[v] = true;
		for(int j = 0; j < n; j++) {
			d[j] = max(d[j], (long long)(a[j] ^ a[v]));
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
