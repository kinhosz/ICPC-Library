typedef pair<int, int> ii;

template <const bool BIDIRECTIONAL>
class EulerPath{
	vector<ii> edges;
	vector<int> ids;
	vector<vector<int>> adj;
	vector<bool> used;
	vector<int> dg;
	int root=0;

	bool check(int u){
		if(BIDIRECTIONAL && adj[u].size()%2) return true;
		if(!BIDIRECTIONAL && dg[u] == 1) return true;

		return false;
	}

	void setRoot(){
		if(check(this->root)) return;

		for(int i=0;i<adj.size();i++){
			if(check(i)) this->root = i;
		}
	}

	bool wasUsed(int e){
		if(BIDIRECTIONAL) return (used[e] || used[e^1]);
		return used[e];
	}

	void dfs(int u, vector<int> &path){
		while(!adj[u].empty()){
			int e = adj[u].back();
			adj[u].pop_back();

			if(this->wasUsed(e)) continue;

			int v = edges[e].second;
			used[e] = true;

			dfs(v, path);
			path.push_back(e);
		}
	}

	void build(vector<int> &path, vector<ii> &ans){
		int from = this->root;

		for(int i=(int)path.size()-1;i>=0;i--){
			int e = path[i];

			if(edges[e].first != from){
				ans.clear();
				return;
			}

			from = edges[e].second;
			ans.push_back({ids[e], edges[e].second});
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
			edges.push_back({u, v});
			ids.push_back(id);
			used.push_back(false);
			dg[u]++;
			dg[v]--;

			swap(u, v);
		}
	}

	void get(vector<ii> &ans, int start=0){
		this->root = start;
		this->setRoot();

		vector<int> path;
		this->dfs(this->root, path);
		build(path, ans);
	}

	int getRoot(){ return this->root; }
};

// returns a vector of <id, to>