#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'
 
template <typename A, typename B>
bool chmin(A &a, const B &b) {
	if( a > b ) {
		return a = b, true;
	}
	return false;
}
 
template <typename A, typename B>
bool chmax(A &a, const B &b) {
	if( a < b ) {
		return a = b, true;
	}
	return false;
}

void solve() {
	freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);
	int n; cin >> n;
	
	vector<int> a(n), b(n);
	
	int mx = 0;
	
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		mx = max(mx, max(abs(a[i]), abs(b[i])));
	}
	
	auto f = [&](int y, bool flag) {
		int res = 0;
		for(int i = 0; i < n; i++) {
			res += min(abs(a[i] - b[i]), abs(a[i]) + abs(b[i] - y));
			if(flag) cout << min(abs(a[i] - b[i]), abs(a[i]) + abs(b[i] - y)) << ' ';
		}
		if(flag) cout << nl;
		return res;
	};
	
	int l = -mx, r = mx;
	
	for(int it = 0; it < 100; it++) {
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;
		
		int f1 = f(m1, 0), f2 = f(m2, 0);
		
		// cout << nl;
		// cout << m1 << ' ' << m2 << nl;
		// cout << f1 << ' ' << f2 << nl;
		// cout << nl;
		
		if(f1 < f2) {
			r = m2;
			// l = m1;
		} else {
			l = m1;
			// r = m2;
		}
	}
	
	cout << f(l, 0) << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
