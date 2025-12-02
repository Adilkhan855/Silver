#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int inf = 1e9;

void chmin(int &a, const int &b) {
	if(a > b) a = b;
}

void solve() {
	int C, n; cin >> C >> n;
	
	vector<string> cow(n);
	
	vector<int> dp(1 << C, inf), val;
	
	for(auto &s : cow) {
		cin >> s;
		
		int x = 0;
		
		for(int i = 0; i < C; i++) {
			if(s[i] == 'G') x |= (1 << i);
		}
		
		dp[x] = 0;
		
		val.push_back(x);
	}
	
	for(int i = 0; i < C; i++) {
		for(int mask = 0; mask < (1 << C); mask++) {
			chmin(dp[mask ^ (1 << i)], dp[mask] + 1);
		}
	}
	
	for(auto &x : val) {
		cout << C - dp[ ((1 << C) - 1) ^ x ] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
