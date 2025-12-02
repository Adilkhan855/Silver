#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct fenw {
	int n; vector<i64> bit;
	
	fenw(int n) : n(n), bit(n + 1) {}
	
	void add(int i, i64 x) {
		for(i++; i <= n; i += i & -i) bit[i] += x;
	}
	
	i64 get(int i) {
		i64 res = 0;
		for(i++; i >= 1; i -= i & -i) res += bit[i];
		return res;
	}
	
	i64 get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

void solve() {
	int n; cin >> n;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	auto b = a;
	
	int q; cin >> q;
	
	vector<array<int, 2>> qs(q);
	
	for(auto &[i, j] : qs) {
		cin >> i >> j;
		i--;
		b.push_back(j);
	}
	
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	
	auto idx = [&](int x) {
		return lower_bound(b.begin(), b.end(), x) - b.begin();
	};
	
	int m = b.size();
	
	fenw sum(m), cnt(m);
	
	for(auto &x : a) {
		sum.add( idx(x), x );
		cnt.add( idx(x), 1 );
	}
	
	vector<int> srt(n);
	
	iota(srt.begin(), srt.end(), 0);
	
	sort(srt.begin(), srt.end(), [&](const int &i, const int &j) {
		return a[i] < a[j];
	});
	
	vector<int> c(n);
	
	i64 T = 0;
	
	for(int i = 0; i < n; i++) {
		T += a[srt[i]] * 1ll * (i + 1);
		c[i] = a[srt[i]];
	}
	
	auto ord = [&](int x) {
		return lower_bound(c.begin(), c.end(), x) - c.begin();
	};
	
	for(auto &[i, j] : qs) {
		i64 nt = T;
		
		sum.add( idx(a[i]), -a[i] );
		cnt.add( idx(a[i]), -1 );
		
		nt -= a[i] * 1ll * (ord(a[i]) + 1);
		nt -= sum.get( idx(a[i]), m );
		
		nt += j * 1ll * (cnt.get( idx(j) ) + 1);
		nt += sum.get( idx(j) + 1, m );
		
		sum.add( idx(a[i]), a[i] );
		cnt.add( idx(a[i]), 1 );
		
		cout << nt << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
