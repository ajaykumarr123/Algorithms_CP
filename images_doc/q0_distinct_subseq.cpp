/********************************************************************************/
//number of distinct subsequence(without null string)
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


void solve()
{
    string s;
    cin>>s;

    map<char,int> mp;
    int allcount=0,levelcount=0;
    for(int i=0;i<s.size();i++)
    {
        levelcount=allcount+1;

        allcount=allcount+levelcount-mp[s[i]];
        mp[s[i]]=levelcount;
    }

    cout<<allcount<<endl;
    

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