#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> merge(const vector<int> &a, const vector<int> &b) {
	vector<int> c;
	
	c.reserve(a.size() + b.size());
	
	int i = 0, j = 0;
	
	while(i < (int)a.size() && j < (int)b.size()) {
		if(a[i] < b[j]) {
			c.push_back(a[i++]);
		} else {
			c.push_back(b[j++]);
		}
	}
	
	while(i < (int)a.size()) c.push_back(a[i++]);
	
	while(j < (int)b.size()) c.push_back(b[j++]);
	
	return c;
}

struct segtree {
	int n;
	
	vector<ll> ans;
	
	vector<int> p;
	
	vector<vector<int>> t;
	
	vector<vector<ll>> pt;
	
	segtree(const vector<int> &a) : n(a.size()), ans(n << 2), p(n << 2, -1), t(n << 2), pt(n << 2) {
		build(1, 0, n - 1, a);
	}
	
	void build(int v, int l, int r, const vector<int> &a) {
		if(l == r) {
			ans[v] = a[l];
			t[v].push_back(a[l]);
			pt[v].push_back(0);
			pt[v].push_back(a[l]);
			return;
		}
		
		int m = (l + r) >> 1;
		
		build(v << 1, l, m, a);
		build(v << 1 | 1, m + 1, r, a);
		
		ans[v] = ans[v << 1] + ans[v << 1 | 1];
		
		t[v] = merge(t[v << 1], t[v << 1 | 1]);
		
		pt[v].resize(t[v].size() + 1);
		
		for(int i = 0; i < (int)t[v].size(); i++) {
			pt[v][i + 1] = pt[v][i] + t[v][i];
		}
	}
	
	void push(int v, int l, int r) {
		if(p[v] == -1) return;
		
		int j = upper_bound(t[v].begin(), t[v].end(), p[v]) - t[v].begin();
		
		// cout << '\n';
		
		// cout << "cur: " << v << ' ' << l << ' ' << r << ' ' << p[v] << ' ' << j << '\n';
		
		ans[v] = pt[v][j] + p[v] * 1LL * ((ll)t[v].size() - j);
		
		// cout << "res: " << ans[v] << '\n';
		
		// cout << '\n';
		
		if(l != r) {
			p[v << 1] = p[v];
			p[v << 1 | 1] = p[v];
		}
		
		p[v] = -1;
	}
	
	void update(int v, int l, int r, int ql, int qr, int x) {
		push(v, l, r);
		
		if(l > qr || ql > r) return;
		
		if(l >= ql && r <= qr) {
			p[v] = x;
			push(v, l, r);
			return;
		}
		
		int m = (l + r) >> 1;
		
		update(v << 1, l, m, ql, qr, x);
		update(v << 1 | 1, m + 1, r, ql, qr, x);
		
		ans[v] = ans[v << 1] + ans[v << 1 | 1];
	}
	
	void update(int l, int r, int x) {
		update(1, 0, n - 1, l, r, x);
	}
	
	ll get() {
		push(1, 0, n - 1);
		return ans[1];
	}
};

void solve() {
	int n, q; cin >> n >> q;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	segtree t(a);
	
	while(q--) {
		int l, r, x; cin >> l >> r >> x;
		
		l--, r--;
		
		t.update(l, r, x);
		
		cout << t.get() << '\n';
	}
}

/**
1 3
100
1 1 50
1 1 120
1 1 0

4 5
1 5 7 3
1 3 1
2 4 2
2 3 5
1 4 3
3 4 100

**/

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
