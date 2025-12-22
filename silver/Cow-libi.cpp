#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lint = __int128;

void solve() {
	int n, m; cin >> n >> m;
	
	vector<int> x(n), y(n), t(n);
	
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> t[i];
	}
	
	vector<int> idx(n);
	
	iota(idx.begin(), idx.end(), 0);
	
	sort(idx.begin(), idx.end(), [&](const int &i, const int &j) {
		return t[i] < t[j];
	});
	
	auto _x = x, _y = y, _t = t;
	
	for(int i = 0; i < n; i++) {
		x[i] = _x[idx[i]];
		y[i] = _y[idx[i]];
		t[i] = _t[idx[i]];
	}
	
	auto check = [](int x, int y, int t) {
		return x * lint(1) * x + y * lint(1) * y <= t * lint(1) * t;
	};
	
	int ans = m;
	
	for(int i = 0; i < m; i++) {
		int xc, yc, tc; cin >> xc >> yc >> tc;
		
		int j = upper_bound(t.begin(), t.end(), tc) - t.begin();
		
		int ok = true;
		
		if(j < n) {
			ok &= check(xc - x[j], yc - y[j], tc - t[j]);
		}
		
		j--;
		
		if(j >= 0) {
			ok &= check(xc - x[j], yc - y[j], tc - t[j]);
		}
		
		ans -= ok;
	}
	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
