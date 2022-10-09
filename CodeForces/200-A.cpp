#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void karma()
{
	int a, b, c = 2, r = 0;
	cin >> a;
	while (a--)
	{
		cin >> b;
		r += b != c;
		c = b;
	}
	cout << r;
}
int main()
{
	ios::sync_with_stdio(0); // Input and output clearance
	cin.tie(0);
	karma();
	return 0;
}
