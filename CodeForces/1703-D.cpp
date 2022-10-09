#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define nl "\n"
#define Fast_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100002


vector<int> v(MAX);
void solve() {
	int n;
    cin >> n;
    string str[n];
    map<string, char> mp;
    for(int i = 0; i < n; i++) {
    	cin >> str[i];
    	mp[str[i]] = '0';
    }
    for(int i = 0; i < n; i++) {
    	char flag = '0';
    	for(int j = 0; j < str[i].size(); j++) {
    		string initial = str[i].substr(0, j);
    		// cout << initial << " ";
    		string end = str[i].substr(j, str[i].size()-j);
    		// cout << end << " ";
    		if(mp[initial] == '0' && mp[end] == '0') flag = '1';
    	}
    	cout << flag;
    }
    cout << nl;
}
 
signed main() {
    Fast_IO;
	int tt;
	cin >> tt;
	while(tt--) {
		solve();
	}
}
