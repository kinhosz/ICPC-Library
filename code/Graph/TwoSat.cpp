struct TwoSat{
    int n, tot;
    vector<vector<int> > g;
    vector<int> vis, comp, id, ans;
    stack<int> s;

    TwoSat() {}
    TwoSat(int n){
        this->n = n;
        this->tot = n;
        g.resize(2*n);
    }

    int dfs(int i, int& t) {
		int lo = id[i] = t++;
		s.push(i), vis[i] = 2;
		for (int j : g[i]) {
			if (!vis[j]) lo = min(lo, dfs(j, t));
			else if (vis[j] == 2) lo = min(lo, id[j]);
		}
		if (lo == id[i]) while (1) {
			int u = s.top(); s.pop();
			vis[u] = 1, comp[u] = i;
			if ((u>>1) < n and ans[u>>1] == -1) ans[u>>1] = ~u&1;
			if (u == i) break;
		}
		return lo;
	}

    // u -> v ==== (~u ou v) &&(~v ou u)
    // Guarda as variaveis negativas em nós ímpares e as positivas em nós pares
    void add_implication(int x, int y){
        x = x >= 0 ? 2*x : -2*x-1; 
		y = y >= 0 ? 2*y : -2*y-1;
		g[x].push_back(y);
		g[y^1].push_back(x^1);
    }

    //Essa operacao é para adicionar o (x ou y)
    void add_cl(int x, int y){
        add_implication(~x, y);
    }

    // x xor y = (x ou y) and (~x ou ~y)
    void add_xor(int x, int y){
        add_cl(x, y);
        add_cl(~x, ~y);
    }
    
    /* x xnor y = ~(x xor y) ==>
       ~((x ou y) and (~x ou ~y)) ==>
       (~x ou y) and (x and ~y)
    */
    void add_xnor(int x, int y){
        add_cl(~x, y);
        add_cl(x, ~y);
    }

    /* x nand y = ~(x and y) ==>
       (~x or ~y)
    */
    void add_nand(int x, int y){
        add_cl(~x, ~y);
    }

    void add_true(int x){
        add_implication(~x, x);
    }

    void at_most_one(vector<int> v) { // Dado um vetor de variaveis, apenas 1 dessas pode ser verdadeira.
		g.resize(2*(tot+v.size()));
		for (int i = 0; i < v.size(); i++) {
			add_implication(tot+i, ~v[i]);
			if (i) {
				add_implication(tot+i, tot+i-1);
				add_implication(v[i], tot+i-1);
			}
		}
		tot += v.size();
	}

    pair<bool, vector<int> > solve(){
        ans = vector<int>(n,-1);
        int t = 0;
        vis = comp = id = vector<int> (2*tot, 0);
        for (int i = 0; i < 2*tot; i++) if (!vis[i]) dfs(i, t);
		for (int i = 0; i < tot; i++)
			if (comp[2*i] == comp[2*i+1]) return make_pair(false, vector<int>());
		return make_pair(true, ans);
    }
};