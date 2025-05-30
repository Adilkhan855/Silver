struct LCA {
	vector<int> euler, dep, lg, first;
	vector<vector<int>> sp;
	
	void dfs(int v, int p, int d, const vector<vector<int>> &adj) {
		first[v] = euler.size();
		euler.pb(v);
		dep.pb(d);
		for(auto to : adj[v]) {
			if(to == p) continue;
			dfs(to, v, d + 1, adj);
			euler.pb(v);
			dep.pb(d);
		}
	}
	
	LCA(vector<vector<int>> adj) {
		first.resize(adj.size());
		
		dfs(1, 1, 0, adj);
		
		int n = euler.size();
		
		lg.resize(n + 1);
		sp = vector(21, vector(n, 0ll));
		
		iota(all(sp[0]), 0);
		
		for(int i = 2; i <= n; i++) {
			lg[i] = lg[i / 2] + 1;
		}
		
		for(int i = 0; i < 20; i++) {
			for(int j = 0; j + (1 << i) < n; j++) {
				int l = sp[i][j], r = sp[i][j + (1 << i)];
				sp[i + 1][j] = (dep[l] < dep[r] ? l : r);
			}
		}
	}
	
	int query(int u, int v) {
		int ql = first[u], qr = first[v];
		if(ql > qr) swap(ql, qr);
		qr++;
		int i = lg[qr - ql];
		int l = sp[i][ql], r = sp[i][qr - (1 << i)];
		return (dep[l] < dep[r] ? euler[l] : euler[r]);
	}
};
