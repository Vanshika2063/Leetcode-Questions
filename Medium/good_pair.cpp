// Code By Romijul Laskar
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(void)
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;cin >> n;vector<ll> vec1(n), vec2(n);ll res = 0;
        for (ll &r : vec1){cin >> r;}
        for (ll &r : vec2){cin >> r;}
        map<pair<ll, ll>, ll> cyc;
        for (ll i = 0; i < n; i++){res += cyc[{vec1[i], vec2[i]}];cyc[{vec2[i], vec1[i]}]++;}
        cout << res << '\n';
    }
    return 0;
}
