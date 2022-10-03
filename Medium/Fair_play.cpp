// Code By Romijul Laskar
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fn endl;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << endl
#define debg(x) cout << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define F first
#define S second
#define ass(x) sizeof(x) / sizeof(x[0])
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
#define max_l *max_element(v.begin(), v.end())
#define min_l *min_element(v.begin(), v.end())
#define fe(i) for (i = 0; i != '\n'; i++)


void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(max(a,b)>min(c,d) && max(c,d)>min(a,b)){
        deb(YES);
    }
    else{
        deb(NO);
    }
}
int main()
{
    fast;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
