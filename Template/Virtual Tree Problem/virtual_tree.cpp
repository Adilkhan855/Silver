#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define ar array
#define nl '\n'

template <typename A, typename B>
bool chmin(A &a, const B &b) {
    if( a > b ) {
        return a = b, true;
    }
    return false;
}

template <typename A, typename B>
bool chmax(A &a, const B &b) {
    if( a < b ) {
        return a = b, true;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, T; cin >> n >> T;
    
    int N = n + 1;
    
    vector<vector<ar<int, 2>>> adj(N);
    
    for(int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    
    vector<int> d(N), tin(N), tout(N);
    vector<vector<int>> jmp(N, vector<int>(21));
    
    int timer = 0;
    
    auto dfs = [&](auto &&self, int v, int p) -> void {
		jmp[v][0] = p;
		
		for(int i = 1; i <= 20; i++) {
			jmp[v][i] = jmp[ jmp[v][i - 1] ][i - 1];
		}
		
        tin[v] = ++timer;
        
        for(auto [to, w] : adj[v]) {
            if(to == p) continue;
            d[to] = d[v] + w;
            self(self, to, v);
        }
        
        tout[v] = timer;
    };
    
    dfs(dfs, 1, 1);
    
    auto upper = [&](int u, int v) {
        return tin[v] >= tin[u] && tout[v] <= tout[u];
    };
    
    auto lca = [&](int u, int v) {
		if(upper(u, v)) return u;
		for(int i = 20; i >= 0; i--) {
			if(!upper(jmp[u][i], v)) u = jmp[u][i];
		}
		return jmp[u][0];
	};
    
    auto cmp = [&](const int &u, const int &v) {
		return tin[u] < tin[v];
	};
	
	vector<int> sz(N);
	vector<vector<int>> adjv(N);
	
    while(T--) {
		int k; cin >> k;
		
		vector<int> in(k);
		
		for(auto &u : in) cin >> u;
		
		vector<int> ver;
		
		for(auto u : in) {
			if(u) ver.pb(u);
		}
		
		sort(all(ver), cmp);
		
		k = ver.size();
		
		for(int i = 1; i < k; i++) {
			ver.pb(lca(ver[i], ver[i - 1]));
		}
		
		sort(all(ver), cmp);
		ver.erase(unique(all(ver)), ver.end());
		
		for(auto u : ver) {
			adjv[u].clear();
			sz[u] = 0;
		}
		
		for(auto u : in) {
			if(u) sz[u]++;
		}
		
		stack<int> stk;
		stk.push(ver[0]);
		
		for(int i = 1; i < (int)ver.size(); i++) {
			while(!upper(stk.top(), ver[i])) stk.pop();
			adjv[stk.top()].pb(ver[i]);
			stk.push(ver[i]);
		}
		
		int res = 0;
		
		auto dfsv = [&](auto &&self, int v, int p) -> void {
			for(auto to : adjv[v]) {
				self(self, to, v);
				sz[v] += sz[to];
				res += (d[to] - d[v]) * sz[to] * ((int)in.size() - sz[to]);
			}
		};
		
		dfsv(dfsv, ver[0], ver[0]);
		
		cout << res << nl;
	}
    
}
