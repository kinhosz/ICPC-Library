const int MAXN = 1e5 + 11;
const int INF = 1e9 + 7;
vector<int> g[MAXN];
int color[MAXN];
int sz[MAXN];
int cnt[MAXN];
bool big[MAXN];
int mx_qtd = -INF;
int sm_mx = 0;
int ans[MAXN];


void getsz(int node=0, int parent=-1){
    sz[node] = 1;
    for(auto x: g[node]){
        if(x != parent){
            getsz(x,node);
            sz[node] += sz[x];
        }
    }
}

void add(int node, int parent, int val){
    cnt[color[node]] += val;
    for(auto x: g[node]){
        if( x != parent && !big[x]){
            add(x, node, val);
        }
    }
}

void dfs(int node=0, int parent=-1, int keep=0){
    int mx = -1;
    int bigChild = -1;
    for(auto x:g[node]){
        if(x != parent && sz[x] > mx){
            mx = sz[x];
            bigChild = x;
        }
    }

    for(auto x: g[node]){
        if(x != parent && x != bigChild){
            dfs(x, node, 0);
        }
    }

    if(bigChild != -1){
        dfs(bigChild, node, 1);
        big[bigChild] = 1;
    }
    add(node, parent,1);
    // Aqui eu coloco a query pro no "node"
    if(bigChild != -1){
        big[bigChild] = 0;
    }
    if(keep == 0){
        add(node, parent, -1);
    }
}