#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main(){
ios::sync_with_stdio(0); 
cin.tie(0);
ll t;
cin>>t;
while (t--)
{
    ll n,k;
    cin>>n>>k;
    if((n == 1) && (k==1)){
        cout<<"1";
    }   
    else if( (k<2) || (k>n)){
        cout<<"-1";
    }
    else{
        for (ll i = 0; i < k-1 ; i++)
        {
            cout<<(i+1)<<" ";
        }
        for (ll i = 0; i < (n-k+1) ; i++)
        {
            cout<<(n-i)<<" ";
        }
    }
    cout<<endl;
}
    return 0;
}
