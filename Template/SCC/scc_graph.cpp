void dfs(int v, vector<int> &used, vector<int> &output, const vector<vector<int>> &adj) {
	if(used[v]) return;
	used[v] = true;
	for(auto to : adj[v]) {
		dfs(to, used, output, adj);
	}
	output.pb(v);
}
 
auto scc_graph(vector<vector<int>> &adj) {
	int n = adj.size();
	
	vector<int> used(n), comp(n), order;
	vector<vector<int>> radj(n), adjc(n);
	
	for(int u = 0; u < n; u++) {
		dfs(u, used, order, adj);
		for(auto v : adj[u]) {
			radj[v].pb(u);
		}
	}
	
	fill(all(used), false);
	reverse(all(order));
	
	for(auto u : order) {
		vector<int> in_comp;
		dfs(u, used, in_comp, radj);
		for(auto v : in_comp) {
			comp[v] = u;
		}
	}
	
	for(int u = 0; u < n; u++) {
		for(auto v : adj[u]) {
			adjc[comp[u]].pb(comp[v]);
		}
	}
	
	return adjc;
}
