
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<"Max of three numbers is:"<<max(a,max(b,c));

    return 0;
}