#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 1e9;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	
	vector a(m, vector(k, 0));
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < k; j++) cin >> a[i][j];
	}
	
	vector<int> ans(m), val(m), b(m);
	
	stack<array<int, 2>> st;
	
	int cur = n;
	
	for(int i = 0; i < m; i++) {
		array<int, 2> mn{inf, inf}, mx{-inf, -inf};
		
		for(int j = 0; j < k; j++) {
			int f = (a[i][j] & 1);
			mn[f] = min(mn[f], a[i][j]);
			mx[f] = max(mx[f], a[i][j]);
		}
		
		assert( !(mn[0] == inf && mn[1] == inf) );
		
		int even, odd;
		
		if(mn[0] != inf && mn[1] != inf) {
			// cout << '1' << '\n';
			even = -mx[1];
			odd = -mx[0];
		} else if(mn[1] != inf) {
			// cout << '2' << '\n';
			even = -mx[1];
			odd = mn[1];
		} else {
			// cout << '3' << '\n';
			even = mn[0];
			odd = -mx[0];
		}
		
		// cout << '\n';
		
		// cout << even << ' ' << odd << '\n';
		// cout << mn[0] << ' ' << mn[1] << '\n';
		
		assert( even != odd );
		
		if(even > odd) {
			cur += even;	
		} else {
			cur += odd;
			ans[i] = true;
			val[i] = odd - even;
		}
		
		b[i] = cur;
		
		if(cur <= 0) {
			cout << -1 << '\n';
			return;
		}
	}
	
	vector<int> suf(m + 1, inf);
	
	for(int i = m - 1; i >= 0; i--) {
		suf[i] = min(suf[i + 1], b[i]);
	}
	
	int minus = 0;
	
	for(int i = 0; i < m; i++) {
		if(i) cout << ' ';
		if(ans[i] && suf[i] - (minus + val[i]) > 0) {
			minus += val[i];
			ans[i] = false;
		}
		cout << (ans[i] ? "Odd" : "Even");
	}
	
	// cout << '\n';
	
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while(tt--) solve();
}
