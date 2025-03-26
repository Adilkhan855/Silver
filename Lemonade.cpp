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
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	sort(all(a), greater<>());
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		ans += (a[i] >= i);
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
