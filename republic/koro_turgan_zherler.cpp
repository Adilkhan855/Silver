#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 1e18 + 5;

struct line {
	ll m, b;
	
	line() : m(0), b(-inf) {}
	
	line(ll m, ll b) : m(m), b(b) {}
	
	ll operator * (const int &x) {
		return m * x + b;
	}
};

struct LiChao {
	int n;
	
	vector<int> q;
	
	vector<line> t;
	
	LiChao(const vector<int> &a) : n(a.size()), q(a), t(n << 2) {
		sort(q.begin(), q.end());
	}
	
	void add(int v, int l, int r, line x) {
		int m = (l + r) >> 1;
		
		if(t[v] * q[m] < x * q[m]) {
			swap(t[v], x);
		}
		
		if(l == r) return;
		
		if(t[v] * q[l] < x * q[l]) {
			add(v << 1, l, m, x);
		} else {
			add(v << 1 | 1, m + 1, r, x);
		}
	}
	
	void add(line x) {
		add(1, 0, n - 1, x);
	}
	
	ll get(int v, int l, int r, int i) {
		if(l == r) return t[v] * q[i];
		
		int m = (l + r) >> 1;
		
		if(i <= m) return max(t[v] * q[i], get(v << 1, l, m, i));
		else return max(t[v] * q[i], get(v << 1 | 1, m + 1, r, i));
	}
	
	ll get(int x) {
		return get(1, 0, n - 1, lower_bound(q.begin(), q.end(), x) - q.begin());
	}
};

void solve() {
	int n, d; cin >> n >> d;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	vector<ll> suf(n + 1);
	
	for(int i = n - 1; i >= 0; i--) {
		suf[i] = suf[i + 1] + (a[i] - d) * 1LL * (a[i] - d);
	}
	
	vector<ll> dp(n, inf);
	
	dp[0] = 0;
	
	LiChao t(a);
	
	t.add( line(-2 * a[0], a[0] * 1LL * a[0] + suf[1]) );
	
	for(int i = 1; i < n; i++) {
		 dp[i] = t.get(a[i]) + a[i] * 1LL * a[i] - suf[i];
		 t.add( line(-2 * a[i], a[i] * 1LL * a[i] + dp[i] + suf[i + 1]) );
	}
	
	// for(int i = 0; i < n; i++) {
		// cout << dp[i] << ' ';
	// }
	
	// cout << '\n';
	
	cout << dp[n - 1] << '\n';
}

/**
6 3
5 1 6 5 0 1

6 -1
4 4 1 1 5 9

**/

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
