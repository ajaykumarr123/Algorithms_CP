## Trie data structure ([problem](https://codeforces.com/contest/271/problem/D))

``` 
//*****IAMTGPEBOTP*****************
#include <bits/stdc++.h>
using namespace std;
 
struct node
{
  struct node *A[26];
};
 
void assign_zero(node *p)
{
    for(int i=0;i<26;i++)
      (*p).A[i]=NULL;
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  string s;
  cin>>s;
 
  string gb;
  cin>>gb;
 
  int k;
  cin>>k;
  int ans=0;
 
   node *root;
   root= new node;
 
   assign_zero(root);
 
 
   for(int i=0;i<s.size();i++)
   {
      node *temp=root;
      int count=0;
 
      for(int j=i;j<s.size();j++)
      {
 
        if(gb[s[j]-'a']=='0')
          count++;
 
        if(count>k)
          break;
 
        int r=s[j]-'a';
 
        if(temp->A[r]==NULL)
        {
           node *pp=new node;
           assign_zero(pp);
           temp->A[r]=pp;
           temp=pp;
           ans++;
        }
 
        else
          temp=temp->A[r];
 
      }
   }
   
   cout<<ans;
 return 0;
}
```

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
### dp parenthesis couresera
```
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}
long long get_maximum_value(const string &exp) {
    long n = exp.length()/2 + 1;
    vector< vector<long> > m(n, vector<long> (n, 0));
    vector< vector<long> > M(n, vector<long> (n, 0));
    vector<long >numbers;
    vector<char >op;

    for (int i = 0; i <  exp.size(); i++){
        if (i%2==0){numbers.push_back((long ) exp[i] - 48);}
        else{op.push_back(exp[i]);}
    }

    for(int i = 0; i < numbers.size(); i++){
        m[i][i] = numbers[i];
        M[i][i] = numbers[i];
    }
    for (int s=1; s < numbers.size(); s++){
        for (int i=0; i < numbers.size()-s; i++){
            int j = i + s;
            long max_value = numeric_limits<long>::min();
            long min_value = numeric_limits<long>::max();
            for (int k = i; k <=  j-1; k++){
                long a = eval(M[i][k], M[k+1][j], op[k]);
                long b = eval(M[i][k], m[k+1][j], op[k]);
                long c = eval(m[i][k], M[k+1][j], op[k]);
                long d = eval(m[i][k], m[k+1][j], op[k]);
                max_value = max(max_value,max(a, max(b, max(c, d))));
                min_value = min(min_value,min(a, min(b, min(c, d))));
            }
            pair<long, long>min_max;
            min_max.first = min_value;
            min_max.second = max_value;
            m[i][j] = min_max.first;
            M[i][j] = min_max.second;
        }
    }
    return M[0][numbers.size()-1];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
```
