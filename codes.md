## Greedy common([CANDIES](https://www.hackerrank.com/challenges/candies/editorial))
```
 #include <bits/stdc++.h>
 #define forn(i,n) for(int i=0;i<n;i++)
 #define forrev(n,i) for(int i=n;i>0;i--)
 typedef long long int ll;
 using namespace std;
int main()
{    int n;
     cin>>n;
    int a[n],v[n];
    forn(i,n) cin>>a[i];
   
    v[0]=1;
    forn(i,n-1){                   // for rise
     if(a[i+1]>a[i])
      v[i+1]=v[i]+1;

      else
      v[i+1]=1;  		//for valley
  }
    ll ans=v[n-1];
    v[n-1]=1;
    
    forrev(n-1,i){              // for fall
       int tmp;
       if(a[i-1]>a[i])
       tmp=v[i]+1;

       else
         tmp=1;

         ans+=max(tmp,v[i-1]);         //for peak
         
         v[i-1]=tmp;
    } 
     cout<<ans;
 return 0;}

```
## Road Signs  ([june long](https://www.codechef.com/JUNE19))
### Modular Exponentation [gfg](https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/)  [ytb](https://www.youtube.com/watch?v=EHUgNLN8F1Y)
```
// used--modular exponentation to remove tle or WA due to very long number 
// to find (2^(n-1))%p n<=10^9


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; 
ll mod=1e9+7;
ll power(ll a,ll b)
{
    if(b==0) return 1;
    else if(b%2==0)
        return power(a*a%mod,b/2)%mod;
    else return (a%mod*power(a*a%mod,b/2))%mod;
}

int main()
{
int t;
cin>>t;

while(t--)
{
   ll k;
   cin>>k;
   k--;
   cout<<(power(2,k)*10)%mod;

cout<<endl;

}

return 0;
}
```
# 2-D vector 
   [problem link](https://codeforces.com/contest/1187/problem/B)

```
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n, m;
string s, t;
vector<int> pos[26];

int main() {
	cin >> n >> s;
	forn(i, n)
		pos[s[i] - 'a'].push_back(i + 1);
	
	cin >> m;
	forn(i, m){
		cin >> t;
		vector<int> cnt(26);
		for (auto &c : t)
			++cnt[c - 'a'];
		int ans = -1;
		forn(j, 26) if (cnt[j] > 0)
			ans = max(ans, pos[j][cnt[j] - 1]);
		cout << ans << "\n";
	}
	return 0;
}
```
