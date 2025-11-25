#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int m, n, k; cin >> m >> n >> k;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x, x--;
	
	vector<set<int>> ems(m);
	
	for(int i = 0; i < n; i++) {
		ems[a[i]].insert(i);
	}
	
	vector<set<int>> ncan(m);
	set<int> can, cur, prv, nxt;
	
	for(int i = 0; i < k; i++) {
		if(a[i] < k) can.insert(i);
		else ncan[a[i]].insert(i);
		cur.insert(i);
	}
	
	for(int i = k; i < n; i++) {
		nxt.insert(i);
	}
	
	auto add = [&]() {
		int ex = -1;
		
		if(!nxt.empty()) {
			ex = *nxt.begin();
			nxt.erase(nxt.begin());
		} else if(!prv.empty()) {
			ex = *(--prv.end());
			prv.erase( (--prv.end()) );
		}
		
		return ex;
	};
	
	for(int i = 0; i + k < m; i++) {
		
		while(!ems[i].empty()) {
		
			while(!can.empty()) {
				int e = *can.begin();
				
				can.erase(e);
				cur.erase(e);
				ems[a[e]].erase(e);
				
				int ex = add();
				
				if(ex != -1) {
					if(a[ex] >= i && a[ex] < i + k) can.insert(ex);
					else ncan[a[ex]].insert(ex);
					cur.insert(ex);
				}
			}
			
			if(ems[i].empty()) break;
			
			if(!nxt.empty()) {
				int e = *cur.begin();
				
				prv.insert(e);
				ncan[a[e]].erase(e);
				cur.erase(e);
				
				int ex = add();
				if(a[ex] >= i && a[ex] < i + k) can.insert(ex);
				else ncan[a[ex]].insert(ex);
				cur.insert(ex);
			} else {
				break;
			}
		}
		
		if(!ems[i].empty()) {
			// cout << i << '\n';
			cout << "NO\n";
			return;
		}
		
		for(auto &e : ncan[i + k]) can.insert(e);
		ncan[i + k].clear();
	}
	
	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while(tt--) solve();
}
