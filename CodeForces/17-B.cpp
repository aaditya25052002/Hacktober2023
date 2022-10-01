 #include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
 
#define ll          long long
#define f           first
#define s           second
#define pp          pop_back
#define vll         vector<long long>
#define fr(i,a,n)   for (ll i=a;i<n;i++)
#define fr1(i,n)    for(ll i=1;i<=n;i++)
#define mpii        map<int, int>
#define umpii       unordered_map<int, int>
#define pii         pair<int,int>
#define pb          push_back
#define asort(a)    sort(a,a+n)
#define dsort(a)    sort(a,a+n,greater<int>())
#define vasort(v)   sort(v.begin(), v.end());
#define vdsort(v)   sort(v.begin(), v.end(),greater<int>());
#define umpll       unordered_map<ll,ll>
#define pl          pair<ll,ll>
#define MP          make_pair
#define df(x)       x.begin(),x.end()
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define as size()
 
typedef set <ll> sll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll , ll> > vpll;
 
ll BE(ll a,ll b){
   ll res = 1;
   while(b>0){
      if(b&1){
         res = (res * a * 1LL);
      }
      a = (1LL * a * a);
      b = b >> 1;
   }
   return res;
}
const int mod = 1e9 + 7;
void pro(){
 
   
   int n;
   cin >> n;
   int a[n];
   fr(i, 0, n) cin >> a[i];
   int x, y, i = 0;
   if(n<=2){
      yes;
      return;
   }
   int j = n - 1;
   while(1){
      if(a[i]!=a[j]){
         x = a[i];
         y = a[j];
         break;
      }
      else
         i++, j--;
         if(i>=j)
            break;
   }
   i = 0, j = n - 1;
   bool ok = 1;
   while(1){
      if(a[i]!=a[j]){
         if(a[i]==x)
            i++;
         else if(a[j]==x)
            j--;
         else{
            ok = 0;
            break;
         }
      }
      else
         i++, j--;
      if(i>=j)
         break;
   }
   if(ok){
      yes;
      return;
   }
   ok = 1;
   i = 0, j = n - 1;
   while (1){
      if(a[i]!=a[j]){
         if(a[i]==y)
            i++;
         else if(a[j]==y)
            j--;
         else {
            ok = 0;
            break;
         }
      }
      else
         i++, j--;
      if(i>=j)
         break;
   }
   if(ok)
      yes;
      else
         no;
}
 
    
    int main()
    { 
        
         ios::sync_with_stdio(0); 
         cin.tie(0);
 
 
         int t = 1;
         cin >> t;
         while (t--)
            pro();
      }     
