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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mod = 1e9 + 7;

void add_self(int &a, const int &b) {
	a = (a + b) % mod;
	if(a < 0) a += mod;
}

struct FenwickTree {
	int n; vector<int> bit;
	
	FenwickTree() : n(0) {}
	FenwickTree(int n) : n(n), bit(n + 1) {}
	
	void update(int i, int x) {
		for(; i <= n; i += i & -i) add_self(bit[i], x);
	}
	
	int pref(int i) {
		int res = 0;
		for(; i >= 1; i -= i & -i) add_self(res, bit[i]);
		return res;
	}
	
	int suf(int i) {
		return pref(n) - pref(i);
	}
};

void solve() {
	setIO("triangles");
	int n; cin >> n;
	
	vector<ar<int, 2>> pt(n);
	
	map<int, vector<int>> mpx, mpy;
	
	for(auto &[x, y] : pt) {
		cin >> x >> y;
		mpx[x].pb(y);
		mpy[y].pb(x);
	}
	
	auto compress = [](vector<int> &a) {
		sort(all(a));
		a.erase(unique(all(a)), a.end());
	};
	
	auto get = [](vector<int> &a, int x) {
		return lower_bound(all(a), x) - a.begin() + 1;
	};
	
	map<int, FenwickTree> sumx, sumy, cntx, cnty;
	
	for(auto &[key, val] : mpx) {
		compress(val);
		sumx[key] = FenwickTree(val.size());
		cntx[key] = FenwickTree(val.size());
	}
	
	for(auto &[key, val] : mpy) {
		compress(val);
		sumy[key] = FenwickTree(val.size());
		cnty[key] = FenwickTree(val.size());
	}
	
	for(auto [x, y] : pt) {
		int indx = get(mpx[x], y);
		int indy = get(mpy[y], x);
		cntx[x].update(indx, 1);
		sumx[x].update(indx, y);
		cnty[y].update(indy, 1);
		sumy[y].update(indy, x);
	}
	
	int ans = 0;
	
	for(auto [x, y] : pt) {
		// int sx = 0, sy = 0;
		// for(auto y2 : mpx[x]) add_self(sx, abs(y - y2));
		// for(auto x2 : mpy[y]) add_self(sy, abs(x - x2));
		// for(auto y2 : mpx[x]) {
			// for(auto x2 : mpy[y]) {
				// cout << "here: " << nl;
				// cout << "1: " << x << ' ' << y << nl;
				// cout << "2: " << x << ' ' << y2 << nl;
				// cout << "3: " << x2 << ' ' << y << nl;
				// ans += abs(x - x2) * abs(y - y2);
			// }
		// }
		// fx[x].pb(y);
		// fy[y].pb(x);
		// add_self(ans, sx * sy % mod);
		
		int indx = get(mpx[x], y);
		int indy = get(mpy[y], x);
		
		int Sx = (cntx[x].pref(indx) * y - sumx[x].pref(indx)) + (sumx[x].suf(indx) - cntx[x].suf(indx) * y);
		int Sy = (cnty[y].pref(indy) * x - sumy[y].pref(indy)) + (sumy[y].suf(indy) - cnty[y].suf(indy) * x);
		
		Sx %= mod;
		Sy %= mod;
		
		// cout << Sx << ' ' << Sy << nl;
		
		add_self(ans, Sx * Sy % mod);
	}
	
	cout << ans << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
