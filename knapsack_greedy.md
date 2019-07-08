# knapsack greedy problem

```
#include <bits/stdc++.h>
#include <vector>
using namespace std; 
using std::vector;

vector< tuple  <  double,int,int >  > v; 

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {

  double value = 0.0;

  int n=weights.size();
  double s;

 
  for(int i=0;i<n;i++)
  { s=(double)values[i]/weights[i];
    v.push_back(make_tuple(s,values[i],weights[i])) ;
  }
  
  sort(v.begin(),v.end());

  long long int total=0,weight;
  for(int i=n-1;i>=0;i--)
  {
       
       weight=get<2>(v[i]);
       
       
         
       if((total+weight)>capacity) 
       { long long int x=capacity-total;
          
          value+=((get<1>(v[i]))*x)/((double)weight);
           break;
       }

       else
        value+=get<1>(v[i]);

      total+=weight;
      
      if(total==capacity)
         break;      
      
  }


  return value;
}

int main() {

  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
```
