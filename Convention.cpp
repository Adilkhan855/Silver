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
	setIO("convention");
	int n, m, c; cin >> n >> m >> c;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	sort(all(a));
	
	auto check = [&](int x) {
		int cnt = 0;
		for(int i = 0, j = 0; i < n; ) {
			while(j < n && a[j] - a[i] <= x && j - i + 1 <= c) {
				j++;
			}
			cnt++;
			i = j;
		}
		return cnt <= m;
	};
	
	int l = 0, r = a.back() - a[0];
	
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	
	cout << r << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
