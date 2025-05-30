const int inf = 1e18;

struct line {
	int m, c;
	line() : m(0), c(-1e18) {}
	line(int m, int c) : m(m), c(c) {}
	
	int operator * (int x) {
		return m * x + c;
	}
};

struct LiChao {
	int n;
	vector<line> t;
	vector<int> q;
	
	LiChao(vector<int> a) : n(a.size()), t(n << 2), q(a) {
		q.pb(-inf);
		sort(all(q));
	}
	
	void add(int v, int l, int r, line x) {
		int m = (l + r) >> 1;
		if(t[v] * q[m] < x * q[m]) swap(t[v], x);
		if(l == r) return;
		if(t[v] * q[r] > x * q[r]) {
			add(v << 1, l, m, x);
		} else {
			add(v << 1 | 1, m + 1, r, x);
		}
	}
	
	void add(line x) {
		add(1, 1, n, x);
	}
	
	int get(int v, int l, int r, int i) {
		if(l == r) return t[v] * q[i];
		int m = (l + r) >> 1;
		if(i <= m) return max(t[v] * q[i], get(v << 1, l, m, i));
		else return max(t[v] * q[i], get(v << 1 | 1, m + 1, r, i));
	}
	
	int get(int x) {
		return get(1, 1, n, lower_bound(all(q), x) - q.begin());
	}
};
