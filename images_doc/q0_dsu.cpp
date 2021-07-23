//Problem-Redundant Connection leetcode
class Solution {
public:
    int parent[1001];
    int size[1001];
    
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        memset(parent,0,sizeof(parent));
        memset(size,0,sizeof(size));
        
        vector<int> v;
        for(auto x:edges)
        {
            if(size[x[0]]==0)
                make_set(x[0]);
            if(size[x[1]]==0)
                make_set(x[1]);
            
            int v1=find_set(x[0]);
            int v2=find_set(x[1]);
            
            if(v1==v2)
            {v=x;
                break;
            }
            else
                union_set(v1,v2);
        }
        
        return v;
        
    }
};
