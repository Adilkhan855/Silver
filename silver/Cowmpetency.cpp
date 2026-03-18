#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
	int n, q, C; cin >> n >> q >> C;
	
	vector<int> c(n), nus(n);
	
	for(int i = 0; i < n; i++) {
		cin >> c[i];
		
		if(c[i] == 0) {
			nus[i] = true;
			c[i] = 1;
		}
	}
	
	vector<int> mn(n, n);
	
	for(int i = 0; i < q; i++) {
		int a, h; cin >> a >> h;
		a--, h--;
		mn[h] = min(mn[h], a);
	}
	
	vector<array<int, 2>> cond;
	
	for(int i = 0; i < n; i++) {
		if(mn[i] < i) {
			cond.push_back({mn[i], i});
		}
	}
	
	sort(cond.begin(), cond.end());
	
	// for(auto &x : c) cout << x << ' ';
	// cout << '\n';
	
	int mx = 0, mx1 = 0, mx2 = 0, j1 = 0, j2 = 0;
	
	for(int i = 0; i < (int)cond.size(); i++) {
		auto [a, h] = cond[i];
		
		if(mx > a) {
			cout << -1 << '\n';
			return;
		}
		
		while(j1 <= a) {
			mx1 = max(mx1, c[j1]);
			j1++;
		}
		
		while(j2 < h) {
			mx2 = max(mx2, c[j2]);
			j2++;
		}
		
		if(mx2 > mx1) {
			bool flag = false;
			for(int j = a; j >= mx; j--) {
				if(nus[j]) {
					c[j] = mx2;
					nus[j] = false;
					flag = true;
					break;
				}
			}
			
			if(!flag) {
				// cout << -2 << ' ' << mx + 1 << ' ' << a + 1 << '\n';
				cout << -1 << '\n';
				return;
			}
			
			mx1 = mx2;
		}
		
		if(nus[h]) {
			c[h] = mx1 + 1;
		}
		
		if(c[h] <= mx1) {
			// cout << -3 << '\n';
			cout << -1 << '\n';
			return;
		}
		
		mx = max(mx, h);
		
	}
	
	for(int i = 0; i < n; i++) {
		if(c[i] > C) {
			// cout << -4 << '\n';
			cout << -1 << '\n';
			return;
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(i) cout << ' ';
		cout << c[i];
	}
	
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while(tt--) solve();
}
