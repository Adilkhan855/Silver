#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

void solve() {
	string s; cin >> s;
	
	int n = s.size();
	
	vector<ar<int, 3>> pref(n + 1);
	
	for(int i = 0; i < n; i++) {
		pref[i + 1] = pref[i];
		if(s[i] == 'C') pref[i + 1][0]++;
		if(s[i] == 'O') pref[i + 1][1]++;
		if(s[i] == 'W') pref[i + 1][2]++;
	}
	
	int q; cin >> q;
	
	while(q--) {
		int l, r; cin >> l >> r;
		ar<int, 3> cnt{};
		for(int i = 0; i < 3; i++) {
			cnt[i] = pref[r][i] - pref[l - 1][i];
		}
		cout << ((cnt[0] + cnt[1]) % 2 && (cnt[1] + cnt[2]) % 2 == 0 ? 'Y' : 'N');
	}
	
	cout << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
