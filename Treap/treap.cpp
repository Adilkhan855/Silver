mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) uniform_int_distribution<int>(l, r)(rng)
 
struct node {
	int x, y, s;
	node *L, *R;
	
	node(int x): x(x), s(1), L(NULL), R(NULL) {
		y = rnd(0, 1e9);
	}
	
	void rec() {
		s = 1;
		if(L) s += L -> s;
		if(R) s += R -> s;
	}
};
 
struct RBST {
	node* _merge(node* a, node* b) {
		if(a == NULL) return b;
		if(b == NULL) return a;
		
		if(a -> y < b -> y) swap(a, b);
		
		if(a -> x < b -> x) {
			a -> R = _merge(a -> R, b);
		} else {
			a -> L = _merge(b, a -> L);
		}
		
		a -> rec();
		
		return a;
	}
	
	node* merge(node* a, node* b) { // assume (a -> x) < (b -> x)
		if(a == NULL) return b;
		if(b == NULL) return a;
		
		if(a -> y > b -> y) {
			a -> R = merge(a -> R, b);
			a -> rec();
			return a;
		} else {
			b -> L = merge(a, b -> L);
			b -> rec();
			return b;
		}
	}
	
	ar<node*, 2> _split(node *a, int k) {
		if(a == NULL) return {NULL, NULL};
		
		if(a -> x < k) {
			auto [ls, rs] = _split(a -> R, k);
			a -> R = ls;
			a -> rec();
			return {a, rs};
		} else {
			auto [ls, rs] = _split(a -> L, k);
			a -> L = rs;
			a -> rec();
			return {ls, a};
		}
	}
	
	ar<node*, 2> split(node* a, int k) { // split on index
		if(a == NULL) return {NULL, NULL};
		
		int i = (a -> L != NULL ? a -> L -> s : 0);
		
		if(i < k) {
			auto [ls, rs] = split(a -> R, k - i - 1);
			a -> R = ls;
			a -> rec();
			return {a, rs};
		} else {
			auto [ls, rs] = split(a -> L, k);
			a -> L = rs;
			a -> rec();
			return {ls, a};
		}
	}
	
	void insert(node* &root, int x) {
		node* n = new node(x);
		auto [L, R] = _split(root, x);
		root = _merge(L, n);
		root = _merge(root, R);
	}
	
	void print(node *a) {
		if(a == NULL) return;
		print(a -> L);
		cout << a -> x << ' ';
		print(a -> R);
	}
} rbst;
