/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
	setIO("cbarn");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<int> a(n);
	
	int c = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		c = max(0ll, c + a[i] - 1);
	}
	
	for(int i = 0; ; i++) {
		if(c == 0) {
			rotate(a.begin(), a.begin() + i, a.begin() + n);
			break;
		}
		c = max(0ll, c + a[i] - 1);
	}
	
	auto sumn2 = [&](int n) {
		return n * (n + 1) * (2 * n + 1) / 6;
	};
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += sumn2(a[i] + c - 1) - sumn2(c - 1);
		c = max(0ll, c + a[i] - 1);
	}
	cout << ans << nl;
}
