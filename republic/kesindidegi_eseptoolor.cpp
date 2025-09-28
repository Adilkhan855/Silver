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

const int mod = 1e9 + 7, B = 450;

int binpow(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int inv(int a) {
	return binpow(a, mod - 2);
}

void add_self(int &a, const int &b) {
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
	// a = (a + b) % mod;
	// if(a < 0) a += mod;
}

struct Query {
	int l, r, i;
	bool operator < (const Query &other) {
		if(l / B != other.l / B) {
			return l / B < other.l / B;
		}
		return (l / B) & 1 ? r > other.r : r < other.r;
	}
};

void solve() {
	int n; cin >> n;
	
	string s; cin >> s;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	vector<int> prec_inv(n);
	
	for(int i = 0; i < n; i++) {
		if(s[i] == 'M') prec_inv[i] = inv(a[i]);
	}
	
	int q; cin >> q;
	
	vector<Query> b(q);
	
	for(int i = 0; i < q; i++) {
		cin >> b[i].l; b[i].l--;
	}
	
	for(int i = 0; i < q; i++) {
		cin >> b[i].r; b[i].r--;
		b[i].i = i;
	}
	
	sort(all(b));
	
	vector<int> ans(q);
	
	int res = 0, mul = 1, ql = 0, qr = -1;
	
	auto add_begin = [&](int i) {
		// cout << "add_begin: " << i + 1 << nl;
		if(s[i] == 'M') {
			mul = mul * a[i] % mod;
		} else if(s[i] == 'A') {
			add_self(res, a[i] * mul % mod);
		} else {
			add_self(res, -a[i] * mul % mod);
		}
	};
	
	auto add_end = [&](int i) {
		// cout << "add_end: " << i + 1 << nl;
		if(s[i] == 'M') {
			mul = mul * a[i] % mod;
			res = res * a[i] % mod;
		} else if(s[i] == 'A') {
			add_self(res, a[i]);
		} else {
			add_self(res, -a[i]);
		}
	};
	
	auto del_begin = [&](int i) {
		// cout << "del_begin: " << i + 1 << nl;
		if(s[i] == 'M') {
			mul = mul * prec_inv[i] % mod;
		} else if(s[i] == 'A') {
			add_self(res, -a[i] * mul % mod);
		} else {
			add_self(res, a[i] * mul % mod);
		}
	};
	
	auto del_end = [&](int i) {
		// cout << "del_end: " << i + 1 << nl;
		if(s[i] == 'M') {
			mul = mul * prec_inv[i] % mod;
			res = res * prec_inv[i] % mod;
		} else if(s[i] == 'A') {
			add_self(res, -a[i]);
		} else {
			add_self(res, a[i]);
		}
	};
	
	for(auto &[l, r, i] : b) {
		// cout << l + 1 << ' ' << r + 1 << ' ' << i + 1 << nl;
		while(ql > l) {
			add_begin(--ql);
		}
		while(ql < l) {
			del_begin(ql++);
		}
		while(qr < r) {
			add_end(++qr);
		}
		while(qr > r) {
			del_end(qr--);
		}
		// cout << res << ' ' << mul << nl;
		// cout << nl;
		ans[i] = (res + mul) % mod;
	}
	
	for(auto &x : ans) cout << x << ' ';
	cout << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
