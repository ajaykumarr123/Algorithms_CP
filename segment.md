# ordered set
```
// ordered set in GNU C++ 
#include <bits/stdc++.h> 
using namespace std; 

/*****************************************/
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> 
//find_by_order(k)  returns iterator to kth element starting from 0;
//order_of_key(k) returns count of elements strictly smaller than k;
//erase,insert same as normal set
/*****************************************/

int main() 
{ 
	// Ordered set declared with name o_set 
	ordered_set o_set; 

	// insert function to insert in 
	// ordered set same as SET STL 
	o_set.insert(make_pair(5,1)); 
	o_set.insert(make_pair(3,2)); 
	o_set.insert(make_pair(9,3)); 

	// Finding the second smallest element 
	// in the set using * because 
	// find_by_order returns an iterator 
	cout << (*(o_set.find_by_order(1))).first 
		<< endl; 

	// Finding the number of elements 
	// strictly less than k=4 
	cout << o_set.order_of_key(make_pair(5,1)) 
		<< endl; 

	// Finding the count of elements less 
	// than or equal to 4 i.e. strictly less 
	// than 5 if integers are present 
	cout << o_set.order_of_key(make_pair(5,1)) 
		<< endl; 

	// Deleting 2 from the set if it exists 
	if (o_set.find(make_pair(5,1)) != o_set.end()) 
		o_set.erase(o_set.find(make_pair(5,1))); 

	// Now after deleting 2 from the set 
	// Finding the second smallest element in the set 
	cout << (*(o_set.find_by_order(1))).first 
		<< endl; 

	// Finding the number of 
	// elements strictly less than k=4 
	cout << o_set.order_of_key(make_pair(3,1)) 
		<< endl; 

	return 0; 
} 

```

