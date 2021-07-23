/*****************************************************************/
/* Recursive lambda replace auto with std::function<int(int,int)> */
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 

int fastexp(int b, int exp){
  if (exp==0)
    return 1;
  int temp=fastexp(b,exp/2);
  temp=(1ll*temp*temp)%MOD;
  if (exp%2==1)
    temp*=b;
  return temp%MOD;
}

int inverse (int b) { return fastexp(b,MOD-2);} 


/*****NCR , fact ******/ 
int MAXN=3e5;
int fact[MAXN],inv[MAXN];

void precompute(){         //compute all fact/inv till MAXN
  fact[0]=1;
  inv[0]=1;
  for (int i=1;i<MAXN;i++){
    fact[i]=(fact[i-1]*i)%MOD;
    inv[i]=fastexp(fact[i],MOD-2);

    //cout<<(1ll*fact[i]*inv[i])%MOD<<endl;
  }
}

int computeNCR(int n,int r)
{
  return ((fact[n]*inv[r])%MOD*inv[n-r])%MOD;
}
///////////////////////////////////

int choose[405][405],pow2[405];
void precompute2()        //find nCr  **N**
{

  for (int i=0;i<=N;i++)
    for (int j=0;j<=i;j++)
      choose[i][j]=((fact[i]*inv[j])%MOD*inv[i-j])%MOD;
  for (int i=0;i<=N;i++)
    pow2[i]=fastexp(2,i);
}
/**********************************************************/

/********************LPS(KMP Algorithm)*********************/
//longest proper suffix that is also prefix(1-indexed)

vector<int> lps(string &s)
{
  int n=s.size();
  vector<int> lps(n+1);
  int i=0,j=-1; lps[0]=-1;

  while(i<n)
  {
    while(j!=-1 and s[j]!=s[i]) j=lps[j];
    i++;j++; lps[i]=j;
  }

  return lps;
} 
 /********************String Hashing************************/
    int hash_value,hash_value1;

    const long long m1 = 1e9 + 7;
    const long long m2 = 1e9 + 9;
    const long long p = 37;
    const int MAXN = 1e6;
    vector<long long> pow1(MAXN), pow2(MAXN);
    void compute_hash(string const& s) 
    {

        hash_value=0;
        hash_value1=0;

        long long int p_pow = 1;
        for (int i = 0; i < s.size(); ++i)
         {
            hash_value = (hash_value + (((s[i] - 'a' + 1) * pow1[i])%m1)) % m1;
            hash_value1 = (hash_value1 + (((s[i] - 'a' + 1) * pow2[i])%m2)) % m2;
        }
    }
    void precompute()
    {
      pow1[0]=1;
      pow2[0]=1;
      for (int i = 1; i<MAXN; ++i)
      {
        pow1[i]=(1LL*pow1[i-1]*p)%m1;
        pow2[i]=(1LL*pow2[i-1]*p)%m2;        
      }
    }
/**********************************************************/


//set with manual sorting

struct comp {
  bool operator() (int a, int b) const {
    if (leaves[a].size() == leaves[b].size()) return a < b;
    return leaves[a].size() > leaves[b].size();
  }
};

set<int, comp> st;

/****************************************************************/

struct node()
{
  int a,b,l,r;
  
   bool friend operator<(node a,node b){
        return a.r > b.r;
}
/****************************************************************/
// Interactive Problem
int query(int l1, int r1, int l2, int r2) {
  printf("Q %d %d %d %d\n", l1, r1, l2, r2);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}
///////////////////////////////////////////////////////////////////



///////////////// generating SPF for every number till 10^7
  const int N = 2e5;
  vector<int> spf(N+1,0);
   
  void generate()
  {
      for(int i=3;i*i<=N;i+=2)
      {
          if(spf[i]==i)
          {
              for(int j=i*i;j<=N;j+=i)
              {
                  if(spf[j]==j)spf[j]=i;
              }
          }
      }
  }

  for(int i=0;i<=N;i++)spf[i]=i;
  for(int i=2;i<=N;i+=2)spf[i]=2;
  
  generate();

////////////////////////////////////////////////////////


///////////////find all iCj (i<=(m+n) and j<m)/////////////////////////
//also dp[i][j] the total number of strings consisting with i a’s and j b’s
  dp[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
 ////////////////////////////////////////////////////////////////////////




////////////////////////Binary lifting////////////////////////////////
const int LOG=20;
int up[MAXN][LOG];  //up[v][j] is 2^j-th ancestor of v
int depth[MAXN];        

void add_bl(int v, int p)
{
 
    up[v][0]= p;
    depth[v]=depth[p]+1;    
    for(int j=1; j<LOG; j++)
    {
        up[v][j]= up[up[v][j-1]][j-1];
    }
}
 
int getKthP(int v, int k)  //get kth parent
{
    for(int j=LOG-1; j>=0; j--)  // or for(int j=0; j<LOG; j++)
    {
        if(k&(1<<j))
        {
            v= up[v][j];
        }
    }
    return v;
}


void dfs(int node,int p) { /***call dfs(root,root)****/

  depth[node] = depth[p] + 1;
  for(int x : g[node]) {
    if(x!=p)
     { 
      add_bl(x,node);
      dfs(x);
    }
  }
}

int get_lca(int a, int b) { // O(log(N))
  if(depth[a] < depth[b]) {
    swap(a, b);
  }
  // 1) Get same depth.
  int k = depth[a] - depth[b];
  for(int j = LOG - 1; j >= 0; j--) {
    if(k & (1 << j)) {
      a = up[a][j]; // parent of a
    }
  }
  // 2) if b was ancestor of a then now a==b
  if(a == b) {
    return a;
  }
  // 3) move both a and b with powers of two
  for(int j = LOG - 1; j >= 0; j--) {
    if(up[a][j] != up[b][j]) {
      a = up[a][j];
      b = up[b][j];
    }
  }
  return up[a][0];
}


////////////////////////////////////////////////////////////////////////