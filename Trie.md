
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
## XOR MAX ([problem](https://codeforces.com/contest/282/problem/E))
```
//In the name of God
#include <iostream>
#include <deque>
using namespace std;
 
const int MAXN=1e6+1e3;
#define num long long
num all[MAXN];
 
struct node
{
  node *child[2];
  node()
  {
    child[0]=child[1]=NULL;
  }
};
 
node *root;
 
deque<short> binary(long long x)
{
  deque<short> ans;
  while(x)
    {
      ans.push_front(x%2);
      x/=2;
    }
  while(ans.size()<50)
    ans.push_front(0);
  return ans;
}
 
void add(long long x)
{
  deque<short> a=binary(x);
  node *C=root;
  while(a.size())
    {
      if(C->child[a[0]]==NULL)
    C->child[a[0]]=new node;
      C=C->child[a[0]];
      a.pop_front();
    }
}
 
long long query(long long x)
{
  deque<short> a=binary(x);
  long long ans=0;
  node *C=root;
  while(a.size())
    {
      if(C->child[1-a[0]]!=NULL)
    {
      C=C->child[1-a[0]];
      ans*=2;
      ans+=1;
    }
      else
    {
      C=C->child[a[0]];
      ans*=2;
    }
      a.pop_front();
    }
  return ans;
}
 
int main()
{
  root=new node;
  int n;
  cin>>n;
  num xorall=0;
  for(int i=1;i<=n;++i)
    {
    cin>>all[i];
    xorall^=all[i];
    }
  num maxgot=0;
  int ai=0,bi=0;
  num total=0;
  add(total);
  for(int i=1;i<=n;++i)
    {
      total^=all[i];
      add(total);
      maxgot=max(maxgot,query(total^xorall));
    }
  cout<<fixed<<maxgot<<endl;
  return 0;
}
```

