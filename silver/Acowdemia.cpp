#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	int n, k, L; cin >> n >> k >> L;
	
	vector<int> c(n);
	
	for(auto &x : c) cin >> x;
	
	sort(all(c), greater<>());
	
	auto check = [&](int h) {
		int cnt = 0, cur = k;
		
		for(int i = 0; i < h; i++) {
			int x = max(0ll, h - c[i]);
			
			if(x > k) return false;
			
			if(cur + x > k) {
				cnt++;
				cur = cur + x - k;
			} else {
				cur += x;
			}
		}
		
		return cnt <= L;
	};
	
	int l = 0, r = n;
	
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
