#### try stress test(algo. toolbox) to remove error
```#include <bits/stdc++.h> ```  //for everything

```cout << fixed << setprecision(9);```  //to change decimal precision - use once in beg. of main

* In C++, to set them all to 0, you can use something like std::fill_n (from <algorithm>): </br>
   std::fill_n(arr, 100, 0); or
   memset(arr, 0, sizeof(arr));
   
  * a x b = LCM(a, b) * GCD (a, b)
  * LCM(a, b) = (a x b) / GCD(a, b) 
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
```vector<int>v;     //creates an empty vector of integers)
int size=v.size();

v.push_back(x);   //Pushing an integer into a vector

v.pop_back();     //Popping the last element from the vector

sort(v.begin(),v.end()); //Sorting a vector


erase(int position)  //Removes the element present at position.  
       Ex: v.erase(v.begin()+4); (erases the fifth element of the vector v)

erase(int start,int end)  //Removes the elements in the range from start to end inclusive of the start and exclusive of the end.
       Ex:v.erase(v.begin()+2,v.begin()+5);   (erases all the elements from the third element to the fifth element.)
 ```      
 ### to find all factors
 
 ``` 
 void print_factors(int n)
 {
    for(int j=1;j*j<=n;j++)
      {  
        if(min%j==0)
       {   f1=j;  f2=min/j; 
       
          cout<<f1<<" "<<f2<<" ";
       }
      }
 }   
```
# auto
If C++ already knows 5.0 is a double literal, why do we have to explicitly specify that d is actually a double? 
Starting with C++11, the auto keyword does just that.
```
auto d = 5.0; // 5.0 is a double literal, so d will be type double
auto i = 1 + 2; // 1 + 2 evaluates to an integer, so i will be type int
```
# 2-d vector
```
vector<int> pos[26];
	forn(i, n)
		pos[s[i] - 'a'].push_back(i + 1);

```

# Map,Pair,Tuple

### [tuple](https://www.geeksforgeeks.org/tuples-in-c/)
(check knapsack code-github)
1. get() :- get() is used to access the tuple values and modify them, it accepts the index and tuple name as arguments to access a particular tuple element.
2. make_tuple() :- make_tuple() is used to assign tuple with values. The values passed should be in order with the values declared in tuple.

