#define pb push_back

int n,m;
vector<vector<int> > g, grev;
vector<bool> visited;
vector<int> order;
vector<int> component;
vector<vector<int> > difComponents;

void dfs(int node){
    visited[node] = true;
    for(auto x: g[node]){
        if(visited[x])continue;
        dfs(x);
    }
    order.pb(node);
}

void dfs_rev(int node){
    visited[node] = true;
    component.pb(node);
    for(auto x: grev[node]){
        if(visited[x])continue;
        dfs_rev(x);
    }
}

void get_scc(){
    visited.assign(n, false);
    for(int i = 0; i < n; ++i){
        if(visited[i])continue;
        dfs(i);
    }

    reverse(order.begin(), order.end());
    visited.assign(n, false);
    for(auto x: order){
        if(visited[x])continue;
        dfs_rev(x);        
        difComponents.pb(component);
        component.clear();
    }
}