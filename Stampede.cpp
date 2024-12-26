/*
 *    author: a.k
 *    created: idk
*/
#include <bits/stdc++.h> 
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define nl '\n'

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> events;
	for(int i = 0; i < n; i++) {
		int x, y, r; cin >> x >> y >> r;
		x = -x * r;
		
		events.pb(x - r, y);
		events.pb(x, -y);
	}
	
	sort(all(events));
	set<int> cur, seen;
	for(int i = 0; i < (int)events.size(); ) {
		int j;
		for(j = i; j < (int)events.size() && events[i].first == events[j].first; j++) {
			int y = events[j].second;
			if(y > 0) {
				cur.emplace(y);
			} else {
				cur.erase(-y);
			}
		}
		if(!cur.empty()) {
			seen.emplace(*cur.begin());
		}
		i = j;
	}
	cout << seen.size() << nl;
}

signed main() {
	freopen("stampede.in", "r", stdin);
	freopen("stampede.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
