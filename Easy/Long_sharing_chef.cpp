// Code By Romijul Laskar
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fn <<endl;
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define debg(x) cout << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define F first
#define S second
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
#define a *max_element(v.begin(),v.end())
#define b *min_element(v.begin(),v.end())
#define fe(i) for(i=0; i!='\n'; i++)


void solve()
{
    string str;
    cin>>str;
    int GG=0;
    int RR=0;
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i]==str[i+1])
        {
            if(str[i]=='R'){RR++;}
            else{GG++;}
        }
    }
    if(str[str.size()-1]==str[0]){
        if(str[0]=='R'){RR++;}
        else{GG++;}
    }
    if((RR==GG)&&RR<=1&&GG<=1){cout<<"yes" fn}
    else{cout<<"no" fn}
    return;
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
