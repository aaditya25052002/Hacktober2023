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
//  it will calulate size of sub tree, levels and it works through dfs

vector<vector<ll>> adj;
int n;
vl level,subtreesize;
void dfs(ll par, ll cur)
{
	subtreesize[cur]=1;
	level[cur]=level[par]+1;
	cout<<cur<<" ";
	for(ll neh : adj[cur])
	{
		if(neh==par)
			continue;

		dfs(cur,neh);
		subtreesize[cur]+=subtreesize[neh];
	}
	
}
int main()
{
//   freopen('input.txt', 'r', stdin);
//   freopen('output.txt', 'w', stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin>>n;
	adj.resize(n+1);
	level.resize(n+1);
	level[0]=0;
	subtreesize.resize(n+1);
	f(i,0,n-1)
	{
		ll a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0,1);
	cout<<"\n";
	f(i,1,n+1)
	{
		cout<<level[i]<<" ";
	}
	cout<<"\n";
	f(i,1,n+1)
	{
		cout<<i<<" "<<subtreesize[i]<<"\n";
	}
   return 0;
}