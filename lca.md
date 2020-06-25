#### [Centroid decomposition & lca](https://codeforces.com/contest/342/submission/81042084)
### lca using Binary lifting
```  
//just call preprocess(root)
int maxn=1e5+1;
int n, l;
vector<int> adj[maxn];
int timer;
vector<int> tin, tout,level;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
           { 
             level[u]=level[v]+1;
             dfs(u, v);
           }
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int distan(int u,int v)
{
  return level[u]+level[v]-level[lca(u,v)];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    level.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    level[root]=0;
    dfs(root, root);
}
```
### [lca using RMQ](https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-tree-set-3-using-rmq/)
```

```
