#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

template <typename A, typename B>
bool chmin(A &a, const B &b) {
	if(a > b) {
		return a = b, true;
	}
	return false;
}

template <typename A, typename B>
bool chmax(A &a, const B &b) {
	if(a < b) {
		return a = b, true;
	}
	return false;
}

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
	setIO("loan");
	int n, K, m; cin >> n >> K >> m;
	
	auto check = [&](int x) {
		int g = 0, k = K;
		while(k > 0 && g < n) {
			int y = (n - g) / x;
			if(y < m) {
				return (n - g + m - 1) / m <= k;
			}
			int q = (n - g - x * y) / y + 1;
			if(q > k) q = k;
			g += y * q;
			k -= q;
		}
		return g >= n;
	};
	
	int l = 1, r = 1e12;
	
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	
	cout << l << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
