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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 255;

int a[N][N], id[N][N], comps;

struct Graph {
	map<int, set<int>> out_edges;
	map<int, int> nodesize, compid;
	map<int, int> compsize;
};

map<int, Graph> G1;
map<ar<int, 2>, Graph> G2;

int dfs(Graph &G, int node, int compid) {
	if(G.compid.count(node)) return 0;
	G.compid[node] = compid;
	int sz = G.nodesize[node];
	for(auto to : G.out_edges[node]) {
		sz += dfs(G, to, compid);
	}
	return G.compsize[compid] = sz;
}

int largest(Graph &G) {
	int mx = 0;
	for(auto &p : G.out_edges) chmax(mx, dfs(G, p.first, ++comps));
	return mx;
}

void add_edge(Graph &G, int node1, int node2) {
	G.out_edges[node1].emplace(node2);
	G.out_edges[node2].emplace(node1);
	G.nodesize[node1] = G.nodesize[node2] = 1;
}

void add_edge_G2(int i1, int j1, int i2, int j2) {
	int a1 = a[i1][j1], a2 = a[i2][j2];
	int c1 = id[i1][j1], c2 = id[i2][j2];
	if(a1 > a2) swap(a1, a2), swap(c1, c2);
	int comp1 = G1[a1].compid[c1], comp2 = G1[a2].compid[c2];
	ar<int, 2> p = {a1, a2};
	add_edge(G2[p], comp1, comp2);
	G2[p].nodesize[comp1] = G1[a1].compsize[comp1];
	G2[p].nodesize[comp2] = G1[a2].compsize[comp2];
}

void solve() {
	setIO("multimoo");
	
	int n; cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j]; id[i][j] = i * n + j;
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			add_edge(G1[a[i][j]], id[i][j], id[i][j]);
			if(i + 1 < n && a[i + 1][j] == a[i][j]) add_edge(G1[a[i][j]], id[i][j], id[i + 1][j]);
			if(j + 1 < n && a[i][j + 1] == a[i][j]) add_edge(G1[a[i][j]], id[i][j], id[i][j + 1]);
		}
	}
	
	int ans1 = 0;
	
	for(auto &p : G1) chmax(ans1, largest(p.second));
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i + 1 < n && a[i + 1][j] != a[i][j]) add_edge_G2(i, j, i + 1, j);
			if(j + 1 < n && a[i][j + 1] != a[i][j]) add_edge_G2(i, j, i, j + 1);
		}
	}
	
	int ans2 = 0;
	
	for(auto &p : G2) chmax(ans2, largest(p.second));
	
	cout << ans1 << nl << ans2 << nl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
}
