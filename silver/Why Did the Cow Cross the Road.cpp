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
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c, n; cin >> c >> n;
	
	multiset<int> st;
	
	for(int i = 0; i < c; i++) {
		int x; cin >> x;
		st.emplace(x);
	}
	
	vector<pair<int, int>> cow(n);
	
	for(int i = 0; i < n; i++) {
		cin >> cow[i].second >> cow[i].first;
	}
	
	sort(all(cow));
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		auto it = st.lower_bound(cow[i].second);
		
		if(it != st.end() && *it <= cow[i].first) {
			ans++;
			st.erase(it);
		}
	}
	
	cout << ans << nl;
}
