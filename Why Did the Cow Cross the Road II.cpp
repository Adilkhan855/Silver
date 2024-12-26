/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define int i64

void solve() {
	int n, k, b; cin >> n >> k >> b;
	vector<int> a(b);
	for(auto &i : a) {
		cin >> i;
	}
	int ans = n;
	{ // easy approach, but not for big a[i]
		
		vector<int> pref(n + 1);
		for(auto i : a) pref[i] = 1;
		
		for(int i = 0; i < n; i++) pref[i + 1] += pref[i];
		
		for(int i = 0; i + k <= n; i++) {
			ans = min(ans, pref[i + k] - pref[i]);
		}
		
	}
	sort(a.begin(), a.end());
	int j = 0;
	while(j < b && a[j] <= k) {
		j++;
	}
	ans = j;
	for(int i = 0; i < b; i++) {
		if(a[i] + k > n) break;
		
		while(j < b && a[j] <= a[i] + k) {
			j++;
		}
		ans = min(ans, j - 1 - i);
	}
	cout << ans << '\n';
}

signed main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
