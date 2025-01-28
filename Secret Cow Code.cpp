/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define int long long
#define nl '\n'

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
	setIO("cowcode");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s; cin >> s;
	int k; cin >> k;
	
	int n = s.size();
	
	auto rec = [&](auto &&rec, int idx) {
		if(idx < n) return s[idx];
		
		int len = n;
		while(len * 2 <= idx) len *= 2;
		
		if(len == idx) return rec(rec, len - 1);
		return rec(rec, idx - len - 1);
	};
	cout << rec(rec, k - 1) << nl;
}
