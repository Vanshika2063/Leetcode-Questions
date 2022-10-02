// Code By- Romijul Laskar
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll x;
    int X;
    ll crime = 0;
    ll police = 0;
    vector<ll> c;
    cin >> x;
    while (x--)
    {
        cin >> X;
        c.push_back(X);
    }
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] >= 1)
        {
            police+=c[i];
        }
        else
        {
            if (police != 0)
            {
                police--;
            }
            else
            {
                crime++;
            }
        }
    }
    cout << crime;
    return 0;
}
