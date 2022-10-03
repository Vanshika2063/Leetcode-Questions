// Code By- Romijul Laskar
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int oc = -1;
        string s;
        cin >> s;
        int z = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != 0)
            {
                oc++;
            }
        } //1352/A
        cout << oc << "\n";
        for (int i = 0; i < z; i++)
        {
            if (s[i] > 0)
            {
                cout << s[i];
                for (int j = i; j < oc; j++)
                {
                    cout << 0;
                }
                cout << " ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
