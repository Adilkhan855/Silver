#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	string s; cin >> s;
	
	int n = s.size();
	
	vector<vector<int>> suf(n + 1, vector<int>(26, n));
	vector<i64> dp(n + 1);
	
	string t = "bessie";
	
	for(int i = n - 1; i >= 0; i--) {
		suf[i] = suf[i + 1];
		suf[i][s[i] - 'a'] = i;
		
		int cur = i, flag = true;
		
		for(int j = 0; j < 6; j++) {
			if(suf[cur][t[j] - 'a'] == n) {
				flag = false;
				break;
			}
			cur = suf[cur][t[j] - 'a'] + 1;
		}
		
		if(flag) {
			dp[i] = (n - cur + 1) + dp[cur];
		}
	}
	
	cout << accumulate(dp.begin(), dp.end(), 0ll) << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
