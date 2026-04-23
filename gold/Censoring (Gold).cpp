#include <bits/stdc++.h>

using namespace std;

#define nl '\n'

using ll = long long;

const int N = 1e5 + 5;

const int mod = 1e9 + 9, pr = 101;

int pw[N];

int mul(int a, int b) {
	return a * 1LL * b % mod;
}

void add_self(int &a, const int &b) {
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
}

void mul_self(int &a, const int &b) {
	a = mul(a, b);
}

int add(int a, int b) {
	add_self(a, b);
	return a;
}

set<int> st[N];

void solve() {
	string t; cin >> t;
	
	int n; cin >> n;
	
	vector<int> sz;
	
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		
		int hash = 0;
		
		for(int j = 0; j < (int)s.size(); j++) {
			add_self(hash, mul(s[j], pw[j]));
		}
		
		mul_self(hash, pw[N - 1]);
		
		st[s.size()].emplace(hash);
		
		sz.push_back(s.size());
	}
	
	sort(sz.begin(), sz.end());
	sz.erase(unique(sz.begin(), sz.end()), sz.end());
	
	// for(auto &x : sz) {
		// cout << x << ": ";
		// for(auto &hash : st[x]) {
			// cout << hash << ' ';
		// }
		// cout << nl;
	// }
	
	vector<int> R, Rc;
	
	R.push_back(0);
	
	auto get = [&](int l) {
		return mul(add(R.back(), -R[l]), pw[N - l - 2]);
	};
	
	for(auto &c : t) {
		R.push_back(add(R.back(), mul(c, pw[R.size()])));
		Rc.push_back(c);
		
		int mx = R.size(), mxc = Rc.size();
		
		for(auto &x : sz) {
			if(x >= (int)R.size()) break;
			
			// cout << get(R.size() - x - 1) << nl;
			
			if(st[x].count(get(R.size() - x - 1))) {
				mx = R.size() - x;
				mxc = Rc.size() - x;
			}
		}
		
		R.resize(mx);
		Rc.resize(mxc);
	}
	
	for(auto &c : Rc) {
		cout << char(c);
	}
	
	cout << nl;
}

signed main() {
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	pw[0] = 1;
	
	for(int i = 1; i < N; i++) {
		pw[i] = mul(pw[i - 1], pr);
	}
	
	solve();
}
