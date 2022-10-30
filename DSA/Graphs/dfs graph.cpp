#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

#define ll long long 
#define all(x) (x).begin(),(x).end()
#define vll vector<ll>
#define vl vector<ll>
#define pi pair<ll,ll>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rall(x) x.rbegin(), x.rend()
#define watch(x) cout << (#x) << ' is ' << (x) << endl
#define f(i,x,z) for(ll i=x;i<z;i++)
#define deb(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define clr(x) memset(x, 0, sizeof(x)) 
#define mll map<ll,ll>
#define mod 1000000007
//  for (auto &a : v)
//cin >> a;
//for (auto me : m) {
//std::vector<ll>::iterator it; 
//it = std::find (v.begin(), v.end(), ser);
//if (it != v.end())
vector< vector <int>> g;
vector<bool> v;
int pre=0,co=0,co1=0;
void addEdge(int a, int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}

  
void bfsvis(int u) 
{ 
    queue<int> q; 
  
    q.push(u); 
    v[u] = true; 
  
    while (!q.empty()) { 
  
        int f = q.front(); 
        q.pop(); 
  
        cout << f << " "; 
  
        // Enqueue all adjacent of f and mark them visited  
        for (auto i = g[f].begin(); i != g[f].end(); i++) { 
            if (!v[*i]) { 
                q.push(*i); 
                v[*i] = true; 
            } 
        } 
    } 
} 
void bfs(int n)
{
    for (int i = 0; i < n; i++) { 
        if (!v[i]){ 
            bfsvis(i);
            cout<<"\n";
        }
    } 
}

int main()
{
	int n, e;
	cin >> n >> e;

	v.assign(n, false);
	g.assign(n, vector<int>());

	int a, b;
	for(int i = 0; i < e; i++)
	{
		cin >> a >> b;
		addEdge(a, b);
	}
	bfs(n);
	
}