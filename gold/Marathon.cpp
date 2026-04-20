#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

using ll = long long;

const int N = 1e5 + 5;

int n;

int x[N], y[N];

int dist(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

struct node {
	ll sum;
	int mx;
	
	node(ll sum = 0, int mx = 0) : sum(sum), mx(mx) {}
	
	node(int i) {
		if(i > 0) sum = dist(i, i - 1);
		if(i >= 2) mx = dist(i, i - 1) + dist(i - 1, i - 2) - dist(i, i - 2);
	}
	
	node operator + (const node &other) {
		return {sum + other.sum, max(mx, other.mx)};
	}
};

node t[N << 2];

void update(int v, int l, int r, int i) {
	if(l == r) {
		t[v] = node(i);
		return;
	}
	
	int m = (l + r) >> 1;
	
	if(i <= m) update(v << 1, l, m, i);
	else update(v << 1 | 1, m + 1, r, i);
	
	t[v] = t[v << 1] + t[v << 1 | 1];
}

void update(int i) {
	if(i >= n) return;
	update(1, 0, n - 1, i);
}

ll get_sum(int v, int l, int r, int ql, int qr) {
	if(l > qr || ql > r) return 0;
	
	if(l >= ql && r <= qr) return t[v].sum;
	
	int m = (l + r) >> 1;
	
	return get_sum(v << 1, l, m, ql, qr) + get_sum(v << 1 | 1, m + 1, r, ql, qr);
}

ll get_sum(int l, int r) {
	return get_sum(1, 0, n - 1, l, r);
}

int get_max(int v, int l, int r, int ql, int qr) {
	if(l > qr || ql > r) return 0;
	
	if(l >= ql && r <= qr) return t[v].mx;
	
	int m = (l + r) >> 1;
	
	return max(get_max(v << 1, l, m, ql, qr), get_max(v << 1 | 1, m + 1, r, ql, qr));
}

int get_max(int l, int r) {
	return get_max(1, 0, n - 1, l, r);
}

void solve() {
	int q; cin >> n >> q;
	
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		update(i);
	}
	
	while(q--) {
		char type; cin >> type;
		
		if(type == 'U') {
			int i, xu, yu; cin >> i >> xu >> yu;
			
			i--;
			
			x[i] = xu, y[i] = yu;
			
			update(i);
			update(i + 1);
			update(i + 2);
		} else {
			int l, r; cin >> l >> r;
			
			l--, r--;
			
			ll sum = get_sum(l + 1, r);
			int mx = get_max(l + 2, r);
			
			cout << sum - mx << nl;
			// cout << sum << ' ' << mx << nl;
		}
	}
}

signed main() {
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
