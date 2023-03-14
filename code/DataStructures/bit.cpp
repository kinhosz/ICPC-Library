int bit[MAXN];

int query(int x){
	int s = 0;

	while(x > 0){
		s += bit[x];
		x -= (x & -x);
	}

	return s;
}

void update(int x,int v){
	while(x < MAXN){
		bit[x] += v;
		x += (x & -x);
	}
}