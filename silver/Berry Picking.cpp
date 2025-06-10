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
	setIO("berries");
	int n, k; cin >> n >> k;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	int M = *max_element(all(a)), ans = 0;
	
	for(int b = 1; b <= M; b++) {
		int cnt = 0;
		for(auto x : a) cnt += x / b;
		if(cnt < k / 2) continue;
		if(cnt >= k) {
			chmax(ans, b * (k / 2));
			continue;
		}
		int cur = b * (cnt - k / 2);
		sort(all(a), [&](int a1, int a2) {
			return a1 % b > a2 % b;
		});
		for(int i = 0; i < n && i + cnt < k; i++) {
			cur += a[i] % b;
		}
		chmax(ans, cur);
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
