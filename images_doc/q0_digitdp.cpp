//Atcoder Educational DP-Problem S 
//count number of numbers b/w 1-R with sum of digits mutiple of D
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

int dp[10001][2][2][101];
string L,R;
int D;
int len;

int rec(int idx,int hi,int lo,int sum)
{
    if(idx==len)
    {
        if(sum==0)
            return 1;
        else
            return 0;
    }

    if(dp[idx][hi][lo][sum]==-1)
    {
        int ans=0;
        int loLimit=0;
        int hiLimit=9;

        if(hi)
            hiLimit=R[idx]-'0';
        if(lo)
            loLimit=L[idx]-'0';

        for(int i=loLimit;i<=hiLimit;i++)
        {   int nhi=hi;
            int nlo=lo;
            if(i!=hiLimit)
            {
                nhi=0;
            }
            if(i!=loLimit)
            {
                nlo=0;
            }

          
            ans+=rec(idx+1,nhi,nlo,(sum+i)%D);
            ans%=MOD;
        }

        dp[idx][hi][lo][sum]=ans;
    }

    return dp[idx][hi][lo][sum];
}

void solve()
{   
    L="1";
    cin>>R>>D;
    
    int leng=R.length()-L.length();
    string temp="";

    while(leng--)
        temp+='0';
    
    L=temp+L;
    len=L.size();

    memset(dp,-1,sizeof(dp));
    
    int x= rec(0,1,1,0);
    cout<<x<<endl;


}

int32_t main()
{ IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    int t=1;
    //cin>>t;
    
    for (int i = 1; i <= t; ++i)
    {
     //cout<<"Case #"<<i<<": ";
     //solve();
    }
    return 0; 
}