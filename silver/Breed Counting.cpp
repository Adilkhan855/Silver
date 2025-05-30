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
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(auto &i : a) {
		cin >> i;
	}
	vector<array<int, 3>> pf(n + 1);
	for(int i = 0; i < n; i++) {
		pf[i + 1] = pf[i];
		pf[i + 1][a[i] - 1]++;
	}
	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		for(int j = 0; j < 3; j++) {
			cout << pf[r][j] - pf[l - 1][j];
			if(j < 2) cout << ' ';
		}
		cout << nl;
	}
}

signed main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
