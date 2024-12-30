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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int INF = 1e9;
signed main() {
	setIO("balancing");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<pair<int, int>> p(n);
	for(auto &[x, y] : p) {
		cin >> x >> y;
	}
	
	sort(all(p));
	
	int ans = n;
	for(int i = 0; i < n; i++) {
		vector<pair<int, int>> bel, abv;
		for(int j = 0; j < n; j++) {
			if(p[j].second <= p[i].second) {
				bel.pb(p[j]);
			} else {
				abv.pb(p[j]);
			}
		}
		int bdx = 0, abx = 0;
		while(bdx < (int)bel.size() || abx < (int)abv.size()) {
			int X = INF;
			
			if(bdx < (int)bel.size()) {
				X = min(X, bel[bdx].first);
			}
			
			if(abx < (int)abv.size()) {
				X = min(X, abv[abx].first);
			}
			
			while(bdx < (int)bel.size() && bel[bdx].first == X) bdx++;
			
			while(abx < (int)abv.size() && abv[abx].first == X) abx++;
			
			int cur = max<int>({bdx, (int)bel.size() - bdx, abx, (int)abv.size() - abx});
			ans = min(ans, cur);
		}
	}
	cout << ans << nl;
}
