/********************************************************************************/
//minimum of range and count of it
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

const int MAXN = 1e5+1;
int arr[MAXN];

struct node{
  int mini;
  int count;

  node(int v1=1e9,int v2=1)
  {
    mini=v1;
    count=v2;
  }
};

node t[4*MAXN];

node merge(node a,node b)
{
  if(a.mini==b.mini)
    return node(a.mini,a.count+b.count);

  if(a.mini<b.mini)
    return a;
  else
    return b;
}

void build(int index,int l,int r)
{
  if(l==r)
  {
    //leaf logic
    t[index]=node(arr[l],1);
    return;
  }
  int mid= (l+r)/2;
  build(index*2,l,mid);
  build(index*2+1,mid+1,r);

  t[index]=merge(t[2*index],t[2*index+1]);
}

void update(int index,int l,int r,int pos,int val)
{
  if(pos<l or pos>r)
    return;
  if(l==r)
  { 
    //leaf condition
    t[index]= node(val,1);
    arr[l]=val;
    return;
  }
  int mid= (l+r)/2;
  update(index*2,l,mid,pos,val);
  update(index*2+1,mid+1,r,pos,val);

  t[index]=merge(t[2*index],t[2*index+1]);
}

node query(int index,int l,int r,int lq,int rq)
{
  if(l>rq or r<lq)
    return node();   
  
  if(lq<=l and r<=rq)
    return t[index];

  int mid=(l+r)/2;
  return merge(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
}

void solve()
{
    int n;
    cin>>n;
    
    int arr[n];
    
    loop(i,n)
    {    cin>>arr[i];
         update(1,0,n-1,i,arr[i]);
    }

    struct node a=query(1,0,n-1,0,3);
    cout<<a.mini<<" "<<a.count<<endl;   
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