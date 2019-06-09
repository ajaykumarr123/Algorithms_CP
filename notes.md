```#include <bits/stdc++.h> ```  //for everything

* In C++, to set them all to -1, you can use something like std::fill_n (from <algorithm>):
   std::fill_n(array, 100, -1);   
```c++

 #pragma GCC optimize("Ofast")


#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define endl '\n'

typedef long long int ll;

ll mod=1e9+7;
ll mod1=998244351;
ll power(ll a,ll b)
{
    if(b==0) return 1;
    else if(b%2==0)
        return power(a*a%mod,b/2)%mod;
    else return (a%mod*power(a*a%mod,b/2))%mod;
}


ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

int main()
{

    IOS
    //cout<<log2(16777216)<<endl;
       #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

return 0;
}
```
* Declaration of 2D characters array
```
char name[5][10]={
                   "tree",
                   "bowl",
                   "hat",
                   "mice",
                   "toon"
                 };
```

# vectors
```vector<int>v; ```      //creates an empty vector of integers)
int size=v.size();

v.push_back(x);   //Pushing an integer into a vector

v.pop_back();     //Popping the last element from the vector

sort(v.begin(),v.end()); //Sorting a vector


erase(int position)  //Removes the element present at position.  
       Ex: v.erase(v.begin()+4); (erases the fifth element of the vector v)

erase(int start,int end)  //Removes the elements in the range from start to end inclusive of the start and exclusive of the end.
       Ex:v.erase(v.begin()+2,v.begin()+5);   (erases all the elements from the third element to the fifth element.)
