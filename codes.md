## Road Signs  ([june long](https://www.codechef.com/JUNE19))
### Modular Exponentation [gfg](https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/)  [ytb](https://www.youtube.com/watch?v=EHUgNLN8F1Y)
```
// used--modular exponentation to remove tle or WA due to very long number 
// to find (2^(n-1))%p n<=10^9


#include <bits/stdc++.h>
using namespace std;
unsigned long long int p = 1000000007; 
  
/* Iterative Function to calculate (x^y)%p in O(log y) */
unsigned long long int power(unsigned long long int x,  unsigned long long int y) 
{ 
   unsigned long long int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
  
// Driver program to test above functions 
int main() 
{ int t;
  cin>>t;
  
  while(t--)
  {
   unsigned long long int x = 2; 
   unsigned long long int y;
   cin>>y;
   y--;
 
   cout<< ((power(x, y)%p)*10)%p; 
   
   cout<<endl;
  }
   return 0; 
} 
