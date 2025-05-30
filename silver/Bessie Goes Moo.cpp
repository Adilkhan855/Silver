/*
 *    author: a.k
 *    created: idk
*/
#include <bits/stdc++.h> 
using namespace std;

using i64 = long long;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
	setIO("bgm");
	int n; cin >> n;
	map<char, map<int, i64>> mp;
	for(int i = 0; i < n; i++) {
		char C; int x;
		cin >> C >> x;
		mp[C][(x % 7 + 7) % 7]++;
	}
	i64 ans = 0;
	for(int B = 0; B < 7; B++) 
	for(int E = 0; E < 7; E++) 
	for(int S = 0; S < 7; S++) 
	for(int I = 0; I < 7; I++) 
	for(int G = 0; G < 7; G++) 
	for(int O = 0; O < 7; O++) 
	for(int M = 0; M < 7; M++) {
		if((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O) % 7 == 0) {
			ans += mp['B'][B] * mp['E'][E] * mp['S'][S] * mp['I'][I] * mp['G'][G] * mp['O'][O] * mp['M'][M];
		}
	} 
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
