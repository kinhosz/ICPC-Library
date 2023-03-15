const int SZ = 1<<20;
template<class T> struct node_t {
	T delta = -1; node_t<T>* c[2];
	node_t() { c[0] = c[1] = nullptr; }
	void upd(int pos, T v, int L = 0, int R = SZ-1) { // upd v
		if (L == pos && R == pos) { delta = v; return; }
		int M = (L + R)>>1;
		if (pos <= M) {
			if (!c[0]) c[0] = new node_t();
			c[0]->upd(pos, v, L, M);
		} else {
			if (!c[1]) c[1] = new node_t();
			c[1]->upd(pos, v, M+1, R);
		}
		delta = -1; 
		for (int i = 0; i < 2; ++i) if (c[i]) delta = max(delta, c[i]->delta);
	}
	T query(int lx, int rx, int L = 0, int R = SZ-1) { // query sum of segment
		if (rx < L || R < lx) return -1;
		if (lx <= L && R <= rx) return delta;
		int M = (L + R)>>1; T res = -1;
		if (c[0]) res = max(res, c[0]->query(lx, rx, L, M));
		if (c[1]) res = max(res, c[1]->query(lx, rx, M+1, R));
		return res;
	}
	void upd(int pos, node_t *a, node_t *b, int L = 0, int R = SZ-1) {
		if (L != R) {
			int M = (L + R)>>1;
			if (pos <= M) {
				if (!c[0]) c[0] = new node_t();
				c[0]->upd(pos, a ? a->c[0] : nullptr, b ? b->c[0] : nullptr, L, M);
			} else {
				if (!c[1]) c[1] = new node_t();
				c[1]->upd(pos,a ? a->c[1] : nullptr, b ? b->c[1] : nullptr, M+1, R);
			}
		} 
		delta = max((a ? a->delta : -1), (b ? b->delta : -1));
	}
};
 
template<class T> struct Node {
    node_t<T> seg; Node* c[2];
    Node() { c[0] = c[1] = nullptr; }
    void upd(int x, int y, T v, int L = 0, int R = SZ-1) { 
        if (L == x && R == x) { seg.upd(y,v); return; }
        int M = (L+R)>>1;
        if (x <= M) {
            if (!c[0]) c[0] = new Node();
            c[0]->upd(x,y,v,L,M);
        } else {
            if (!c[1]) c[1] = new Node();
            c[1]->upd(x,y,v,M+1,R);
        }
        //seg.upd(y,v); // only for addition
        seg.upd(y,c[0]?&c[0]->seg:nullptr,c[1]?&c[1]->seg:nullptr);
    }
    T query(int x1, int x2, int y1, int y2, int L = 0, int R = SZ-1) { // query sum of rectangle
        if (x1 <= L && R <= x2) return seg.query(y1,y2);
        if (x2 < L || R < x1) return -1;
        int M = (L+R)>>1; T res = -1;
        if (c[0]) res = max(res, c[0]->query(x1, x2, y1, y2, L, M));
        if (c[1]) res = max(res, c[1]->query(x1, x2, y1, y2, M+1, R));
        return res;
    }
};
// by: LeticiaFCS
