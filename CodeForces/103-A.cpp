#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// int mn(int array[]){

// }
int main()
{
    ios::sync_with_stdio(0); // Input and output clearance
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = INT_MIN, x, y;
    int min = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            x = i;
        }
        if (a[i] <= min)
        {
            min = a[i];
            y = i;
        }
    }

    if (y<x)
    {
        cout<<x+(n-1)-y-1<<endl;
    }
    else
    {
        cout<<x+(n-1)-y<<endl;
    }
        return 0;
}
