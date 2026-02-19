#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct fenw {
	int n; vector<int> bit;
	
	fenw(int size) : n(size + 2), bit(n + 1) {}
	
	void update(int i, int x) {
		for(i += 2; i <= n; i += i & -i) bit[i] += x;
	}
	
	int get(int i) {
		int res = 0;
		for(i += 2; i >= 1; i -= i & -i) res += bit[i];
		return res;
	}
};

void solve() {
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &x : a) {
		cin >> x;
		x--;
	}
	
	vector<int> mp(n, -1), prev(n);
	
	for(int i = 0; i < n; i++) {
		prev[i] = mp[a[i]];
		mp[a[i]] = i;
	}
	
	mp.assign(n, n);
	
	vector<int> next(n);
	
	for(int i = n - 1; i >= 0; i--) {
		next[i] = mp[a[i]];
		mp[a[i]] = i;
	}
	
	vector<array<int, 3>> qrs;
	
	for(int i = 0; i < n; i++) {
		qrs.push_back({i, i, 1});
		qrs.push_back({next[i] - 1, i, -1});
	}
	
	sort(qrs.begin(), qrs.end());
	
	fenw fn(n);
	
	ll ans = 0;
	
	for(int i = (int)qrs.size() - 1, j = n - 1; i >= 0; i--) {
		while(j >= 0 && j > qrs[i][0]) {
			fn.update(prev[j], 1);
			j--;
		}
		
		// cout << qrs[i][0] << ' ' << qrs[i][1] << ' ' << qrs[i][2] << ' ' << fn.get(qrs[i][1] - 1) << '\n';
		
		ans += fn.get(qrs[i][1] - 1) * qrs[i][2];
	}
	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
