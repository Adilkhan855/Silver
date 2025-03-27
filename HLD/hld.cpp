struct SGT {
	int n; vector<int> t;
	
	void resize(int size) {
		n = size;
		t.resize(n << 1);
	}
	
	void UPD(int i, int x) {
		for(t[i += n] = x; i > 0; i >>= 1) t[i >> 1] = max(t[i], t[i ^ 1]);
	}
	
	int GET(int l, int r) { // [l, r)
		int res = 0;
		for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res = max(res, t[l++]);
			if(r & 1) res = max(res, t[--r]);
		}
		return res;
	}
};

struct HLD {
	vector<int> dep, par, sz;
	vector<int> head, heavy, tin;
	vector<vector<int>> adj;
	
	SGT T;
	
	int timer;
	
	void Dfs(int v, int p) {
		par[v] = p;
		dep[v] = dep[p] + 1;
		sz[v] = 1;
		
		for(auto to : adj[v]) {
			if(to == p) continue;
			Dfs(to, v);
			sz[v] += sz[to];
			if(sz[heavy[v]] < sz[to]) {
				heavy[v] = to;
			}
		}
	}
	
	void Decompose(int v, int hd) {
		tin[v] = ++timer;
		head[v] = hd;
		
		if(heavy[v]) {
			Decompose(heavy[v], hd);
		}
		
		for(auto to : adj[v]) {
			if(to == par[v] || to == heavy[v]) continue;
			Decompose(to, to);
		}
	}
	
	HLD(vector<vector<int>> adj) : adj(adj) {
		int n = adj.size();
		timer = 0;
		T.resize(n);
		tin.resize(n);
		head.resize(n);
		heavy.resize(n);
		dep.resize(n);
		par.resize(n);
		sz.resize(n);
		Dfs(1, 1), Decompose(1, 1);
	}
	
	void update(int u, int x) {
		T.UPD(tin[u], x);
	}
	
	int query(int u, int v) {
		int res = 0;
		while(head[u] != head[v]) {
			if(dep[head[u]] < dep[head[v]]) swap(u, v);
			res = max(res, T.GET(tin[head[u]], tin[u]));
			u = par[head[u]];
		}
		if(tin[u] > tin[v]) swap(u, v);
		res = max(res, T.GET(tin[u], tin[v]));
		return res;
	}
};