# [segment tree](https://www.topcoder.com/community/competitive-programming/tutorials/range-minimum-query-and-lowest-common-ancestor/#Lowest%20Common%20Ancestor%20(LCA))
### General(basic version)
```
//segment tree(RMQ) 
//0-indexed
#include <bits/stdc++.h>
using namespace std;
const int maxn=100000;
int n,t[4*maxn];
int construct(int* arr,  int st, int end, int si)
{
    if(st==end)
    {
        t[si] = arr[st];
        return t[si];
    }
    
    int mid = (st + end)/2;
    construct(arr,st, mid, 2*si + 1);
    construct(arr,mid+1, end, 2*si + 2);
    t[si] = min(t[2*si+1],t[2*si+2]);
    return t[si];
}

int query(int qs, int qe, int ss, int se, int si)
{
    if(qs<=ss && qe>=se)
       return t[si];
    
    if(qs>se || qe<ss)
       return INT_MAX;          //change  acc. to question
    
    int mid = (ss + se)/2;
    int sum = min(query(qs, qe, ss, mid, 2*si + 1), query(qs, qe, mid+1, se, 2*si + 2));
    return sum;
}

void update( int x, int pos, int ss, int se, int si)
{   
    if(ss==se)
    {
        t[si] =  x;
        return;
    }
    
    int mid = (ss + se)/2;
    if(pos<=mid)
      update( x, pos, ss, mid, 2*si + 1);
    else
      update(x, pos, mid+1, se, 2*si + 2);

    t[si] = min(t[2*si+1] , t[2*si+2]);     
}

int main()
{  
     #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
      #endif
  
    cin>>n;
    
    int* arr = new int[n];
    for(int i=0; i<n; i++)
      cin>>arr[i];
    
 
    for(int i=0; i<=4*n; i++)
      t[i] = -1;

    construct(arr, 0, n-1, 0);
    
    int qs;
    int qe;
    cin>>qs>>qe;
    
    int sum = query(qs, qe, 0, n-1, 0);
    
    for(int i=0; i<=4*n; i++)
    {
        if(t[i]==-1)
          cout<<"dummy ";
        else
          cout<<t[i]<<" ";
    }
    cout<<endl;
    cout<<sum<<endl;
    
    int add;
    cin>>add;
    int index;
    cin>>index;
    
    update(add, index, 0, n-1, 0);
    cin>>qs>>qe;
    
    int sum1 = query(qs, qe, 0, n-1, 0);
    cout<<sum1<<endl;
    
}
```
# range update using lazy propagation 
[problem](https://www.codechef.com/problems/MAXBTY)

```
#include<bits/stdc++.h>
#include<unordered_map>
#define M 1000000007
#define T 998244353
#define PI 3.142
#define ll long long
#define MAXN 100001


using namespace std;
ll tx[4*MAXN], tn[4*MAXN], lx[4*MAXN], ln[4*MAXN];
ll maxi(ll a, ll b)
{
    return (a>b)?a:b;
}
ll mini(ll a, ll b)
{
    return (a<b)?a:b;
}
void buildx(ll pre[], ll v, ll tl, ll tr)
{
    if(tl==tr){
        tx[v] = pre[tl];
    }
    else {
        ll tm = (tl+tr)/2;
        buildx(pre, 2*v, tl, tm);
        buildx(pre, 2*v+1, tm+1, tr);
        tx[v] = maxi(tx[2*v], tx[2*v+1]);
    }
}
void buildn(ll pre[], ll v, ll tl, ll tr)
{
    if(tl==tr){
        tn[v] = pre[tl];
    }
    else {
        ll tm = (tl+tr)/2;
        buildn(pre, 2*v, tl, tm);
        buildn(pre, 2*v+1, tm+1, tr);
        tn[v] = mini(tn[2*v], tn[2*v+1]);
    }
}
void pushx(ll v)
{
    tx[2*v] += lx[v];
    lx[2*v] += lx[v];
    tx[2*v+1] += lx[v];
    lx[2*v+1] += lx[v];
    lx[v]=0;
}
void pushn(ll v)
{
    tn[2*v] += ln[v];
    ln[2*v] += ln[v];
    tn[2*v+1] += ln[v];
    ln[2*v+1] += ln[v];
    ln[v]=0;
}
void updatex(ll v, ll tl, ll tr, ll l, ll r, ll add){
    if(l>r){
        return;
    }
    if(l==tl && tr==r){
        tx[v] += add;
        lx[v] += add;
    }
    else {
        pushx(v);
        ll tm = (tl+tr)/2;
        updatex(2*v, tl, tm, l, mini(r, tm), add);
        updatex(2*v+1, tm+1, tr, maxi(l, tm+1), r, add);
        tx[v] = maxi(tx[2*v], tx[2*v+1]);
    }
}
void updaten(ll v, ll tl, ll tr, ll l, ll r, ll add){
    if(l>r){
        return;
    }
    if(l==tl && tr==r){
        tn[v] += add;
        ln[v] += add;
    }
    else {
        pushn(v);
        ll tm = (tl+tr)/2;
        updaten(2*v, tl, tm, l, mini(r, tm), add);
        updaten(2*v+1, tm+1, tr, maxi(l, tm+1), r, add);
        tn[v] = mini(tn[2*v], tn[2*v+1]);
    }
}
ll qux(ll v, ll tl, ll tr, ll l, ll r)
{
    if(l>r){
        return INT64_MIN;
    }
    if(l==tl && r==tr){
        return tx[v];
    }
    pushx(v);
    ll tm = (tl+tr)/2;
    return maxi(qux(2*v, tl, tm, l, mini(r, tm)), qux(2*v+1, tm+1, tr, maxi(l, tm+1), r));
}
ll qun(ll v, ll tl, ll tr, ll l, ll r)
{
    if(l>r){
        return INT64_MAX;
    }
    if(l==tl && r==tr){
        return tn[v];
    }
    pushn(v);
    ll tm = (tl+tr)/2;
    return mini(qun(2*v, tl, tm, l, mini(r, tm)), qun(2*v+1, tm+1, tr, maxi(l, tm+1), r));
}
void solve()
{
    ll n, q, i, x, y, ans1, ans2, v, dif;
    cin >> n >> q;
    ll b[n], pre[n];
    for(i=0; i<n; i++){
        cin >> b[i];
    }
    pre[0]=b[0];
    for(i=1; i<n; i++){
        pre[i] = pre[i-1]+b[i];
    }
    for(i=1; i<=4*n; i++){
        lx[i]=0;
	ly[i]=0;
    }
    
    
    buildx(pre, 1, 0, n-1);
    buildn(pre, 1, 0, n-1);
    for(i=0; i<q; i++){
        char ch;
        cin >> ch;
        if(ch=='Q'){
            cin >> x >> y;
            x--;
            y--;
            ans1 = qux(1, 0, n-1, y, n-1);
            ans2 = qun(1, 0, n-1, 0, x-1);
            if(ans2>0){
                ans2 = 0;
            }
            cout << ans1 - ans2 << "\n";
        }
        else {
            cin >> x >> v;
            x--;
            dif = v - b[x];
            b[x]=v;
            updatex(1, 0, n-1, x, n-1, dif);
            updaten(1, 0, n-1, x, n-1, dif);
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int _t;cin >> _t; while(_t--)
    solve();

    return 0;
}
```


## Range query for Largest Sum Contiguous Subarray 
[gfg](https://www.geeksforgeeks.org/range-query-largest-sum-contiguous-subarray/)
</br>
for maximun prefix sum or suffix sum or sum in query range 
for eg- query(2,4) its prefix will give max(a2,a2+a3,a2+a3+a4) starting from l(not 0) similary for suffix starting from r(not n-1)


``` 
//1-inexed segment tree for query and update
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll int

int n;
int a[100001];

struct data {
    int sum, pref, suff, ans;
};
data t[400001];

data combine(data l, data r) {
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
data make_data(int val) {
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max((ll)0, val);
    return res;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_data(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_data(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
data query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return make_data(0);
    if (l == tl && r == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int q;
		cin>>q;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		build(1,1,n);
		while(q--)
		{
			char ch;
			cin>>ch;
			if(ch=='Q')
			{
				int x,y;
				cin>>x>>y;
				data p=query(1,1,n,x,y);
				int s=p.sum;
				int s1=0;
				if(x!=1)
				{
					data r=query(1,1,n,1,x-1);
					int pq=r.suff;
					if(pq>0)
						s1+=pq;
				}
				if(y!=n)
				{
					data r=query(1,1,n,y+1,n);
					int pq=r.pref;
					if(pq>0)
						s1+=pq;
				}
				cout<<s1+s<<endl;
			}
			else
			{
				int x,y;
				cin>>x>>y;
				update(1,1,n,x,y);
			}
		}

	}
}     
```


