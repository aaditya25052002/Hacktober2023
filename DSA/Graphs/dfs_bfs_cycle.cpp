#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//#pragma GCC optimize('O2') 
#define ll long long 
#define vll vector<ll>
#define vi vector<int>
#define tin tuple<ll,ll,ll>
#define mll map<ll,ll>
#define pi pair<ll,ll>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define rall(x) x.rbegin(), x.rend()
#define watch(x) cout << (#x) << ' is ' << (x) << endl
#define f(i,x,z) for(ll i=x;i<z;i++)
#define rf(i,x,z) for(ll i=x-1;i>=z;i--)
#define deb(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define clr(x) memset(x, 0, sizeof(x)) 
#define fa(i,vect) for(auto i : vect)
#define fr(i,vect) for(VI :: reverse_iterator i = vect.rbegin(); i != vect.rend(); i++)
#define s(a) (a).size()
#define mod 1000000007
// get<0>(v[i])
// unordered_map<string, int> umap;
// s.insert(0);multiset<int> ms;
//auto it = s.lower_bound(a);
//for (auto me : m) {
//std::vector<ll>::iterator it; 
//it = std::find (v.begin(), v.end(), ser);
//v.erase(v.begin() +n);
# define INF 0x3f3f3f3f 
const int MAX = 1e3 + 7; 
////////////////////////////////////////////////////////////////////////////////////////////
vector<bool> vis1(5,false);
vector<int> color(5,0);
vector<bool> vis2(5,false);
ll power(ll base,ll por)
{
  ll res=1;
   while(por>1){
      if(por%2==1)
      {
         res*=base;
         por--;
      }
      por/=2;
      base*=base;
   }
   res*=base;
   return res;
}

ll mo(ll a, ll b) {
     ll c = a % b;
     return (c < 0) ? c + b : c;
  }


long long gcd(long long  a, long long  b)
{
   if (b == 0)
     return a;
     return gcd(b, a % b);
}

long long lcm(ll a, ll b)
{
      return (a / gcd(a, b)) * b;
}
 ll dtob (ll a)
{  ll r=1;
   while((a&r)==0)r*=2;
   return r;
}

void addedge(vector<int> adj[],int a, int b)
{
   adj[a].pb(b);
   adj[b].pb(a);
}

void bfs(vector<int> adj[], int root,int t)
{
   queue<int> q;
   vector<bool> vis(t,false);
   q.push(root);
   vis[root]=true;
   cout<<root<<" \n";
   while(!q.empty())
   {
      for(int i=0;i<adj[q.front()].size();i++)
      {
         if(vis[adj[q.front()][i]]==false)
         {
            vis[adj[q.front()][i]]=true;
            q.push(adj[q.front()][i]);
            cout<<adj[q.front()][i]<<" ";
         }
      }
      q.pop();
      cout<<"\n";
   }
}

void trav(vector<int> adj[], int root,int parent)
{
   for(int i=0;i<adj[root].size();i++)
   {
      if(vis1[adj[root][i]]==false)
      {
         cout<<adj[root][i]<<"\n";
         vis1[adj[root][i]]=true;
         trav(adj,adj[root][i],root);
      }
      else if(adj[root][i] != parent)
      {
         cout<<adj[root][i]<<" THis point has cycle\n";
      }
   }
   return;
}
void dfs(vector<int> adj[],int root, int t)
{
   
   vis1[root]=true;
   cout<<root<<"\n";
   for(int i=0;i<adj[root].size();i++)
   {
      if(vis1[adj[root][i]]==false)
      {
         cout<<adj[root][i]<<"\n";
         vis1[adj[root][i]]=true;
         trav(adj,adj[root][i],root);
      }
      
   }
}
void bitrav(vector<int> adj[], int root,int parent, int coo)
{
   color[root]=coo;
   for(int i=0;i<adj[root].size();i++)
   {
      if(vis1[adj[root][i]]==false)
      {
         
         cout<<adj[root][i]<<"\n";
         vis1[adj[root][i]]=true;
         if(coo==-1){
            bitrav(adj,adj[root][i],root,1);
         }
         else{
            bitrav(adj,adj[root][i],root,0);
         }
      }
      else if(color[adj[root][i]] ==color[root])
      {
         cout<<"It is not a BIpartite graph\n";
      }
   }
   return;
}
void bipartite(vector<int> adj[],int root, int t)
{
   vis2[root]=true;
   color[root]=1;
   int coo=-1;
   for(int i=0;i<adj[root].size();i++)
   {
      if(vis1[adj[root][i]]==false)
      {
         
         vis1[adj[root][i]]=true;
         bitrav(adj,adj[root][i],root,coo);
      }
   }
}

bool isGoogles = 0;


/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
//   freopen('a.txt', 'r', stdin); freopen('a_out.txt', 'w', stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,n;
    cin>>t;
    vector<int> adj[t];
    cin>>n;
      f(i,0,n)
      {
         int a,b;
         cin>>a>>b;
         addedge(adj,a,b);
      }
      int root;
      cin>>root;
      //bfs(adj,root,t);
      //cout<<"\n\n\n";
      //dfs(adj,root,t);
      //cout<<"\n\n\n";
      bipartite(adj,root,t);

   return 0;
}