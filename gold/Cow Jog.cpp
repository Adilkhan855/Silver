#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

using ll = long long;

struct segtree {
	int n;
	
	vector<ll> t;
	
	segtree(int n) : n(n), t(n << 2, -1) {}
	
	void update(int v, int l, int r, int i, ll x) {
		// cout << v << ' ' << l << ' ' << r << ' ' << i << ' ' << x << nl;
		
		if(l == r) {
			t[v] = x;
			return;
		}
		
		int m = (l + r) >> 1;
		
		if(i <= m) update(v << 1, l, m, i, x);
		else update(v << 1 | 1, m + 1, r, i, x);
		
		t[v] = max(t[v << 1], t[v << 1 | 1]);
	}
	
	void update(int i, ll x) {
		update(1, 0, n - 1, i, x);
	}
	
	int find(int v, int l, int r, int ql, int qr, ll x) {
		if(l > qr || ql > r || t[v] <= x) return -1;
		
		if(l == r) return l;
		
		int m = (l + r) >> 1;
		
		int left = find(v << 1, l, m, ql, qr, x);
		
		if(left != -1) return left;
		
		return find(v << 1 | 1, m + 1, r, ql, qr, x);
	}
	
	int find(int l, int r, ll x) {
		return find(1, 0, n - 1, l, r, x);
	}
};

void solve() {
	int n, T; cin >> n >> T;
	
	vector<ll> a(n);
	
	segtree t(n);
	
	for(int i = 0; i < n; i++) {
		int x, v; cin >> x >> v;
		
		a[i] = x + T * 1LL * v;
		
		t.update(i, a[i]);
	}
	
	int ans = 0;
	
	while(true) {
		int cur = t.find(0, n - 1, -1);
		
		if(cur == -1) break;
		
		ans++;
		
		while(cur != -1) {
			t.update(cur, -1);
			
			cur = t.find(cur, n - 1, a[cur]);
		}
	}
	
	cout << ans << nl;
}

signed main() {
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
