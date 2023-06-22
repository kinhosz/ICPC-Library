typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int lvl[MAXN];
vector<int> adj[MAXN];
vector<iii> edges;

void init(){
  for(int i=0;i<MAXN;i++) lvl[i] = -1;
}

// u, parent(u), level; pass p = -1 if u is root
int bridge(int u, int p, int l){
  int ret = -1;
  lvl[u] = l;

  for(auto v: adj[u]){
      if(v == p) continue;
      int cb = -1;

      if(lvl[v] != -1) cb = v;
      else cb = bridge(v, u, l+1);

      if(cb != -1){
          if(ret == -1 || lvl[cb] < lvl[ret]) ret = cb;
      }
  }

  if(ret != -1 && lvl[ret] >= l) ret = -1;

  bool isBridge = true;
  if(ret != -1) isBridge = false;

  if(p != -1) edges.push_back({{p, u}, isBridge});

  return ret;
}