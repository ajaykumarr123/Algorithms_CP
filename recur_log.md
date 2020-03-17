```
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
 #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
ll mod=1e9+7;
ll mod1=1e9+7;
 ll power(ll a,ll b)
    {
        if(b==0) return 1;
        else if(b%2==0)
            return power((((a%mod)*(a%mod))%mod),b/2)%mod;
        else return ((a%mod)*(power((((a%mod)*(a%mod))%mod),b/2)%mod))%mod;
    }
     
 
 
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
ll mat[2][2];

void mult(ll mat1[2][2],ll mat2[2][2],int n)
{   ll res[2][2];
     for (int i = 0; i < n ;i++) 
    { 
        for (int j = 0; j <n; j++) 
        { 
            res[i][j] = 0; 
            for (int k = 0; k < n; k++) 
              res[i][j]=(res[i][j] +mat1[i][k] * mat2[k][j])%mod;
        } 
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            mat[i][j]=res[i][j];
    }
}
void expo(ll k,int n)
{

    if(k==1)
        return ;
    else if(k%2==0)
    {
            mult(mat,mat,n);
            expo(k/2,n);
    }
    else
    {
        ll temp[2][2];
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                temp[i][j]=mat[i][j];
            mult(mat,mat,n);
            
            expo(k/2,n);   
            mult(temp,mat,n);
    }
}
int fib(int n)
{
    
    if(n==1)
        return 2;
    if(n==0)
        return 1;
    if(n<0)
        return 0; 

    mat[0][0]=2;
    mat[0][1]=2;
    mat[1][0]=1;
    mat[1][1]=0;
    expo(n-1,2);
    int ans=(2*mat[0][0])%mod+mat[0][1];
    ans%=mod;
    return ans;

}
 
 
int32_t main()
{
    IOS

    //  #ifndef ONLINE_JUDGE    
    // freopen("input.txt", "r", stdin);    
    // #endif        
        
     int t;
     cin>>t;
     while(t--)
     {
        int n;
        cin>>n;
    
        int ans=fib(n);
        
        cout<<ans<<endl;    
     }
}
