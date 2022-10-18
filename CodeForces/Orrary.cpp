 
#include<bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
 
#define ll     long long
#define ff     first
#define ss     second
#define pb     push_back
#define sz(x)  ((int)(x).size())
#define all(a) (a).begin(),(a).end()
 
void Solve() {
	int n;
	cin >> n;
 
	multiset<int> s;
 
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
 
	vector<int> ans;
 
	int o = 0, need = 0;
 
	for (int rep = 1; rep <= min(30, n); rep++) {
		int mx = 0;
		int need = 0;
 
		for (auto i : s) {
			if ((o | i) >= o) {
				if (mx <= (o | i)) {
					need = i;
					mx = o | i;
				}
			}
		}
 
		ans.pb(need);
		o |= need;
		s.erase(s.find(need));
	}
 
	for (auto i : s)
		ans.pb(i);
 
	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
 
 
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  int T = 1;
	cin >> T;
	while (T--) Solve();

}
