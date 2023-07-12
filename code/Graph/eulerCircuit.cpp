typedef pair<int, int> ii;

template <const bool BIDIRECTIONAL>
class EulerPath{
	vector<ii> edges;
	vector<vector<int>> adj;
	vector<bool> used;
	vector<int> dg;

	int getRoot(){
		for(int i=0;i<adj.size();i++){
			if(BIDIRECTIONAL && adj[i].size()%2) return i;
			else if(!BIDIRECTIONAL && dg[i] == 1) return i;
		}

		return 0;
	}

	bool wasUsed(int e){
		if(BIDIRECTIONAL) return (used[e] || used[e^1]);
		return used[e];
	}

	void dfs(int u, vector<ii> &path){
		while(!adj[u].empty()){
			int e = adj[u].back();
			adj[u].pop_back();

			if(this->wasUsed(e)) continue;

			int id = edges[e].first;
			int v = edges[e].second;
			used[e] = true;

			dfs(v, path);
			path.push_back({id, v});
		}
	}

public:
	void init(int n){
		adj.resize(n);
		dg.resize(n, 0);
	}

	void add(int u, int v, int id){
		for(int i=0;i<=BIDIRECTIONAL;i++){
			adj[u].push_back(edges.size());
			edges.push_back({id, v});
			used.push_back(false);
			dg[u]++;
			dg[v]--;

			swap(u, v);
		}
	}

	void get(vector<ii> &path){
		int root = this->getRoot();

		this->dfs(root, path);
		reverse(path.begin(), path.end());
	}
};
