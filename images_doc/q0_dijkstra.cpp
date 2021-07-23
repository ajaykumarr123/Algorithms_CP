/********************************************************************************/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
using vi = vector<int>;
using pii = pair<int,int>;
const double PI = 4*atan(1);

#define loop(i,n) for(int i=0;i<n;i++)
#define itr(it,v)  for(auto it=v.begin();it!=v.end();++it)  
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(x) cout << "[ " << #x  << " : " << x << " ]" << endl ;
#define MOD (int)(1e9+7)

int n,m;
vector<pair<int,int>> g[100100];

int dist[100100];
int vis[100100];
void djikstra(int sc)
{   
    for(int i=1;i<=n;i++){
        dist[i]=1e18;
        vis[i]=0;
    }

    dist[sc]=0;
    priority_queue<pii> pq;
    pq.push(MP(-0ll,sc));

    while(!pq.empty()){
        pii fs=pq.top(); pq.pop();

        if(vis[fs.S]) continue;
        vis[fs.S]=1;

        for(auto v:g[fs.S]){
            int neigh = v.F;
            int wt = v.S;

            if(dist[neigh]>dist[fs.S]+wt){
                dist[neigh]=dist[fs.S]+wt;
                pq.push(MP(-dist[neigh],neigh));
            }
        }
    }
}

void solve()
{
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].PB({y,w});
        g[y].PB({x,w});
    }

}

int32_t main()
{ IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    int t=1;
    //cin>>t;
    
    while(t--)
    {
      solve();
    }
    return 0; 
}