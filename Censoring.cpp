/*
 *    author: a.k
 *    created: idk
*/
#include <bits/stdc++.h> 
using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int nax = 1e6 + 5;
const int mod = 1e9 + 7, hpr = 31;
void solve() {
	setIO("censor");
	
	string s, t;
	cin >> s >> t;
	
	vector<int> pw(1, 1);
	for(int i = 0; i < nax; i++) {
		pw.emplace_back(1ll * pw.back() * hpr % mod);
	}
	int thsh = 0;
	for(int i = 0; i < (int)t.size(); i++) {
		thsh = (thsh + 1ll * t[i] * pw[i] % mod) % mod;
	}
	
	string r;
	int cnt = 0;
	vector<int> rhsh(1, 0);
	for(int i = 0; i < (int)s.size(); i++) {
		r += s[i];
		rhsh.emplace_back((1ll * s[i] * pw[i - cnt] % mod + rhsh.back()) % mod);
		if(r.size() >= t.size()) {
			int l = r.size() - t.size();
			int cur = rhsh.back() - rhsh[l];
			cur = (cur + mod) % mod;
			if((1ll * cur * pw[nax - l]) % mod == (1ll * thsh * pw[nax]) % mod) {
				cnt += t.size();
				r.erase(r.begin() + l, r.end());
				rhsh.erase(rhsh.begin() + l + 1, rhsh.end());
			}
		}
	}
	cout << r << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
