/**
 *    author: a.k
 *    created: idk
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define nl '\n'

signed main() {
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	
	vector<pair<int, int>> c(n);
	
	for(int i = 0; i < n; i++) {
		cin >> c[i].second >> c[i].first;
	}
	
	sort(all(c));
	
	int l = 0, r = n - 1;
	
	int ans = 0;
	
	while(l <= r) {
		int mn = min(c[l].second, c[r].second);
		
		ans = max(ans, c[l].first + c[r].first);
		
		if(l == r) c[l].second -= mn;
		else {
			c[l].second -= mn;
			c[r].second -= mn;
		}
		
		if(c[l].second == 0) l++;
		if(c[r].second == 0) r--;
	}
	
	cout << ans << nl;
}
