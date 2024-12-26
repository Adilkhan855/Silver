/*
 *    author: a.k
 *    created: idk
*/
#include <bits/stdc++.h> 
using namespace std;

template<class F, class S> 
void chmin(F& a, const S& b) {
	if(a > b) a = b;
} 
const int mxV = 1005;
void solve() {
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);
	int a, b, n; cin >> a >> b >> n;
	
	vector dis(mxV, vector(mxV, pair{(long long)1e18, (int)1e9}));
	for(int i = 0; i < n; i++) {
		long long cost;
		int len;
		cin >> cost >> len;
		
		vector<int> route(len);
		for(int j = 0; j < len; j++) {
			cin >> route[j];
			for(int k = 0; k < j; k++) {
				chmin(dis[route[k]][route[j]], pair{cost, j - k});
			}
		}
	}
	for(int i = 0; i < mxV; i++) dis[i][i] = {0, 0};
	
	vector dis_a2v(mxV, pair{(long long)1e18, (int)1e9});
	vector used(mxV, false);
	
	dis_a2v[a] = {0, 0};
	for(int i = 0; i < mxV; i++) {
		int v = -1;
		for(int j = 0; j < mxV; j++) {
			if(!used[j] && (v == -1 || dis_a2v[j] < dis_a2v[v])) {
				v = j;
			}
		}
		if(v == (long long)1e18) break;
		used[v] = true;
		for(int j = 0; j < mxV; j++) {
			pair rlx = dis_a2v[v];
			rlx.first += dis[v][j].first;
			rlx.second += dis[v][j].second;
			chmin(dis_a2v[j], rlx);
		}
	}
	if(dis_a2v[b].first < (long long)1e18) {
		cout << dis_a2v[b].first << ' ' << dis_a2v[b].second << '\n';
	} else {
		cout << "-1 -1\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1; 
	// cin >> tt;
	while(tt--) solve();
}
