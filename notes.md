### [DP with Bitsmask](https://codingblocks.com/resources/dp-webinar2/)
#####  [Tshirts](https://www.codechef.com/problems/TSHIRTS)

#### Try stress test(algo. toolbox) to remove error

```cout << fixed << setprecision(9);```  //to change decimal precision - use once in beg. of main
* [Trie](https://www.geeksforgeeks.org/trie-insert-and-search/)

 	Data Structure can be used in computing distinct substring or more substring problems.</br>
eg [problem](https://codeforces.com/contest/271/problem/D) [code](https://codeforces.com/contest/271/submission/61939688)
</br> search time complexity can be reduced from O(no. of words) to O(length of word) </br> string sorting in O(sum of length of all words)

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

## Pair
```
pair  g1;         //default
pair  g2(1, 'a');  //initialized,  different data type
pair  g3(1, 10);   //initialized,  same data type
pair  g4(g3);    //copy of g3
Another way to initialize a pair is by using the make_pair() function.
g2 = make_pair(1, 'a');

    g1.first = 100; 
    g1.second = 'G' ; 
  
    cout << g1.first << " " <<g1.second; 
```
#### vector of Pairs(array) [link](https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-1-sort-by-first-and-second/)
```
// Declaring vector of pairs 
    vector< pair <int,int> > vect; 

    for (int i=0; i<n; i++)                      // Entering values in vector of pairs           
        vect.push_back( make_pair(arr[i],arr1[i]) ); 
 
    for (int i=0; i<n; i++) 			  // Printing the original vector(before sort()) 
        cout << vect[i].first << " "<< vect[i].second; 
	
    //Sorting the vector elements on the basis of 
   	 sort(vect.begin(),vect.end());		//first element of pairs in ascending order
    	 sort(vect.begin(), vect.end(), sortbysec);    //second element of pairs in ascending order
```

## [Map](https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/)
```  
begin() – Returns an iterator to the first element in the map
end() – Returns an iterator to the theoretical element that follows last element in the map
size() – Returns the number of elements in the map
empty() – Returns whether the map is empty
insert(keyvalue, mapvalue) – Adds a new element to the map
erase(iterator position) – Removes the element at the position pointed by the iterator
erase(const g)– Removes the key value ‘g’ from the map
clear() – Removes all the elements from the map


  map<int, int> mp;  //declaration    
  
   // insert elements in random order 
    mp.insert({ 2, 30 });                   or  *** mp[2]=30;  ****
   
   map<int, int>::iterator itr; 
    cout << "\nThe map gquiz1 is : \n"; 
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) { 
        cout<< itr->first << '\t' << itr->second << '\n'; 
    } 

    // assigning the elements from gquiz1 to gquiz2 
    map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());
    
    // remove all elements with key = 4 
    int num; 
    num = gquiz2.erase(4);     
```

## [Tuple](https://www.geeksforgeeks.org/tuples-in-c/)  
(check knapsack code-github)  </br>

1. get() :- get() is used to access the tuple values and modify them, it accepts the index and tuple name as arguments to access a particular tuple element.
2. make_tuple() :- make_tuple() is used to assign tuple with values. The values passed should be in order with the values declared in tuple.
```
     tuple <char, int, float> geek; //declaration
  
    // Assigning values to tuple using make_tuple() 
    geek = make_tuple('a', 10, 15.5); 
 ```

