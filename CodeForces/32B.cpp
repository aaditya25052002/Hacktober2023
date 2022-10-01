#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define end '\n'
#define rep(i,a,b) for(int i=a;i<b;i++)
#define yes cout<<"YES"<<end
#define no cout<<"NO"<<end


void solve(){

    string s; cin >> s;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '.')
        {
            cout << 0;
        }
        else if (s[i] == '-')
        {
            int j = i+1;
            if (s[j] == '-')
            {
                cout << 2;
            }
            else cout << 1;
        i = j;
        }
    }
}



int main() {
cin.tie(0);
ios_base::sync_with_stdio(false);
// int tt; cin>>tt;
// while(tt--) 
    solve();
   
return 0;
}
