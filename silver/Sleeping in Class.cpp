#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void chmin(int &a, const int &b) {
	if(a > b) a = b;
}

void solve() {
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	int sum = accumulate(all(a), 0ll);
	
	if(sum == 0) {
		cout << 0 << nl;
		return;
	}
	
	vector<int> pref(n + 1), last(sum + 1, -1);
	
	for(int i = 0; i < n; i++) {
		pref[i + 1] = pref[i] + a[i];
		last[pref[i + 1]] = i + 1;
	}
	
	int ans = n - 1;
	
	for(int i = 1; i <= sum; i++) {
		if(sum % i) continue;
		int cur = 0, res = 0, flag = true;
		for(int j = i; j <= sum; j += i) {
			if(last[j] == -1) {
				flag = false;
				break;
			}
			res += last[j] - cur - 1;
			cur = last[j];
		}
		if(flag) {
			if(ans > res) {
				// cout << i << ": " << res << nl;
				ans = res;
			}
		}
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while(tt--) solve();
}
