#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define int long long

using ll = long long;

const int N = 1e6;

void solve() {
	int n, k; cin >> n >> k;
	
	vector<int> a(n);
	
	for(auto &x : a) cin >> x;
	
	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
	
	vector<int> ind(n, -1);
	
	for(int i = 0; i < k; i++) {
		pq.push({a[i], i});
		ind[i] = i;
	}
	
	vector<vector<int>> radj(n + 1);
	
	int i = k;
	
	// /**
	
	while(!pq.empty()) {
		int mn = pq.top()[0];
		
		// cout << nl;
		
		// cout << mn << ": " << nl;
		
		int inds = 0;
		
		while(!pq.empty() && pq.top()[0] == mn) {
			auto [val, idx] = pq.top();
			pq.pop();
			
			// cout << idx + 1 << ' ' << ind[idx] + 1 << nl;
			
			inds++;
			
			radj[i].push_back(ind[idx]);
		}
		
		// cout << nl;
		
		int j = i;
		
		while(i < n && inds--) {
			// cout << "add: " << mn + a[i] << ' ' << i << nl;
			ind[i] = j;
			pq.push({mn + a[i], i});
			i++;
		}
		
		if(inds > 0) {
			vector<int> used(n + 1);
			
			int cnt = 0;
			
			auto dfs = [&](auto &&self, int v) -> void {
				used[v] = true;
				
				assert(++cnt <= N);
				
				for(auto to : radj[v]) {
					if(!used[to]) self(self, to);
				}
			};
			
			dfs(dfs, j);
			
			cout << mn << nl;
			
			for(int i = 0; i < k; i++) cout << used[i];
			
			cout << nl;
			
			return;
		}
	}
	
	// **/
}

/**

**/

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
